#pragma once

#include <vector>

#include "sorted_sequence.hpp"

class SortedVector : public ISortedSequence
{
public:
    SortedVector(const std::string& name) : ISortedSequence(name) {}

    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
private:
    std::vector<int> m_vec;
};
