#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum grid size

// Function to find the minimum cost path
void minCostPath(int cost[MAX_SIZE][MAX_SIZE], int n, int m) {
    int dp[MAX_SIZE][MAX_SIZE];

    // Initialize the starting point
    dp[0][0] = cost[0][0];

    // Fill the first column
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

    // Fill the first row
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
    }

    // Fill the rest of the dp table, allowing diagonal movement
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int fromAbove = dp[i - 1][j];
            int fromLeft = dp[i][j - 1];
            int fromDiagonal = dp[i - 1][j - 1];
            dp[i][j] = min(fromAbove, min(fromLeft, fromDiagonal)) + cost[i][j];
        }
    }

    cout << "Minimum Cost: " << dp[n - 1][m - 1] << endl;

    // Print path
    cout << "Path: ";
    int i = n - 1, j = m - 1;
    while (i > 0 || j > 0) {
        cout << "(" << i << ", " << j << ") ";
        if (i == 0) {
            j--; // Move left
        } else if (j == 0) {
            i--; // Move up
        } else if (dp[i - 1][j] < dp[i][j - 1] && dp[i - 1][j] < dp[i - 1][j - 1]) {
            i--; // Move up
        } else if (dp[i][j - 1] < dp[i - 1][j - 1]) {
            j--; // Move left
        } else {
            i--; j--; // Move diagonally
        }
    }
    cout << "(0, 0)" << endl; // Print the starting point
}

int main() {
    int n, m;
    int cost[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter cost matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    minCostPath(cost, n, m);
    return 0;
}
