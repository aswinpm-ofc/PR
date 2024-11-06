#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;
const int MAX_CAPACITY = 1000;  

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1] = {0};  

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }

    cout << "Maximum value in the knapsack: " << dp[n][capacity] << endl;

    int w = capacity;
    cout << "Items included in the knapsack:\n";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " (weight: " << weights[i - 1] << ", value: " << values[i - 1] << ")\n";
            w -= weights[i - 1];  
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    knapsack(capacity, weights, values, n);

    return 0;
}
