#pragma once
#include <set>

#include "sorted_sequence.hpp"

class SortedTree : public ISortedSequence
{
public:
    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
private:
    std::set<int> m_tree;
};
