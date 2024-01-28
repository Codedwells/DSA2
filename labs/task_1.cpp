#include <iostream>

using namespace std;

// Function to calculate the sum of the integers in the array
int summation(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum integer in the array
int maximum(const int* arr, int size) {
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = summation(arr, n);
    int max = maximum(arr, n);

    cout << "Sum of the integers: " << sum << endl;
    cout << "Maximum integer: " << max << endl;

    return 0;
}
