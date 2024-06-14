#pragma once
#include <list>

#include "sorted_sequence.hpp"

class SortedDList : public ISortedSequence
{
public:
    SortedDList(const std::string& name) : ISortedSequence(name) {}

    void Insert(int num) override;
    void Remove(int index) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
    
private:
    std::list<int> m_dlist;
};
