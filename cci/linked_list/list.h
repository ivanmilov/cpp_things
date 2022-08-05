#pragma once

#include <iostream>
#include <memory>

using SNodePtr = std::shared_ptr<struct SNode>;
using DNodePtr = std::shared_ptr<struct DNode>;

struct SNode
{
    SNode() {}
    SNode(int i) : data{i} {}
    int data{};
    SNodePtr next{nullptr};
};

struct DNode
{
    DNode() {}
    DNode(int i) : data{i} {}
    int data{};
    DNodePtr next{nullptr};
    DNodePtr prev{nullptr};
};

inline SNodePtr get_tail(SNodePtr head)
{
    if (not head)
        return head;

    while (head->next)
    {
        head = head->next;
    }
    return head;
}

inline SNodePtr push_front(SNodePtr head, int d)
{
    auto new_head = std::make_shared<SNode>(d);

    new_head->next = head;

    return new_head;
}

inline SNodePtr push_back(SNodePtr head, int d)
{
    auto tail = get_tail(head);

    tail->next = std::make_shared<SNode>(d);

    return tail->next;
}

inline SNodePtr get_s_list()
{
    auto head = std::make_shared<SNode>(0);
    auto node = head;
    for (int i{1}; i < 10; ++i)
    {
        node->next = std::make_shared<SNode>(i);
        node = node->next;
    }
    return head;
}

template <class NodePtr>
inline void print_list(NodePtr node)
{
    while (node)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <class NodePtr>
inline size_t get_len(NodePtr node)
{
    size_t len{};
    while (node)
    {
        len++;
        node = node->next;
    }

    return len;
}
