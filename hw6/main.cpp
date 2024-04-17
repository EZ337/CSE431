#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{
    auto start_time = time(nullptr);
    const int MAX_TIME = 4;

    int N, K, skillCount, skillID;
    std::vector<std::unordered_set<int>> people;

    std::cin >> N >> K;

    // Collect each skill for each person
    for (int i = 0; i < N; ++i)
    {
        std::cin >> skillCount;
        people.push_back(std::unordered_set<int>(skillCount));

        // Add each skill to person[i]
        for (int j = 0; j < skillCount; ++j)
        {
            std::cin >> skillID;
            people[i].insert(skillID);
        }
    } // Data collection end

    // Initialise the complete set
    std::unordered_set<int> final_Set;
    std::vector<int> included_People;

    // Start greedy algorithm. Only run for MAX_TIME before quitting and outputting
    do
    {
        for (auto &elm : people)
        {
            std::unordered_set<int> tempSet;
            std::set_union(elm.begin(), elm.end(), final_Set.begin(), final_Set.end(),
                std::insert_iterator<std::unordered_set<int>>(tempSet, tempSet.begin()));

            // We gained stuff
            if (tempSet.size() > final_Set.size())
            {
                if ()
            }
        }
        
    } while (time(nullptr) - start_time < MAX_TIME);



    // Final output
    std::cout << included_People.size() << std::endl;
    for (auto elm : included_People)
    {
        std::cout << elm << ' ';
    }
    std::cout << std::endl;
}