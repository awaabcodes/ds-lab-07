#include <iostream>
using namespace std;

struct Stats {
    int calls = 0;
    int merges = 0;
    int comparisons = 0;
};

void merge(int arr[], int left, int mid, int right, Stats &s) {
    int size = right - left + 1;
    int *temp = new int[size];

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        s.comparisons++;
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else                  temp[k++] = arr[j++];
    }
    while (i <= mid)   temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int t = 0; t < size; t++)
        arr[left + t] = temp[t];

    s.merges++;
    delete[] temp;
}

void mergeSort(int arr[], int left, int right, Stats &s) {
    s.calls++;
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, s);
    mergeSort(arr, mid + 1, right, s);
    merge(arr, left, mid, right, s);
}

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Error: n must be a positive integer." << endl;
        return 1;
    }

    int *arr = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Stats s;
    mergeSort(arr, 0, n - 1, s);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nRecursive calls : " << s.calls
         << "\nMerge operations: " << s.merges
         << "\nComparisons     : " << s.comparisons << endl;

    delete[] arr;
    arr = nullptr;
    return 0;
}
