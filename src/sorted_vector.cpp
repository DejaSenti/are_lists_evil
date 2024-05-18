#include <algorithm>

#include "sorted_vector.hpp"

void SortedVector::Insert(std::vector<int> sequence)
{
    for (auto num : sequence)
    {
        auto const position = std::lower_bound(m_vec.begin(), m_vec.end(), num);
        m_vec.insert(position, num);
    }
}

void SortedVector::Remove(std::vector<int> indices)
{
    for (auto num : indices)
    {
        m_vec.erase(m_vec.begin() + num);
    }
}

bool SortedVector::IsSorted(void) const
{
    return std::is_sorted(m_vec.begin(), m_vec.end());
}

std::vector<int> SortedVector::GetContents(void) const
{
    return m_vec;
}