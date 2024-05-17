#pragma once

#include <array>
#include <algorithm>

#include "sorted_sequence.hpp"

template<std::size_t N>
class SortedArray : public ISortedSequence
{
public:
    SortedArray(const std::string& name) : ISortedSequence(name) {}

    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void) const override;
    std::vector<int> GetContents(void) const override;
private:
    std::array<int, N> m_arr;
    int m_size;
};

template<std::size_t N>
void sorted_insert(std::array<int, N>& arr, int num, int current_size)
{
    arr[current_size] = num;

    int i = current_size;

    while (i > 0 && arr[i] < arr[i - 1])
    {
        std::swap(arr[i], arr[i - 1]);
        i--;
    }
}

template<std::size_t N>
void remove_from_array(std::array<int, N>& arr, int ind)
{
    for (int i = ind; i < arr.size() - 1; i++)
    {
        std::swap(arr[i], arr[i + 1]);
    }
}

template<std::size_t N>
void 
SortedArray<N>::Insert(std::vector<int> sequence)
{
    m_size = 0;
    for (int i = 0;  i < m_arr.size(); i++)
    {
        sorted_insert(m_arr, sequence[i], i);
        m_size++;
    }
}

template<std::size_t N>
void 
SortedArray<N>::Remove(std::vector<int> indices)
{
    for(auto ind : indices)
    {
        remove_from_array(m_arr, ind);
        m_size--;
    }
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
