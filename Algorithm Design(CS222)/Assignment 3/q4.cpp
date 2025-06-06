#include <iostream>

using namespace std;

// Recursive function to compute gcd and coefficients u, v
int extendedGCD(int x, int y, int &u, int &v) {
    if (y == 0) {
        u = 1;
        v = 0;
        return x; // Base case: gcd(x, 0) = x
    }

    int u1, v1;
    int gcd = extendedGCD(y, x % y, u1, v1); // Recursive call

    // Update u and v using the results of recursion
    u = v1;
    v = u1 - (x / y) * v1;

    return gcd;
}

int main() {
    int x, y;
    cout << "Input the two numbers: ";
    cin >> x >> y;

    int u, v;
    int gcd = extendedGCD(x, y, u, v); // Compute GCD and coefficients

    // Output the results in the required format
    cout << "The gcd of " << x << " and " << y << " is " << gcd << "." << endl;
    cout << gcd << " = (" << u << ") * " << x << " + (" << v << ") * " << y << "." << endl;

    return 0;
}
