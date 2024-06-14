#pragma once

#include <vector>
#include <string>

class ISortedSequence
{
public:
    ISortedSequence(const std::string& name) : m_name(name) {}
    virtual ~ISortedSequence(void) = default;

    virtual void Insert(int num) = 0;
    virtual void Remove(int index) = 0;
    virtual bool IsSorted(void) const = 0;
    virtual std::vector<int> GetContents(void) const = 0;
    const std::string& GetName(void) const { return m_name; }
    
private:
    std::string m_name;
};
