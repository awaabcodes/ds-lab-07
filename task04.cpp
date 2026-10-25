#include <iostream>
using namespace std;

void swapInts(int &a, int &b) { int t = a; a = b; b = t; }

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapInts(arr[i], arr[j]);
        }
    }
    swapInts(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int n, int low, int high, int &partitionCount) {
    if (low < high) {
        partitionCount++;
        cout << "Partition #" << partitionCount << ": low = " << low
             << ", high = " << high << ", pivot = " << arr[high] << endl;

        int p = partition(arr, low, high);

        cout << "   Pivot landed at index " << p << " -> ";
        printArray(arr, n);
        cout << endl;

        quickSort(arr, n, low, p - 1, partitionCount);
        quickSort(arr, n, p + 1, high, partitionCount);
    }
}

int main() {
    int marks[] = {40, 20, 70, 10, 60, 30, 50};
    int n = sizeof(marks) / sizeof(marks[0]);
    int partitionCount = 0;

    cout << "Original: "; printArray(marks, n); cout << "\n\n";
    quickSort(marks, n, 0, n - 1, partitionCount);
    cout << "\nSorted: "; printArray(marks, n);
    cout << "\nTotal partition operations: " << partitionCount << endl;
    return 0;
}
