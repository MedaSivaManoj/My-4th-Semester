#include <iostream>
using namespace std;

// Function to print array within the given range
void printArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Merge function to combine two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;    // Size of left subarray
    int n2 = right - mid;        // Size of right subarray
    
    int L[n1], R[n2];            // Temporary arrays for left and right subarrays
// Copy data to temporary arrays
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
// Pointers for left, right, and merged array
    while (i < n1 && j < n2) {          // Pick smaller element from left or right subarray
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort function
void mergesort(int arr[], int start, int end) {
    cout << "Starting **[" << start << ", " << end << "]" << endl;
    printArray(arr, start, end);

    if (start < end) {
        int mid = start + (end - start) / 2;
        
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    cout << "Ending[" << start << ", " << end << "]**" << endl;
    printArray(arr, start, end);
}

int main() {
    int n;
    cout << "Please enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "Final sorted array: ";
    printArray(arr, 0, n - 1);

    return 0;
}
