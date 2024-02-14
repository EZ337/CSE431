#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int N, dist;
    std::vector<int> distances;
    
    // Begin Data collection
    std::cin >> N;

    while (std::cin >> dist)
    {
        distances.push_back(dist);
    }

    // Begin logic
    // Sort to make it easy to process. This puts whole operaation at nlog(n)
    std::sort(distances.begin(), distances.end());

    int arrived = 0; // Amount that have arrived

    // With sorted list
    for (int i = 0; N - arrived; ) // Run until all have arrived
    {
        // Print arrived so far
        std::cout << (N-arrived) << std::endl;

        int val = distances[i]; // Current shortest distances
        int newArrivals = 0; // Used to increment i

        for (int j = i; j < N; ++j)
        {
            if (distances[j] <= val) // If the current distance is <= the current __shortest__ distance
            {
                ++arrived;
                ++newArrivals;
            }
            else
            {
                i = i + newArrivals; // Jump i to the next value that is not equal to the past value
                break;
            }

        }

    }
}