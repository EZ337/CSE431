#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

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
    

    std::cout << "Hello World!" << std::endl;
}

