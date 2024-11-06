#include <iostream>
using namespace std;

// Function to calculate the maximum coins collected and print the path
void coin_collecting(int C[][100], int n, int m) {
    int F[100][100] = {0}; // DP table initialized to 0
    F[0][0] = C[0][0];

    // Fill the first column
    for (int i = 1; i < n; i++) {
        F[i][0] = F[i - 1][0] + C[i][0];
    }

    // Fill the first row
    for (int j = 1; j < m; j++) {
        F[0][j] = F[0][j - 1] + C[0][j];
    }

    // Fill the rest of the matrix
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    // The bottom-right corner contains the maximum number of coins
    cout << "Maximum coins collected: " << F[n - 1][m - 1] << endl;

    // Backtracking to find the path
    int i = n - 1, j = m - 1;
    cout << "Path: ";
    while (i > 0 || j > 0) {
        cout << "(" << i << ", " << j << ") ";
        if (i == 0) {
            j--; // Move left if we're in the first row
        } else if (j == 0) {
            i--; // Move up if we're in the first column
        } else if (F[i - 1][j] > F[i][j - 1]) {
            i--; // Move up if the value came from above
        } else {
            j--; // Move left if the value came from the left
        }
    }
    // Print the starting point
    cout << "(0, 0)" << endl;
}

int main() {
    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    int C[100][100]; 

    cout << "Enter the coin values (matrix):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j]; 
        }
    }

    coin_collecting(C, n, m);

    return 0;
}
