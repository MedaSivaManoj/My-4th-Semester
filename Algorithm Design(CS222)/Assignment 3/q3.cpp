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

// Modified gcd function to count function calls
int gcd(int x, int y, int &count) {
    count++; // Increment function call count

    if (y == 0) return x; // Base case

    int q, r;
    division(x, y, q, r); // Compute x = q * y + r

    return gcd(y, r, count); // Recursive call
}

// Function to compute Fibonacci numbers
void fibonacci(int n, int &f1, int &f2) {
    f1 = 1, f2 = 1;
    for (int i = 2; i < n; i++) {
        int temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    for (int k = 1; k <= N; k++) {
        int Fk, Fk1;
        fibonacci(k + 1, Fk, Fk1); // Compute F_k and F_k+1

        int count = 0;
        gcd(Fk, Fk1, count); // Compute gcd and count calls

        cout << "(" << k << ", " << count << ")" << endl;
    }

    return 0;
}
