#include "sorted_tree.hpp"

void SortedTree::Insert(std::vector<int> sequence)
{

}

void SortedTree::Remove(std::vector<int> indices)
{

}

bool SortedTree::IsSorted(void) const
{
    return false;
}

std::vector<int> SortedTree::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_tree.begin(), m_tree.end());

    return result;
}