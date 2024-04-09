#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<iterator>
#include <queue>
#include <limits>
#include <fstream>

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
    friend bool operator==(const Edge& e1, const Edge& e2); 
    friend bool operator!=(const Edge& e1, const Edge& e2);
};

bool operator==(const Edge& e1, const Edge& e2) {return (e1.to == e2.to && e1.weight == e2.weight); }
bool operator !=(const Edge& e1, const Edge& e2) {return !(e1 == e2); };

// Graph class using adjacency list representation
// Base implemented by ChatGPT. Heavily modified for my needs
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

    // Visualises the graph
    void VisualiseGraph(std::string filename = "graph.gv")
    {
        std::ofstream fp;
        fp.open(filename);

        // Open line with 
        fp << "Graph{\n";
        
        // Colour keyVertices Red
        for (int keyVert : keyVertices)
        {
            fp << '\t' << keyVert << " [color=red, style=filled]\n";
        }

        fp << '\n';
        std::unordered_map<int, std::unordered_set<int>> alreadyMapped;

        for (auto elm : adjList)
        {
            // Input the vertex 
            fp << '\t' << elm.first << " -- {";

            // Connect the vertex
            for (auto edges : elm.second)
            {
                if (alreadyMapped[edges.to].find(elm.first) == alreadyMapped[edges.to].end())
                {
                    fp << edges.to << ' ';
                    alreadyMapped[elm.first].insert(edges.to); // Add to mapped
                }

            }
            fp << "}" << std::endl;
        }

        fp << '}' << std::endl;
        fp.close();
    }
    

};

int main() {
    std::cout << std::boolalpha;
    Graph graph;

    int N, M, K, vert, edg, weight = 0;
    std::cin >> N >> M >> K;

    // Collect and add all edges (Build the graph)
    for (int i = 0; i  < M; ++i)
    {
        std::cin >> vert >> edg;
        graph.addEdge(vert, edg);
    }

    // Collect and store the keyVertices
    for (int i = 0; i < K; ++i)
    {
        std::cin >> vert;
        graph.addKeyVertex(vert);
    }

    // Start BruteForceAlgo
    graph.VisualiseGraph();

    return 0;
}
