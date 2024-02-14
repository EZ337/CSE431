#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

/// @brief Simple selection sort
/// @param vec Vector of ints to sort
/// @return Sorted version of the vector
std::vector<int> SelectionSort(std::vector<int> vec)
{
    int smallest_index;
    for (int i = 0; i < vec.size(); ++i)
    {
        smallest_index = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
           if (vec[j] < vec[smallest_index])
                smallest_index = j;
        }

        std::swap(vec[i], vec[smallest_index]);
    }

    return vec;
}

std::vector<int> MergeSort(std::vector<int> vec)
{

}

bool ASSERT_CONTENTS(const std::vector<int>& a, const std::vector<int>& b)
{
    return (a == b);
}

int main()
{
    std::vector<int> vec{13,53,65,6,3,54,6};
    auto sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());


    std::cout << std::boolalpha<< ASSERT_CONTENTS(sorted_vec, SelectionSort(vec)) << std::endl;
}








/* std::clock_t start_time = std::clock();
the_function_you_want_to_time();
std::clock_t tot_time = std::clock() - start_time;
std::cout << "Time: "
          << ((double) tot_time) / (double) CLOCKS_PER_SEC
          << " seconds" << std::endl;          */