#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

int getMax(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m) m = arr[i];
    return m;
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

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
        pass++;
        cout << "After pass " << pass << " (place " << exp << "): ";
        printArray(arr, n);
        cout << endl;
    }
}

int main() {
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: "; printArray(arr, n); cout << "\n\n";
    radixSort(arr, n);
    cout << "\nSorted:   "; printArray(arr, n); cout << endl;
    return 0;
}
