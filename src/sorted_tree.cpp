#include <algorithm>

#include "sorted_tree.hpp"

void SortedTree::Insert(std::vector<int> sequence)
{
    for (auto num : sequence)
    {
        m_tree.insert(num);
    }
}

// careful, Icarus, especially when using huge vectors here
void SortedTree::Remove(std::vector<int> indices)
{
    if (indices.size() == 0)
    {
        return;
    }
    
    auto iter = m_tree.begin();
    std::advance(iter, indices[0]);

    m_tree.erase(iter);

    indices.erase(indices.begin());

    Remove(indices);
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