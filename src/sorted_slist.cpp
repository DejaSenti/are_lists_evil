#include "sorted_slist.hpp"

void SortedSList::Insert(std::vector<int> sequence)
{

}

void SortedSList::Remove(std::vector<int> indices)
{

}

bool SortedSList::IsSorted(void) const
{
    return false;
}

std::vector<int> SortedSList::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_slist.begin(), m_slist.end());

    return result;
}