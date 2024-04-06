#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <iterator>

void ExploreSet(int currentKey, std::map<int, std::set<int>>& graph, std::set<int>& explored)
{
    // Mark this vertex as explored
    explored.insert(currentKey);

    // Attack the edges of this vertex
    for (auto elm : graph[currentKey])
    {
        // If we haven't explored this vertex already,
        if (explored.find(elm) == explored.end())
            ExploreSet(elm, graph, explored);
    }
}


int main()
{
    int N, M;
    std::cin >> N >> M;

    std::map<int, std::set<int>> graph;

    int vert, edge;
    // Populate graph
    for (int i = 0; i < M; ++i)
    {
        std::cin >> vert >> edge;
        // vert : {vert1, vert2, vert3, ...}

        graph[vert].insert(edge);
        graph[edge].insert(vert); // Bidirectional
    }


    // Visualiser
    std::ofstream fp;
    fp.open("graph.gv");
    fp << "graph{\n";

    for (const auto& elm : graph)
    {
        fp << "\t" << elm.first << " -- {";

        // Output every edge
        for (const auto& inVert : elm.second)
        {
            fp << inVert;
            // Add comma if we are not the last element
            if (&inVert != &(*(--elm.second.end())))
                fp << ',';
        }
        fp << "}\n";
    }

    fp << "}";
    fp.close(); 
   

    std::set<int> explored;
    int trees = 0;
    for (auto elm : graph)
    {
        // If we haven't exploroed this section of the graph, explore it
        if (explored.find(elm.first) == explored.end())
        {
            ++trees;
            ExploreSet(elm.first, graph, explored);
        }
    }

    std::cout << trees << std::endl;

}



