#include <algorithm>

#include "sorted_dlist.hpp"

void SortedDList::Insert(std::vector<int> sequence)
{
    for (auto num : sequence)
    {
        auto const position = std::lower_bound(m_dlist.begin(), m_dlist.end(), num);
        m_dlist.insert(position, num);
    }
}

void SortedDList::Remove(std::vector<int> indices)
{
    for (auto num : indices)
    {
        m_dlist.erase(std::next(m_dlist.begin(), num));
    }
}

bool SortedDList::IsSorted(void) const
{
    return std::is_sorted(m_dlist.begin(), m_dlist.end());
}

std::vector<int> SortedDList::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_dlist.begin(), m_dlist.end());

    return result;
}