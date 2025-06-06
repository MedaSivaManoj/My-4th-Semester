#include <iostream>

using namespace std;

void division(int x, int y, int &q, int &r) {
    if (x < y) {
        q = 0;
        r = x;
        return;
    }

    division(x >> 1, y, q, r); // Recursive call with x / 2
    q = q << 1; // Left shift q (equivalent to multiplying by 2)
    r = r << 1; // Left shift r (equivalent to multiplying by 2)

    if (x % 2 == 1) {
        r = r + 1;
    }

    if (r >= y) {
        r = r - y;
        q = q + 1;
    }
}

int main() {
    int x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    int q, r;
    division(x, y, q, r);

    cout << "Quotient: " << q << ", Remainder: " << r << endl;
    return 0;
}
