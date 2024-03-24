#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    // n = number of things, m = amount of enemies at this loc
    long n, m;
    std::cin >> n;

    // prev = the non adjacent number to me. 
    long prev2 = 0, total = 0;

    for (long i = 0; i < n; ++i)
    {
        std::cin >> m;

        if (i == 0)
            total = m;
        
        else
        {
            // Update total if our current number plus the non adjacent number is greater than the total
            if (m+prev2 > total)
            {
                long temp = m+prev2;
                prev2 = total;
                total = temp;
            }
            
            else
                prev2 = total;
        }

    }

    std::cout << total << std::endl;

}