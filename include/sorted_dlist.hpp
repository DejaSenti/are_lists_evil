#pragma once
#include <list>

#include "sorted_sequence.hpp"

class SortedDList : public ISortedSequence
{
public:
    SortedDList(const std::string& name) : ISortedSequence(name) {}

    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
private:
    std::list<int> m_dlist;
};
