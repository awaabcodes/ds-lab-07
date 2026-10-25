#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

void printCounts(int count[]) {
    cout << "{ ";
    for (int d = 0; d < 10; d++) cout << count[d] << (d < 9 ? ", " : " ");
    cout << "}";
}

void countingSortByDigit(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    cout << "  Frequency count  (digits 0-9): "; printCounts(count); cout << endl;

    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];
    cout << "  Cumulative count (digits 0-9): "; printCounts(count); cout << endl;

    for (int i = n - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    cout << "  Output array: "; printArray(output, n); cout << endl;

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    cout << "Original: "; printArray(arr, n); cout << "\n";

    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        pass++;
        cout << "\nPass " << pass << " (place value = " << exp << ")\n";
        countingSortByDigit(arr, n, exp);
    }

    cout << "\nSorted: "; printArray(arr, n); cout << endl;
    return 0;
}
