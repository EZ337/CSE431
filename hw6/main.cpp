#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{
    const int MAX_TIME = 4;

    int N, K, skillCount, skillID;
    std::vector<std::unordered_set<int>> people;
    std::vector<int> included_People(N);

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

        // Start off with everyone in the set
        included_People.push_back(i);

    } // Data collection end

    // Start time
    auto start_time = time(nullptr);

    // Initialise the complete set
    std::unordered_set<int> final_Set;
    std::vector<int> final_people(N); // Up to N people will be included

    // Start greedy algorithm. Only run for MAX_TIME before quitting and outputting
    // This is the base. Now it needs optimisation

    for (int i = 0; i < N; ++i)
    {
        auto x = (time(nullptr) - start_time);
        std::cout << "Time is: " << x << std::endl;


        if (time(nullptr) - start_time < MAX_TIME)
        {
            // Compute the number of uncovered elements by this person's set
            std::unordered_set<int> tempSet;
            std::set_union(people[i].begin(), people[i].end(), final_Set.begin(), final_Set.end(),
                std::inserter(tempSet, tempSet.begin()));

            // If this person's set covers more elements than the current maximum, update
            if (tempSet.size() > final_Set.size())
            {
                std::swap(final_Set, tempSet); // Do it in constant time
                final_people.push_back(i);
            }
        }
        else if (final_Set.size() == K) // If we run out of time AND we got all of our elements,
        {

            std::swap(included_People, final_people);
            break;
        }
        

    }




    // Final output
    std::cout << included_People.size() << std::endl;
    for (auto elm : included_People)
    {
        std::cout << elm << ' ';
    }
    std::cout << std::endl;
}