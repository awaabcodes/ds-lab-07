#include <iostream>
using namespace std;

void printSub(int arr[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << (i < size - 1 ? ", " : " ");
    cout << "}";
}

void merge(int arr[], int left, int mid, int right, int &comparisons) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int L[50], R[50];
    for (int i = 0; i < leftSize; i++)  L[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++) R[j] = arr[mid + 1 + j];

    cout << "Left  = "; printSub(L, leftSize);
    cout << "   Right = "; printSub(R, rightSize);
    cout << endl;

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < leftSize)  arr[k++] = L[i++];
    while (j < rightSize) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, int &comparisons) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, comparisons);
    mergeSort(arr, mid + 1, right, comparisons);
    merge(arr, left, mid, right, comparisons);
}

int main() {
    int prices[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = sizeof(prices) / sizeof(prices[0]);
    int comparisons = 0;

    cout << "Original prices: "; printSub(prices, n); cout << "\n\n";

    mergeSort(prices, 0, n - 1, comparisons);

    cout << "\nFinal sorted prices: "; printSub(prices, n);
    cout << "\nTotal comparisons: " << comparisons << endl;
    return 0;
}
