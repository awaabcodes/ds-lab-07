#include <iostream>
using namespace std;

void swapInts(int &a, int &b) { int t = a; a = b; b = t; }

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

int partition(int arr[], int low, int high, int &comparisons) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swapInts(arr[i], arr[j]);
        }
    }
    swapInts(arr[low], arr[i]);
    return i;
}

void quickSort(int arr[], int n, int low, int high, int &comparisons) {
    if (low < high) {
        int pivot = arr[low];
        int p = partition(arr, low, high, comparisons);

        cout << "Pivot = " << pivot << " (range " << low << ".." << high
             << ", final index " << p << ") -> ";
        printArray(arr, n);
        cout << endl;

        quickSort(arr, n, low, p - 1, comparisons);
        quickSort(arr, n, p + 1, high, comparisons);
    }
}

int main() {
    int ids[] = {55, 25, 75, 15, 65, 35, 45};
    int n = sizeof(ids) / sizeof(ids[0]);
    int comparisons = 0;

    cout << "Original: "; printArray(ids, n); cout << "\n\n";
    quickSort(ids, n, 0, n - 1, comparisons);
    cout << "\nSorted: "; printArray(ids, n);
    cout << "\nTotal element comparisons: " << comparisons << endl;
    return 0;
}
