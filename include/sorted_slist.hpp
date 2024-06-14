#pragma once
#include <forward_list>

#include "sorted_sequence.hpp"


class SortedSList : public ISortedSequence
{
public:
    SortedSList(const std::string& name) : ISortedSequence(name) {}

    void Insert(int num) override;
    void Remove(int index) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
    
private:
    std::forward_list<int> m_slist;
};
