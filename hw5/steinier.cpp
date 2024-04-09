
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <climits>

using namespace std;

class Graph {
public:
    int vertices;
    vector<unordered_set<int> > adj; // Using unordered_set for efficient lookup and deletion

    Graph(int v) : vertices(v), adj(v) {}

    void addEdge(int x, int y) {
        adj[x].insert(y);
        adj[y].insert(x); // Since the graph is undirected
    }

    // Check if all key servers are connected using DFS
    bool areAllKeyServersConnected(const vector<int>& keyServers, const vector<bool>& on) {
        if (keyServers.empty()) return true;
        vector<bool> visited(vertices, false);
        dfs(keyServers[0], visited, on);
        for (int keyServer : keyServers) {
            if (!visited[keyServer]) return false;
        }
        return true;
    }

private:
    void dfs(int src, vector<bool>& visited, const vector<bool>& on) {
        visited[src] = true;
        for (int neighbor : adj[src]) {
            if (!visited[neighbor] && on[neighbor]) {
                dfs(neighbor, visited, on);
            }
        }
    }
};

int minServers = INT_MAX;

void preprocessGraph(Graph& graph, vector<bool>& on, const vector<int>& keyServers) {
    set<int> keyServersSet(keyServers.begin(), keyServers.end());

    for (int i = 0; i < graph.vertices; i++) {
        if (keyServersSet.find(i) == keyServersSet.end() && graph.adj[i].size() <= 1) {
            on[i] = false; // Turn off non-key servers with degree <= 1
        }
    }
}

void findMinServers(Graph& graph, vector<bool>& on, int current, int count, const vector<int>& keyServers, int& best, vector<bool>& visited) {
    if (current == graph.vertices) {
        if (graph.areAllKeyServersConnected(keyServers, on)) {
            best = min(best, count);
        }
        return;
    }

    if (visited[current]) { // Skip already processed or visited nodes
        findMinServers(graph, on, current + 1, count, keyServers, best, visited);
        return;
    }

    // Skip if it's a key server
    if (find(keyServers.begin(), keyServers.end(), current) != keyServers.end()) {
        findMinServers(graph, on, current + 1, count, keyServers, best, visited);
        return;
    }

    // Try to turn off the current server
    on[current] = false;
    if (graph.areAllKeyServersConnected(keyServers, on)) {
        findMinServers(graph, on, current + 1, count - 1, keyServers, best, visited);
    }
    on[current] = true; // Backtrack

    // Try keeping the current server on
    visited[current] = true; // Mark as visited to avoid reprocessing
    findMinServers(graph, on, current + 1, count, keyServers, best, visited);
    visited[current] = false; // Unmark for other branches of recursion
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    vector<int> keyServers(k);
    vector<bool> on(n, true), visited(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    for (int i = 0; i < k; i++) {
        cin >> keyServers[i];
    }

    preprocessGraph(g, on, keyServers);
    int best = n; // Start with the maximum number of servers
    findMinServers(g, on, 0, n, keyServers, best, visited);

    cout << (best == n ? 200 : best) << endl; // If no solution was found, output 200 as per the problem statement

    return 0;
}
