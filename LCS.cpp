#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100; // Maximum length for the strings

// Function to find the length of the longest common subsequence and print it
int longestCommonSubsequence(char X[], char Y[], int m, int n) {
    int f[MAX][MAX] = {0}; // DP table initialized to 0

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1; // Characters match
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]); // Take max
            }
        }
    }

    // Length of the LCS
    
    cout << "Length of LCS: " << f[m][n] << endl;

    // Backtracking to find the LCS
    int i = m, j = n;
    char lcs[MAX]; // Array to store LCS characters
    int index = f[m][n]; // Start from the end of the LCS

    lcs[index] = '\0'; // Null-terminate the LCS string

    while (i > 0 && j > 0) {
        // If characters match, they are part of the LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // Store character in LCS
            i--;
            j--;
            index--; // Move to the previous position
        }
        // If not, move in the direction of the larger value
        else if (f[i - 1][j] > f[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // Print the LCS
    cout << "LCS: " << lcs << endl;

    return f[m][n];
}

int main() {
    char X[MAX], Y[MAX]; // Input strings X and Y

    cout << "Enter first string (X): ";
    cin >> X; // Input the first string
    cout << "Enter second string (Y): ";
    cin >> Y; // Input the second string

    int m = strlen(X); // Length of string X
    int n = strlen(Y); // Length of string Y

    longestCommonSubsequence(X, Y, m, n);

    return 0;
}
