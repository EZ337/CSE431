#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int N, K;
        std::cin >> N >> K;

        // Logic requirements
        std::vector<int> logicReqs(N);

        for (int i = 0; i < N; ++i)
            std::cin >> logicReqs[i];

        // Initialize dynamic programming array
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= K; ++j) {
                if (logicReqs[i - 1] <= j) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - logicReqs[i - 1]] + logicReqs[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Index the last array for the solution
        std::cout << dp[N][K] << std::endl;
    }

    return 0;
}