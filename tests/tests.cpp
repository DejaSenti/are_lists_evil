#include <iostream>
#include <vector>
#include <algorithm>

#include "sorted_sequence.hpp"
#include "sorted_array.hpp"
#include "sorted_dlist.hpp"
#include "sorted_slist.hpp"
#include "sorted_tree.hpp"
#include "sorted_vector.hpp"

const int NUM_SEQUENCES = 5;
const int TEST_SIZE = 10;

const std::array<int, TEST_SIZE> test_nums = { 10, 5, 41, 90, 10, 745, 30, 6201, 6, 897 };
const std::array<std::vector<int>, 3> test_inds = 
{
    std::vector<int>{ 5 },
    std::vector<int>{ 1, 6, 3 },
    std::vector<int>{ 4, 0, 2, 2, 0, 0 }
};

static void printVector(std::string label, const std::vector<int>& vec)
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
    SortedArray<TEST_SIZE> arr("Array");
    SortedDList dlist("Doubly-Linked List");
    SortedSList slist("Singly-Linked List");
    SortedTree tree("Tree");
    SortedVector vec("Vector");

    ISortedSequence* sequences[NUM_SEQUENCES] = 
    {
        &arr,
        &dlist,
        &slist,
        &tree,
        &vec
    };

    std::vector<int> sorted_test_vec;
    sorted_test_vec.assign(test_nums.begin(), test_nums.end());
    std::sort(sorted_test_vec.begin(), sorted_test_vec.end());

    bool is_passed = true;

    for (auto sequence : sequences)
    {
        for (auto num : test_nums)
        {
            sequence->Insert(num);
        }

        if (!sequence->IsSorted())
        {
            std::cout << "Failed! " + sequence->GetName() + " is not sorted after insertion!" << std::endl;
            printVector("Expected", sorted_test_vec);
            printVector("Result", sequence->GetContents());
            is_passed = false;
        }
        
        std::vector<int> sorted_vec;
        sorted_vec.assign(sorted_test_vec.begin(), sorted_test_vec.end());

        for (auto test_remove : test_inds)
        {
            std::vector<int> before_rem = sequence->GetContents();
            
            for (auto num : test_remove)
            {
                sorted_vec.erase(sorted_vec.begin() + num);
                sequence->Remove(num);
            }

            std::vector<int> rem_result = sequence->GetContents();

            if (rem_result != sorted_vec)
            {
                std::cout << "Failed! " + sequence->GetName() + " doesn't have the correct contents after removal!" << std::endl;
                printVector("Before remove", before_rem);
                printVector("Indices to remove", test_remove);
                printVector("Expected", sorted_vec);
                printVector("Result", rem_result);
                is_passed = false;
            }
        }
    }

    if (is_passed)
    {
        std::cout << "Passed all tests!" << std::endl;
    }
}
