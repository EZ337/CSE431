#include <iostream>
#include <vector>
#include <algorithm>

using std::endl; using std::cout;

int main()
{
    int T, rubies, sapphire, N;
    std::cin >> T;


    for(int i = 0; i < T ; ++i)
    {
        std::cin >> rubies >> sapphire >> N;
        
        // Used to sort and output. Not ideal because I didn't want to weigh which
        // is small and which is big
        std::vector<int> totals;
        
        // Case where we collect all of one and none of the other
        totals.push_back(rubies * N);

        // Calculate in between values
        if (rubies != sapphire)
        {
            for (int j = 1; j < N; ++j)
            {
                totals.push_back( (rubies * j) + (sapphire * (N-j)) );
            }

            totals.push_back(sapphire * N);
        }

        std::sort(totals.begin(), totals.end());

        for (auto itr = totals.begin(); itr != totals.end(); ++itr)
        {
            std::cout << *itr;

            if (itr != totals.end() - 1)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}