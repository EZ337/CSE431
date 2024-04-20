#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to find the smallest team
pair<int, vector<int>> findSmallestTeam(int N, int K, vector<vector<int>>& people) {
    unordered_set<int> coveredSkills;
    vector<int> team;

    while (coveredSkills.size() < K) {
        int maxCovered = 0;
        int bestCandidate = -1;

        for (int i = 0; i < N; ++i) {
            int uncoveredCovered = 0;
            for (int skill : people[i]) {
                if (coveredSkills.find(skill) == coveredSkills.end()) {
                    ++uncoveredCovered;
                }
            }

            if (uncoveredCovered > maxCovered) {
                maxCovered = uncoveredCovered;
                bestCandidate = i;
            }
        }

        for (int skill : people[bestCandidate]) {
            coveredSkills.insert(skill);
        }

        team.push_back(bestCandidate); // Push person ID instead of index
    }

    return {team.size(), team};
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> people(N);
    for (int i = 0; i < N; ++i) {
        int skillCount;
        cin >> skillCount;
        people[i].resize(skillCount);
        for (int j = 0; j < skillCount; ++j) {
            cin >> people[i][j];
        }
    }

    auto result = findSmallestTeam(N, K, people);

    cout << result.first << endl;
    for (int member : result.second) {
        cout << member << " "; // Output person ID
    }
    cout << endl;

    return 0;
}
