#pragma once

#include <array>

#include "sorted_sequence.hpp"

template<std::size_t N>
class SortedArray : public ISortedSequence
{
public:
    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void) const override;
    std::vector<int> GetContents(void) const override;
private:
    std::array<int, N> m_arr;
    int m_size;
};
