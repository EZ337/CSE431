#include <vector>
#include <iostream>
#include <utility>


int main()
{
    long value = 0, first, second, potential_index = 0, N;
    // Collect amount of values
    std::cin >> N;

    std::vector<std::pair<long, long>> vec;

    for (long i = 0; i < N; ++i)
    {
        std::cin >> first >> second;

        // Add it to potential vector
        vec.push_back(std::make_pair(first, second));

        if (value + first - second >= 0 && potential_index != -1)
        {
            value += first - second;
        }
        else if (potential_index == -1 && first  - second > 0)
        {
            potential_index = i;
            value = first - second;
        }
        else
        {
            potential_index = -1;
            value = 0;
        }
    }

    std::cout << potential_index << std::endl;
}