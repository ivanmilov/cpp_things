#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>

using LeafPtr = std::shared_ptr<struct Leaf>;

struct Leaf
{
    Leaf() {}
    Leaf(int i) : data{i} {}
    int data{};
    LeafPtr left{nullptr};
    LeafPtr right{nullptr};
};

LeafPtr get_tree()
{
    auto head = std::make_shared<Leaf>(1);
    head->left = std::make_shared<Leaf>(2);
    head->right = std::make_shared<Leaf>(3);

    head->left->left = std::make_shared<Leaf>(4);
    head->left->right = std::make_shared<Leaf>(5);

    return head;
}

LeafPtr get_bin_tree()
{
    auto head = std::make_shared<Leaf>(4);
    head->left = std::make_shared<Leaf>(2);
    head->right = std::make_shared<Leaf>(6);

    head->left->left = std::make_shared<Leaf>(1);
    head->left->right = std::make_shared<Leaf>(3);

    head->right->left = std::make_shared<Leaf>(5);
    head->right->right = std::make_shared<Leaf>(7);

    return head;
}

void print_X_order(LeafPtr tree)
{
    if (not tree)
        return;

    print_X_order(tree->left);
    std::cout << tree->data << " "; // move this line down to iterate [pre, in, post] order
    print_X_order(tree->right);
}

int get_height(LeafPtr tree)
{
    if (not tree)
        return 0;

    int left = get_height(tree->left);
    int right = get_height(tree->right);

    return std::max(left, right) + 1;
}

void print_level(LeafPtr tree, int level)
{
    if (not tree)
        return;

    if (level == 0)
        std::cout << tree->data << " ";
    else
    {
        print_level(tree->left, level - 1);
        print_level(tree->right, level - 1);
    }
}

void print_queue(LeafPtr tree)
{
    if (not tree)
        return;

    std::queue<LeafPtr> q;

    q.push(tree);

    while (not q.empty())
    {
        auto l = q.front();
        std::cout << l->data << " ";
        q.pop();

        if (l->left)
            q.push(l->left);

        if (l->right)
            q.push(l->right);
    }
}

constexpr void foo()
{
    int n{100};
    for (int a{0}; a < n; ++a)
        for (int b{0}; b < n; ++b)
            for (int c{0}; c < n; ++c)
                for (int d{0}; d < n; ++d)
                {
                    if (a * a * a + b * b * b == c * c * c + d * d * d)
                        std::cout << a << " " << b << " " << c << " " << d << std::endl;
                }
}

int main()
{
    auto tree = get_tree();

    std::cout << "height: " << get_height(tree) << std::endl;

    print_X_order(tree);
    std::cout << "" << std::endl;

    for (int i{0}; i < get_height(tree); ++i)
        print_level(tree, i);
    std::cout << "" << std::endl;

    print_queue(tree);
    std::cout << "" << std::endl;

    auto btree = get_bin_tree();
    print_X_order(btree);

    // foo();
    return 0;
}
