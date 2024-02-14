#include <iostream>
#include <math.h>


int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int min, max, div12 = 0, perf_square = 0, overlap = 0;
        std::cin >> min >> max;
        
        // int x = (int)ceil(max/12.0), y = (int)ceil(min/12.0);
        div12 = floor(max/12.0) - ceil(min/12.0) + 1;

        //max = (sqrt(max) > min) ? sqrt(max) : max;

        for (int j = ceil(sqrt(min)); j <= floor(sqrt(max)); j++)
        {
            int square = j * j; // calculate the square of i
            if (square >= min && square <= max) // check if the square is within the range
            {
                ++perf_square;

                if (square%12 == 0)
                {
                    ++overlap;
                }
            }
        }

        std::cout << div12 << ' ' << perf_square << ' ' << overlap << std::endl;

    }
}