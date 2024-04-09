#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<iterator>
#include <queue>
#include <limits>

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Graph class using adjacency list representation
class Graph 
{
private:
    std::unordered_map<int, std::vector<Edge>> adjList;
    std::unordered_set<int> keyVertices;

public:
    // Add an edge to the graph
    void addEdge(int from, int to, int weight = 0) 
    {
        adjList[from].push_back(Edge(to, weight));
        adjList[to].push_back(Edge(from, weight)); // Undirected graph
    }

    // Add a key vertex
    void addKeyVertex(int vertex) {
        keyVertices.insert(vertex);
    }

    // Check if a vertex is a key vertex
    bool isKeyVertex(int vertex) {
        return keyVertices.find(vertex) != keyVertices.end();
    }

    // Begin function for range based loop
    std::unordered_map<int, std::vector<Edge>>::iterator begin() { return adjList.begin(); }

    // End function for range based loop
    std::unordered_map<int, std::vector<Edge>>::iterator end() {return adjList.end();}

    // const reference to the keyVertices of this graph
    const std::unordered_set<int>& GetKeyVertices() {return keyVertices;}

    // Dijkstra's algorithm to find the shortest path from a source to all vertices
    std::unordered_map<int, int> dijkstra(int source) {
        std::unordered_map<int, int> distances;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (auto& pair : adjList) {
            int v = pair.first;
            distances[v] = std::numeric_limits<int>::max();
        }

        distances[source] = 0;
        pq.push(std::make_pair(0, source));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push(std::make_pair(distances[v], v));
                }
            }
        }

        return distances;
    }
};

int main() {
    std::cout << std::boolalpha;
    Graph g;

    int N, M, K, vert, edg, weight = 0;
    std::cin >> N >> M >> K;

    // Collect and add all edges (Build the graph)
    for (int i = 0; i  < M; ++i)
    {
        std::cin >> vert >> edg;
        g.addEdge(vert, edg);
    }

    // Collect and store the keyVertices
    for (int i = 0; i < K; ++i)
    {
        std::cin >> vert;
        g.addKeyVertex(vert);
    }

    // Start BruteForceAlgo

    return 0;
}
