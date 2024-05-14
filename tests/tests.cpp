#include <iostream>
#include <vector>
#include <algorithm>

#include "sorted_sequence.hpp"
#include "sorted_array.hpp"
#include "sorted_dlist.hpp"
#include "sorted_slist.hpp"
#include "sorted_tree.hpp"
#include "sorted_vector.hpp"

const int TEST_SIZE = 10;
const std::array<int, TEST_SIZE> test_nums = { 10, 5, 41, 90, 10, 745, 30, 6201, 6, 897 };
const std::array<std::vector<int>, 3> test_inds = 
{
    std::vector<int>{ 5 },
    std::vector<int>{ 1, 6, 3 },
    std::vector<int>{ 4, 0, 2, 2, 0, 0 }
};

typedef struct sequence
{
    ISortedSequence* sequence;
    std::string name;
} sequence_t;

static void printVector(std::string label, std::vector<int>& vec)
{
    std::cout << label + ":" << std::endl;

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];

        if (i < vec.size() - 1) [[likely]]
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

int main(void)
{
    SortedArray<TEST_SIZE> arr;
    SortedDList dlist;
    SortedSList slist;
    SortedTree tree;
    SortedVector vec;

    std::vector<sequence_t> sequences = 
    { 
        { &arr, "Array" },
        { &dlist, "Doubly-Linked List" },
        { &slist, "Singly-Linked List" },
        { &tree, "Tree" },
        { &vec, "Vector" }
    };

    std::vector<int> test_vec;
    test_vec.assign(test_nums.begin(), test_nums.end());
    std::vector<int> sorted_test_vec = test_vec;
    std::sort(sorted_test_vec.begin(), sorted_test_vec.end());

    bool is_passed = true;

    for (auto sequence : sequences)
    {
        sequence.sequence->Insert(test_vec);
        if (!sequence.sequence->IsSorted())
        {
            std::cout << "Failed! " + sequence.name + " is not sorted after insertion!" << std::endl;
            printVector("Expected", sorted_test_vec);
            printVector("Result", sequence.sequence->GetContents());
            is_passed = false;
        }
    }

    for (auto test_remove : test_inds)
    {
        for (auto num : test_remove)
        {
            sorted_test_vec.erase(sorted_test_vec.begin() + num);
        }
        
        for (auto sequence : sequences)
        {
            sequence.sequence->Remove(test_remove);
            std::vector<int> rem_result = sequence.sequence->GetContents();

            if (rem_result != test_vec)
            {
                std::cout << "Failed! " + sequence.name + " doesn't have the correct contents after removal!" << std::endl;
                printVector("Expected", sorted_test_vec);
                printVector("Result", sequence.sequence->GetContents());
                is_passed = false;
            }
        }
    }

    if (is_passed)
    {
        std::cout << "Passed all tests!" << std::endl;
    }
}
