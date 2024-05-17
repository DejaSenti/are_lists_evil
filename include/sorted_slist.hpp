#pragma once
#include <forward_list>

#include "sorted_sequence.hpp"


class SortedSList : public ISortedSequence
{
public:
    SortedSList(const std::string& name) : ISortedSequence(name) {}

    void Insert(std::vector<int> sequence) override;
    void Remove(std::vector<int> indices) override;
    bool IsSorted(void)const override;
    std::vector<int> GetContents(void) const override;
private:
    std::forward_list<int> m_slist;
};
