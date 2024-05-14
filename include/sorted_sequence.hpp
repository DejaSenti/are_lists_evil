#pragma once

#include <vector>

class ISortedSequence
{
public:
    virtual ~ISortedSequence(void) = default;

    virtual void Insert(std::vector<int> sequence) = 0;
    virtual void Remove(std::vector<int> indices) = 0;
    virtual bool IsSorted(void) const = 0;
    virtual std::vector<int> GetContents(void) const = 0;
};
