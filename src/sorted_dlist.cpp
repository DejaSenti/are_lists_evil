#include "sorted_dlist.hpp"

void SortedDList::Insert(std::vector<int> sequence)
{

}

void SortedDList::Remove(std::vector<int> indices)
{

}

bool SortedDList::IsSorted(void) const
{
    return false;
}

std::vector<int> SortedDList::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_dlist.begin(), m_dlist.end());

    return result;
}