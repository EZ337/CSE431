#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void convertToKClique(int N, int M, int K, vector<pair<int, int>>& edges) {
    // Convert to Independent Set
    int independentSetSize = N - K;
    set<int> independentSet;
    for (int i = 0; i < N; ++i) {
        independentSet.insert(i);
    }
    for (auto& edge : edges) {
        independentSet.erase(edge.first);
        independentSet.erase(edge.second);
    }

    // Convert to Clique
    set<pair<int, int>> complementEdges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (independentSet.find(i) != independentSet.end() && independentSet.find(j) != independentSet.end()) {
                // If both vertices are in the independent set, add edge to complement graph
                complementEdges.insert({i, j});
            } else if (i != j && find(edges.begin(), edges.end(), make_pair(i, j)) == edges.end()) {
                // If edge not present in original graph, add it to complement graph
                complementEdges.insert({i, j});
            }
        }
    }

    // Output the complement edges
    cout << N << " " << complementEdges.size() << " " << independentSetSize << endl;
    for (auto& edge : complementEdges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    convertToKClique(N, M, K, edges);

    return 0;
}
