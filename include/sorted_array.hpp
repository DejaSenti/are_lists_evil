#pragma once

#include <array>
#include <algorithm>

#include "sorted_sequence.hpp"

template<std::size_t N>
class SortedArray : public ISortedSequence
{
public:
    SortedArray(const std::string& name) : ISortedSequence(name), m_size(0) {}

    void Insert(int num) override;
    void Remove(int index) override;
    bool IsSorted(void) const override;
    std::vector<int> GetContents(void) const override;

private:
    std::array<int, N> m_arr;
    int m_size;
};

template<std::size_t N>
void 
SortedArray<N>::Insert(int num)
{
    m_arr[m_size] = num;

    int i = m_size;

    while (i > 0 && m_arr[i] < m_arr[i - 1])
    {
        std::swap(m_arr[i], m_arr[i - 1]);
        i--;
    }

    m_size++;
}

template<std::size_t N>
void 
SortedArray<N>::Remove(int index)
{
    for (int i = index; i < m_size - 1; i++)
    {
        std::swap(m_arr[i], m_arr[i + 1]);
    }

    m_size--;
}

template<std::size_t N>
bool 
SortedArray<N>::IsSorted(void) const
{
    return std::is_sorted(m_arr.begin(), m_arr.end());
}

template<std::size_t N>
std::vector<int> 
SortedArray<N>::GetContents(void) const
{
    std::vector<int> result;
    result.assign(m_arr.begin(), m_arr.begin() + m_size);

    return result;
}
