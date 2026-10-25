#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}";
}

void merge(int arr[], int n, int left, int mid, int right, int &mergeCount) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int L[50], R[50];
    for (int i = 0; i < leftSize; i++)  L[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < leftSize)  arr[k++] = L[i++];
    while (j < rightSize) arr[k++] = R[j++];

    mergeCount++;
    cout << "Merge #" << mergeCount << " [index " << left << " to " << right << "]: ";
    printArray(arr, n);
    cout << endl;
}

void mergeSort(int arr[], int n, int left, int right, int &mergeCount) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, n, left, mid, mergeCount);
    mergeSort(arr, n, mid + 1, right, mergeCount);
    merge(arr, n, left, mid, right, mergeCount);
}

int main() {
    int marks[] = {78, 45, 92, 63, 45, 88, 51, 70};
    int n = sizeof(marks) / sizeof(marks[0]);
    int mergeCount = 0;

    cout << "Original array: ";
    printArray(marks, n);
    cout << "\n\n";

    mergeSort(marks, n, 0, n - 1, mergeCount);

    cout << "\nSorted marks: ";
    printArray(marks, n);
    cout << "\nTotal merge operations: " << mergeCount << endl;
    return 0;
}
