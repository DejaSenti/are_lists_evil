#pragma once
#include <set>

#include "sorted_sequence.hpp"

class SortedTree : public ISortedSequence
{
public:
    SortedTree(const std::string& name) : ISortedSequence(name) {}

    void Insert(int num) override;
    void Remove(int index) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
    
private:
    std::multiset<int> m_tree;
};
