#include "list.h"
#include <algorithm>
#include <queue>

// assume no length known
SNodePtr get_k_from_back(SNodePtr node, size_t k)
{
    SNodePtr pointer = node;
    SNodePtr result = nullptr;

    size_t counter{};

    while (pointer)
    {
        counter++;
        pointer = pointer->next;

        if (counter == k)
            result = node;

        if (counter > k)
            result = result->next;
    }
    return result;
}

SNodePtr get_k_from_back1(SNodePtr node, size_t k)
{
    SNodePtr pointer = node;
    SNodePtr result = node;

    for (size_t i{0}; i < k; ++i)
    {
        if (not pointer)
            return nullptr;
        pointer = pointer->next;
    }

    while (pointer)
    {
        pointer = pointer->next;
        result = result->next;
    }
    return result;
}

void k_from_back(SNodePtr node, size_t k)
{
    auto k_el = get_k_from_back(node, k);

    if (k_el)
        std::cout << "[" << k << "] elem: " << k_el->data << std::endl;
    else
        std::cerr << "[" << k << "] is to big!" << std::endl;
}

void k_from_back1(SNodePtr node, size_t k)
{
    auto k_el = get_k_from_back1(node, k);

    if (k_el)
        std::cout << "[" << k << "] elem: " << k_el->data << std::endl;
    else
        std::cerr << "[" << k << "] is to big!" << std::endl;
}

/**
 * Два числа хранятся в виде связных списков, в которых каждый узел пред­
 * ставляет один разряд. Все цифры хранятся в обратном порядке, при этом
 * младший разряд (единицы) хранится в начале списка. Напишите функцию,
 * которая суммирует два числа и возвращает результат в виде связного списка.

 * Пример:
 * Ввод: (7->1->6) + (5->9->2), то есть 617 + 295.
 * Вывод: 2->1->9, то есть 912.
 * Дополнителыю
 * Решите задачу, предполагая, что цифры записаны в прямом порядке.
 * Ввод: (6->1->7) + (2->9->5), то есть 617 + 295.
 * Вывод: 9->1->2, то есть 912.
 * Подсказки:
 *  7, 30, 71, 95, 109
 */
void sum_reverse(SNodePtr, SNodePtr)
{
    auto result = std::make_shared<SNode>();
}

int main()
{
    auto l = get_s_list();

    print_list(l);

    std::cout << "len: " << get_len(l) << std::endl;

    const size_t K{3};
    k_from_back(l, K);
    k_from_back1(l, K);

    return 0;
}
