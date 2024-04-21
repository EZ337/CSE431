#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using std::priority_queue; using std::vector; using std::set;

// Type def cause typing this out is a pain.
typedef std::pair<int, std::set<int>> PairSetInt;
// Sorts the pq in ascending order by pair.first
typedef std::priority_queue<PairSetInt, std::vector<PairSetInt>, std::greater<PairSetInt>> PairSetPQ;

class Graph
{
private:
    // Graph = {id : {0,1,2,3,..}, id1 : {5,8,1} }
    std::unordered_map<int, std::set<int>> graph;

    std::set<int> allSkills; // All the skills we need a set cover for

public:
    /// @brief Gets the skillset of person with ID id. Creates ID if it does not exist
    /// @param id id of the person to search for
    /// @return The corresponding skillset.
    std::set<int>& operator[](int id) {return graph[id]; }

    /// @brief Adds skillID to the universe of all skills
    /// @param skillID skill to add
    void AddToAllSkills(int skillID) {allSkills.insert(skillID); }

    /// @brief Finds the approx set Cover starting from startID
    /// @param startID The ID to start from to get the approximate best set cover
    /// @return A set of the included vertices for the set cover
    std::set<int> SetCover(int startID)
    {
        std::set<int> uncoveredSkills = allSkills, processedIDs; // Start with all skills being uncovered

        bool start = true;
        int candidateID = startID; // Start us off with the startID

        while (!uncoveredSkills.empty())
        {
            if (!start)
            {
                int bestSoFar = 0;
                for (auto& [id, skills] : graph)
                {
                    // If this person has already been processed or their ID is irrelvant, skip them
                    if (processedIDs.count(id))
                    {
                        continue;
                    }

                    std::set<int> result;
                    // Get the overlaps between the skills of this person and the uncoveredSkills
                    std::set_intersection(skills.begin(), skills.end(), uncoveredSkills.begin(), uncoveredSkills.end(),
                        std::insert_iterator(result, result.begin()));


                    // If the candidate has the best skills so far, we want them
                    if (result.size() > bestSoFar)
                    {
                        candidateID = id;
                        bestSoFar = result.size();
                    }
                }
            }

            std::set<int> result;

            // Get the left Over skills and put it into result
            std::set_difference(uncoveredSkills.begin(), uncoveredSkills.end(), graph[candidateID].begin(), graph[candidateID].end(),
                std::insert_iterator(result, result.begin()));

            uncoveredSkills.swap(result); // Constant time operation
            processedIDs.insert(candidateID); // Add to the list of people we are using to solve this problem
            start = false;
        }
        
        return processedIDs;

    }


    /// @brief Brutesforces its way by calling SetCover to start at all the ids avaialable
    /// in the graph.
    /// @return The best pair representing the amount of people required and a set of the people required
    std::pair<int, std::set<int>> BruteForceSetCover(int maxRuns = 1000)
    {
        PairSetPQ pq;

        // Accumalte the possibilities of all the set covers available from each starting id
        // Mechanisms are in place to stop early though.
        for (auto [id, skillset] : graph)
        {
            if (pq.size() > maxRuns - 1)
                break;

            std::set<int> setCover = SetCover(id);
            pq.push(std::make_pair(setCover.size(), setCover));
        }

        // auto x = pq.top();
        // std::cout << "pq Top is: " << x.first << " : {" ;
        // for (auto elm : x.second)
        // {
        //     std::cout << elm << ", ";
        // }
        // std::cout << '}' << std::endl;

        return pq.top();
    }
    
};


int main()
{
    // Collect Data
    int N, K;
    std::cin >> N >> K;
    
    // Build graph
    Graph graph;
    int skillcount, skillID;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> skillcount;

        // Populate skills of this member
        for (int j = 0; j < skillcount; ++j)
        {
            std::cin >> skillID;
            graph[i].insert(skillID); // Add the skill to this member
            graph.AddToAllSkills(skillID); // Duplicates are ignored
        }
    }
    
    // Grab the approximate best cover within the time limit
    PairSetInt result =  graph.BruteForceSetCover(6);

    std:: cout << result.first << std::endl;
    for (auto person : result.second)
    {
        std::cout << person << ' ';
    }
}

