#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

int main()
{



    uint N;
    std::cin >> N;
    std::map<long, long, std::greater<long>> nums;

    long number;
    long count = 0;

    for (long i = 0; i < N; ++i)
    {
        std::cin >> number;
        ++(nums[number]);
    }

    //std::cout << (*(nums.begin())).first << std::endl;

    number = (*(nums.begin())).first;
    count = (*(nums.begin())).second;

    for (auto pair : nums)
    {
        if (pair.second >= count && pair.first < number)
        {
            count = pair.second;
            number = pair.first;
        }
    }

    std::cout << number << std::endl;
}