#include <iostream>

using namespace std;

void division(int x, int y, int &q, int &r) {
    if (x < y) {
        q = 0;
        r = x;
        return;
    }

    division(x >> 1, y, q, r); // Recursive call with x / 2
    q = q << 1; // Left shift q (multiply by 2)
    r = r << 1; // Left shift r (multiply by 2)

    if (x % 2 == 1) {
        r = r + 1;
    }

    if (r >= y) {
        r = r - y;
        q = q + 1;
    }
}

int gcd(int x, int y) {
    if (y == 0) return x; // Base case: gcd(x, 0) = x

    int q, r;
    division(x, y, q, r); // Compute x = q * y + r

    return gcd(y, r); // Recursive call: gcd(y, r)
}

int main() {
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    cout << "GCD: " << gcd(x, y) << endl;
    return 0;
}
