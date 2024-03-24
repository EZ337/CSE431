#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    // n = fights, m = amount of armour
    int n, m;
    std::cin >> n >> m;

    // Collect the base cost of every armour piece
    std::vector<int> armorBaseCost;
    int baseCost;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> baseCost;
        armorBaseCost.push_back(baseCost);
    }

    // Sort the data in reverse order
    std::sort(armorBaseCost.begin(), armorBaseCost.end(), std::greater<int>());

    // Loop through and assigning them in order of decreasing magnitude
    int multiplier = 1, total = 0, loc = 0;
    for (int i = 0; i < n; ++i)
    {
        // Total is equal to the mult * 
        total += armorBaseCost[i] * multiplier;
        //total *= (loc%(m+1));

        if (++loc == m)
        {
            loc = 0;
            ++multiplier;
        }
         
    }


    std::cout << total << std::endl;
    return 0;
}