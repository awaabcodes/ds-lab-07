#include <iostream>
using namespace std;

void printTagged(int arr[], int pos[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "[" << pos[i] << "]" << (i < n - 1 ? ", " : " ");
    cout << "}";
}

int countDigits(int x) {
    int digits = 0;
    do { digits++; x /= 10; } while (x > 0);
    return digits;
}

void countingSortByDigit(int arr[], int pos[], int n, int exp) {
    int outVal[100], outPos[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int d = 1; d < 10; d++) count[d] += count[d - 1];

    for (int i = n - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;
        outVal[count[d] - 1] = arr[i];
        outPos[count[d] - 1] = pos[i];
        count[d]--;
    }
    for (int i = 0; i < n; i++) { arr[i] = outVal[i]; pos[i] = outPos[i]; }
}

int main() {
    int arr[] = {7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos[100];
    for (int i = 0; i < n; i++) pos[i] = i;

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    int totalPasses = countDigits(maxVal);
    cout << "Original (value[original position]):\n  "; printTagged(arr, pos, n);
    cout << "\nMax = " << maxVal << " -> maximum digit passes required = "
         << totalPasses << "\n\n";

    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, pos, n, exp);
        pass++;
        cout << "After pass " << pass << " (place " << exp << "):\n  ";
        printTagged(arr, pos, n);
        cout << endl;
    }

    cout << "\nSorted accession numbers: { ";
    for (int i = 0; i < n; i++) cout << arr[i] << (i < n - 1 ? ", " : " ");
    cout << "}\n";

    bool stable = true;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] == arr[i + 1] && pos[i] > pos[i + 1]) stable = false;
    cout << "Duplicates kept original relative order: " << (stable ? "YES" : "NO") << endl;
    return 0;
}
