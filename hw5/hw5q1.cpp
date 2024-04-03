#include <iostream>
#include <map>
#include <set>

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

    int mostEdges = 0;
    for (std::pair<int, std::set<int>> vertex : graph)
    {
        // +1 to include ourselves in our edges
        int edgeCount = vertex.second.size() + 1;
        if ( edgeCount > mostEdges)
        {
            mostEdges = edgeCount;
        }
    }

    std::cout << mostEdges * (mostEdges - 1)/2 << std::endl;
    
}