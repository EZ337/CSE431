#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

#include <fstream>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int vert, edge;
    std::map<int, std::set<int>> graph;
    for (int i = 0; i < M; i++)
    {
        std::cin >> vert >> edge;
        graph[vert].insert(edge);
        // Undirected graph is bidirectional
        graph[edge].insert(vert);
    }

    // First get the one with the most edges
    int mostEdges = 0;
    for (std::pair<int, std::set<int>> vertex : graph)
    {
        // +ourself to include ourself in our count
        //graph[vertex.first].insert(vertex.first);

        int edgeCount = vertex.second.size() + 1;
        if ( edgeCount > mostEdges)
        {
            mostEdges = edgeCount;
            // Store the index of the vertex with the most edges
            vert = vertex.first;
        }
    }

    std::ofstream fp;
    fp.open("test.gv");
    fp << "Graph{\n\t" << vert << " [color=red, style=filled]\n";

    // Then see if you can find a secondary connection that will add the most to your collection
    std::set<int> mostSet = graph[vert];
    for (int secondary : mostSet)
    {
        std::set<int> secondarySet = graph[secondary], outSet;

        // Output to file for visualising
        fp  << '\t' << secondary << " -- {";
        for (const auto& elm : secondarySet)
        {
            fp << elm;
            if (&elm != &(*(--secondarySet.end())))  
                fp << ','; // add comma if we are not at the end
        }
        fp << "}\n";
        // End visualisation

        // Copy the elements in secondary set that are not in 
        std::set_difference(secondarySet.begin(), secondarySet.end(), 
            mostSet.begin(), mostSet.end(), std::insert_iterator<std::set<int>>(outSet, outSet.begin()));
        
        // If we have extra connections to gain and the connections are more than our current
        // +2 because we need to include ourselves
        if (outSet.size() + mostSet.size()> mostEdges)
        {
            // Our uninion with this other vertex will net us a greater gain
            mostEdges = mostSet.size() + outSet.size();
        }
    }
    
    fp << '}';
    fp.close();
    std::cout << mostEdges * (mostEdges - 1)/2 << std::endl;
    
}