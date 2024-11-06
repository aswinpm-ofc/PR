#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int f1 = 0, f2 = 1, f = 0;
    for (int i = 2; i <= n; i++) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    
    return f;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n-1) << endl;
    return 0;
}
