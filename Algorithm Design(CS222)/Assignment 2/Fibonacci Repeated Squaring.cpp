#include <iostream>
using namespace std;

int counter = 0; // Global counter for counting multiplications

// Function to multiply two 2x2 matrices
void matrix_mult( int A[2][2],  int B[2][2], int result[2][2]) {
    counter++;
    result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

// Function to calculate the power of a matrix using non_recursive  repeated squaring method
void matrix_pow(int X[2][2], int k, int B[2][2]) {
    int A[2][2] = {{X[0][0], X[0][1]}, {X[1][0], X[1][1]}};
    B[0][0] = 1, B[0][1] = 0; // Identity matrix
    B[1][0] = 0, B[1][1] = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            int temp[2][2];
            matrix_mult(B, A, temp);
            B[0][0] = temp[0][0];
            B[0][1] = temp[0][1];
            B[1][0] = temp[1][0];
            B[1][1] = temp[1][1];
        }

        int temp[2][2];
        matrix_mult(A, A, temp);
        A[0][0] = temp[0][0];
        A[0][1] = temp[0][1];
        A[1][0] = temp[1][0];
        A[1][1] = temp[1][1];

        k /= 2;
    }
}

// Function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) 
        return 0;

    int X[2][2] = {{0, 1}, {1, 1}};
    int B[2][2];
    matrix_pow(X, n, B);

    return B[0][1]; 
}

int main() {
    int n;
    cout << "Enter n(atleast 40): ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        counter = 0; // Reset the counter
        int fib_n = fibonacci(i);
        cout << "n: " << i << ", Fibonacci_value: " << fib_n << ", Multiplications: " << counter << endl;
    }

    return 0;
}
