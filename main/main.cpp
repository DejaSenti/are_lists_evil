#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <iostream>

#include "sorted_sequence.hpp"
#include "sorted_array.hpp"
#include "sorted_dlist.hpp"
#include "sorted_slist.hpp"
#include "sorted_tree.hpp"
#include "sorted_vector.hpp"

using namespace std;

class TimedSequence
{
public:
    TimedSequence(unique_ptr<ISortedSequence> seq) : m_Seq(move(seq)), m_timer_msec(0) {}

    TimedSequence(const TimedSequence&) = delete;
    TimedSequence& operator=(const TimedSequence&) = delete;

    TimedSequence(TimedSequence&&) = default;
    TimedSequence& operator=(TimedSequence&&) = default;

    void AddTimer(double nsec) { m_timer_msec += nsec; }
    double GetTimer(void) { return m_timer_msec; }

    unique_ptr<ISortedSequence> m_Seq;

private:
    double m_timer_msec;
};

int main(void)
{
    const int NUM_VARS = 100000000;
    const int EXP3 = 1000;

    TimedSequence ts1(make_unique<SortedArray<NUM_VARS>>("Array"));
    TimedSequence ts2(make_unique<SortedDList>("DList"));
    TimedSequence ts3(make_unique<SortedSList>("SList"));
    TimedSequence ts4(make_unique<SortedTree>("Tree"));
    TimedSequence ts5(make_unique<SortedVector>("Vector"));

    std::vector<TimedSequence> sequences;
    sequences.push_back(move(ts1));
    sequences.push_back(move(ts2));
    sequences.push_back(move(ts3));
    sequences.push_back(move(ts4));
    sequences.push_back(move(ts5));

    for (auto& seq : sequences)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(INT_MIN, INT_MAX);

        for (int i = 0; i < NUM_VARS; i++)
        {
            int num = distr(gen);

            auto start = std::chrono::high_resolution_clock::now();
            seq.m_Seq->Insert(num);
            auto end = std::chrono::high_resolution_clock::now();

            seq.AddTimer((chrono::duration<double>(end - start)).count());
        }
        


        double insertionElapsedSec = seq.GetTimer() * EXP3;
        std::cout << "Insertion into " << seq.m_Seq->GetName() << " took " << insertionElapsedSec << " seconds." << std::endl;

        for (int i = 0; i < NUM_VARS; i++)
        {
            std::uniform_int_distribution<> distr(0, NUM_VARS - i - 1);
            int index = distr(gen);
            
            auto start = std::chrono::high_resolution_clock::now();
            seq.m_Seq->Remove(index);
            auto end = std::chrono::high_resolution_clock::now();
            seq.AddTimer((chrono::duration<double>(end - start)).count());
        }

        double totalElapsedSec = seq.GetTimer() * EXP3;
        std::cout << "Removal from " << seq.m_Seq->GetName() << " took " << totalElapsedSec - insertionElapsedSec << " seconds." << std::endl;        
        std::cout << "Total time: " << totalElapsedSec << " seconds." << std::endl;
        std::cout << "===============================================================================" << std::endl;
    }
}