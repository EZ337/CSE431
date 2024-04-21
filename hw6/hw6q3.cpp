#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

bool isValid(std::map<int, std::unordered_set<int>>& graph, std::vector<int>& path)
{
    std::unordered_set<int> visited;
    for (int i = 0; i < path.size(); i++)
    {
        int curr = path[i];
        int nextNode = path[(i + 1) % path.size()]; // Wrap around to the start to form a cycle

        // If we have already been to this vertex or there's no path to the next vertex, return 0
        if (graph[curr].count(nextNode) == 0 || visited.count(curr))
            return false;
        
        visited.insert(curr); // We have now visited this vertex
    }

    return true;
}


int main() {
    int N, M, vert, incidentVert;
    std::cin >> N >> M;
    std::map<int, std::unordered_set<int>> graph;

    // Build graph
    for (int i = 0; i < M; i++)
    {
        std::cin >> vert >> incidentVert;

        graph[vert].insert(incidentVert);
        graph[incidentVert].insert(vert);
    } // Finish data collection

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::vector<int> path;
        
        // Collect the path
        for (int j = 0; j < N; ++j)
        {
            std::cin >> vert;
            path.push_back(vert);
        }

        if (isValid(graph, path))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;

    }

    return 0;
}