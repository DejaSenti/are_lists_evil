#include <algorithm>

#include "sorted_tree.hpp"

void SortedTree::Insert(int num)
{
    m_tree.insert(num);
}

void SortedTree::Remove(int index)
{
    auto iter = m_tree.begin();
    std::advance(iter, index);

    m_tree.erase(iter);
}

bool SortedTree::IsSorted(void) const
{
    return std::is_sorted(m_tree.begin(), m_tree.end());
}

std::vector<int> SortedTree::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_tree.begin(), m_tree.end());

    return result;
}