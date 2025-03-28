#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

//code for Recursive Fibonacci function
int fib(int k) {
    if (k <= 1)
        return k;
    return fib(k - 1) + fib(k - 2);
}

int main() {
    
    string filename;				//Taking  csv file name from user
    cout << "Enter the filename to save (with .csv extension): ";
    getline(cin, filename);
    
    int N;
    cout << "Enter value of N(Atlest 40)\n";
    cin>>N;
   
    // Opening the file for writing
    ofstream file(filename);
    if (!file.is_open()) {			//If we are unable to open the file then showing the error message for user
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    // Writing the header to the CSV file
    file << "k,log(F_k)\n";

   
    for (int k = 2; k <= N; k++) {  
       double log_fib_k = log(fib(k)) ;
        file << k << "," << log_fib_k << "\n";
    }

    cout << "Fibonacci and logarithm data saved to '" << filename << "'." << endl;

    // Closing the file
    file.close();
    return 0;
}
