#include <atomic>
#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <thread>
#include <vector>

template <class T>
class ConcurrentStack
{
    struct Node;
    using NodePtr = std::shared_ptr<Node>;
    struct Node
    {
        T t;
        NodePtr next;
    };
    NodePtr head{nullptr};
    ConcurrentStack(ConcurrentStack&) = delete;
    void operator=(ConcurrentStack&) = delete;
    std::atomic<size_t> count{0};

  public:
    ConcurrentStack() = default;
    ~ConcurrentStack() = default;

    ConcurrentStack(ConcurrentStack&&) noexcept = default;
    ConcurrentStack& operator=(ConcurrentStack&& other) noexcept = default;

    class Reference
    {
        NodePtr p;

      public:
        Reference(NodePtr p) : p{p} {}
        T& operator*() { return p->t; }
        T* operator->() { return &p->t; }
        explicit operator bool() const { return p.operator bool(); }
    };

    auto find(T t)
    {
        auto p = std::atomic_load(&head);
        while (p and p->t != t)
            p = p->next;

        return Reference(std::move(p));
    }

    auto front() const { return Reference(std::atomic_load(&head)); }
    const auto cfront() const { return Reference(std::atomic_load(&head)); }
    void push_front(T t)
    {
        auto p = std::make_shared<Node>();
        p->t = t;
        p->next = std::atomic_load(&head);
        while (not std::atomic_compare_exchange_weak(&head, &p->next, p))
            ;
        count++;
    }
    void pop_front()
    {
        auto p = std::atomic_load(&head);
        while (p and not atomic_compare_exchange_weak(&head, &p, p->next))
            ;
        count--;
    }

    size_t size() const { return count; }
    bool empty() const { return not front().operator bool(); }
};

void pusher(ConcurrentStack<int>& s, int index)
{
    constexpr auto amount{10000};
    const auto base{amount * index};
    for (int i{base}; i < base + amount; ++i)
    {
        s.push_front(i);
    }
}

int main()
{
    ConcurrentStack<int> s;

    std::vector<std::thread> threads;
    for (int i{0}; i < 10; ++i)
    {
        threads.emplace_back(pusher, std::ref(s), i);
    }

    for (auto& t : threads)
        t.join();

    std::cout << "Size: " << s.size() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (not s.empty())
    {
        s.pop_front();
    }
    std::cout << "Size: " << s.size() << std::endl;

    return 0;
}
