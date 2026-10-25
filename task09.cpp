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

int getMax(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m) m = arr[i];
    return m;
}

int countDigits(int x) {
    int digits = 0;
    do { digits++; x /= 10; } while (x > 0);
    return digits;
}

void countingSortByDigit(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    cout << "  Frequency count : "; printCounts(count); cout << endl;

    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];
    cout << "  Cumulative count: "; printCounts(count); cout << endl;

    for (int i = n - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    cout << "  Output array    : "; printArray(output, n); cout << endl;

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    cout << "  Copied back to original array: "; printArray(arr, n); cout << endl;
}

int main() {
    int trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
    int n = sizeof(trackingIDs) / sizeof(trackingIDs[0]);

    int maxVal = getMax(trackingIDs, n);
    int totalPasses = countDigits(maxVal);

    cout << "Original array: "; printArray(trackingIDs, n);
    cout << "\nMax value = " << maxVal << " -> " << totalPasses << " digit passes\n";

    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        pass++;
        cout << "\n--- Pass " << pass << " of " << totalPasses
             << " (place value " << exp << ") ---\n";
        countingSortByDigit(trackingIDs, n, exp);
    }

    cout << "\nFinal sorted array: "; printArray(trackingIDs, n); cout << endl;
    return 0;
}
