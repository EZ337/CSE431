/**
 * Code analysis on proving the asymptotic difference between O(nlog(n)) vs O(n^2) on
 * large and small input values
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

/// @brief Simple selection sort
/// @param vec Vector of ints to sort
/// @return Sorted version of the vector
void SelectionSort(std::vector<long>& vec)
{
    int smallest_index;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        smallest_index = i;
        for (size_t j = i + 1; j < vec.size(); ++j)
        {
           if (vec[j] < vec[smallest_index])
                smallest_index = j;
        }

        std::swap(vec[i], vec[smallest_index]);
    }
}

// A function to merge two sorted subvectors
void Merge(std::vector<long>& vec, int left, int mid, int right) {
    // Create temporary vectors to store the subvectors
    std::vector<long> left_vec(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<long> right_vec(vec.begin() + mid + 1, vec.begin() + right + 1);

    // Initialize indices for the subvectors and the original vector
    int i = 0, j = 0, k = left;

    // Merge the subvectors in sorted order
    while (i < left_vec.size() && j < right_vec.size()) {
        if (left_vec[i] <= right_vec[j]) {
            vec[k] = left_vec[i];
            i++;
        }
        else {
            vec[k] = right_vec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subvector, if any
    while (i < left_vec.size()) {
        vec[k] = left_vec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subvector, if any
    while (j < right_vec.size()) {
        vec[k] = right_vec[j];
        j++;
        k++;
    }
}

/// @brief Merge sort implementation\
/// @brief Quick implementation with AI help as the implementation is not the focus.\
/// @brief Credits to Bing AI and https://stackoverflow.com/questions/44973765/how-to-efficiently-merge-sort-with-vectors-using-c
/// @param vec Vector to sort
/// @param left left  index of a
/// @return 
void MergeSort(std::vector<long>& vec, int left, int right) {
    // Base case: if the vector has one or zero elements, it is already sorted
    if (left >= right) {
        return;
    }

    // Recursive case: divide the vector into two halves and sort them separately
    int mid = left + (right - left) / 2; // To avoid overflow
    MergeSort(vec, left, mid);
    MergeSort(vec, mid + 1, right);

    // Merge the sorted halves
    Merge(vec, left, mid, right);
}

/// @brief Compares equality of values in a and b
/// @param a Vector a
/// @param b Vector b
/// @return True if all contents are equal in every index
bool ASSERT_CONTENTS(const std::vector<long>& a, const std::vector<long>& b)
{
    return (a == b);
}

/// @brief Generates a random vector. Inspired from: https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
/// @param N Amount of values to generate
/// @param min Minimum element possible
/// @param max Maximum element possible
/// @return Newly generated populated vector
std::vector<long> GenerateVector(size_t N, long min, long max)
{
    // Random setup
    std::random_device rd;
    std::mt19937_64 generator;
    std::uniform_int_distribution<long> dist(min, max);

    // Empty vector
    std::vector<long> vec;

    std::generate(vec.begin(), vec.end(), generator);

    // Populate vector
    for (size_t i = 0; i < N; i++)
    {
        vec.push_back(dist(generator));
    }
    

    return vec;
}


int main()
{
    int trials;
    size_t N;
    long min, max;

    std::cout << "Input how many runs" << std::endl;
    std::cin >> trials;

    for (int i = 0; i < trials; i++)
    {
        std::cout << "Input values: size min_value max_value" <<std::endl;
        std::cin >> N >> min >> max;


        std::vector<long> vec = GenerateVector(N, min, max), sorted, mergeSorted, selectionSorted;
        sorted = mergeSorted = selectionSorted = vec;

        // Sort the sorted version with standard C++ sort
        std::sort(sorted.begin(), sorted.end());

        std::cout << "\n\n" << std::endl;

        // Time Selection Sort
        std::clock_t start_time = std::clock();
        SelectionSort(selectionSorted); // Call selection sort
        std::clock_t tot_time = std::clock() - start_time;
        std::cout << "Selection Sort Time: "
                << ((double) tot_time) / (double) CLOCKS_PER_SEC
                << " seconds" << std::endl;

        // Time Merge Sort
        start_time = std::clock();
        MergeSort(mergeSorted, 0, mergeSorted.size() - 1); // Call MergeSort
        tot_time = std::clock() - start_time;
        std::cout << "Merge Sort Time: "
                << ((double) tot_time) / (double) CLOCKS_PER_SEC
                << " seconds" << std::endl;


        // Error checking
        if (!ASSERT_CONTENTS(sorted, selectionSorted))
        {
            std::cerr << "ERROR! Selection sort did not sort properly" << std::endl;
            return 1;
        }
        else if (!ASSERT_CONTENTS(sorted, mergeSorted))
        {
            std::cerr << "ERROR! Merge sort did not sort properly" << std::endl;
            return 1;
        }
    }
    
    
    // Collect info
}








/* std::clock_t start_time = std::clock();
the_function_you_want_to_time();
std::clock_t tot_time = std::clock() - start_time;
std::cout << "Time: "
          << ((double) tot_time) / (double) CLOCKS_PER_SEC
          << " seconds" << std::endl;          */