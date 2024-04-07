#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

/// @brief Implementation by ChatGPT
struct Edge {
    int dest;
    int weight;
    Edge(int d, int w) : dest(d), weight(w) {}
};

/// @brief Implementation by ChatGPT
class Graph {
private:

public:
    int V; // Number of vertices

    vector<vector<Edge>> adjList; // Adjacency list


    // Constructor
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(Edge(dest, weight));
        adjList[dest].push_back(Edge(src, weight)); // Undirected graph
    }


    // Function to print the graph
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " :";
            for (const Edge& edge : adjList[i]) {
                cout << " -> " << edge.dest << " (weight: " << edge.weight << ")";
            }
            cout << endl;
        }
    }


};

/// @brief Use Prim's algorithm to get the MST of the graph and return the total edgeWeight required
/// @brief Got some corrections from ChatGPT as well MST algorithm was hard...
/// @param graph Graph to find minimum spanning tree of 
/// @return the total edgeWeight of the MST
int PrimsAlgorithm(const Graph& graph) {
    int V = graph.V;
    const vector<vector<Edge>>& adjList = graph.adjList;
    vector<int> parent(V, -1); // Array to store the parent of each vertex in the MST
    vector<int> key(V, numeric_limits<int>::max()); // Key values used to pick the minimum weight edge
    vector<bool> inMST(V, false); // Array to represent whether a vertex is in MST

    // Priority queue that stores vertices and their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        // Minimum key
        int u = pq.top().second;
        pq.pop(); // Remove minimum key

        inMST[u] = true; // Include vertex u in MST

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (const Edge& edge : adjList[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Calculate total weight of MST
    int totalWeight = 0;
    for (int i = 1; i < V; ++i) {
        totalWeight += key[i];
    }

    return totalWeight;
}



int main() 
{

    int N, M, weight, vert, incident;

    std::cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> vert >> incident >> weight;
        graph.addEdge(vert, incident, weight);
    }

    int totalWeight = PrimsAlgorithm(graph);
    std::cout << totalWeight << std::endl;


    return 0;
} 