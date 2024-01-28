#include <iostream>

using namespace std;

// Function to calculate the sum of elements in an array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in an array
int maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // Get the length of the array from the user
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    // Declare an array of length n
    int arr[n];

    // Input elements from the user and store them in the array
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Call the summation function and display the result
    int sum = summation(arr, n);
    cout << "Sum of the array elements: " << sum << endl;

    // Call the maximum function and display the result
    int max = maximum(arr, n);
    cout << "Maximum element in the array: " << max << endl;

    return 0;
}
