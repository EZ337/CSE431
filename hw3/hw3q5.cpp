#include <iostream>

int CountOnes(uint64_t val)
{
    int count = 0;
    while (val)
    {
        val &= val - 1;
        ++count;
    }

    return count;
    
}


int main()
{
    int N;
    uint64_t curr, goal;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> curr >> goal;

        uint64_t diff = curr - goal;

        std::cout << CountOnes(diff) << std::endl;

    }
}