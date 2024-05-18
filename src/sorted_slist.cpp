#include <algorithm>

#include "sorted_slist.hpp"

void SortedSList::Insert(std::vector<int> sequence)
{
    for (auto num : sequence)
    {        
        auto prev = m_slist.before_begin();
        auto curr = m_slist.begin();

        while (curr != m_slist.end() && *curr < num) 
        {
            prev = curr;
            ++curr;
        }

        m_slist.insert_after(prev, num);
    }
}

void SortedSList::Remove(std::vector<int> indices)
{
    for (auto num : indices)
    {
        m_slist.erase_after(std::next(m_slist.before_begin(), num));
    }
}

bool SortedSList::IsSorted(void) const
{
    if (m_slist.empty())
    {
        return true;
    }

    auto iter = m_slist.begin();

    while (std::next(iter) != m_slist.end())
    {
        if (*std::next(iter) < *iter)
        {
            return false;
        }

        iter++;
    }

    return true;
}

std::vector<int> SortedSList::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_slist.begin(), m_slist.end());

    return result;
}