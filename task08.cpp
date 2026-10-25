#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

void countingSortByDigit(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int d = 1; d < 10; d++) count[d] += count[d - 1];

    for (int i = n - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int arr[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    cout << "Original: "; printArray(arr, n); cout << "\n";
    cout << "Maximum value = " << maxVal << "\n\n";

    int passes = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
        passes++;
        cout << "After pass " << passes << " (place " << exp << "): ";
        printArray(arr, n);
        cout << endl;
    }

    cout << "\nSorted: "; printArray(arr, n);
    cout << "\nTotal number of passes: " << passes
         << " (number of digits in " << maxVal << ")" << endl;
    return 0;
}
