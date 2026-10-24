#include <iostream>
#include <algorithm>
using namespace std;

void Output(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void merge(int a[], const int b[], const int c[],
           int nb, int nc, int k) {
    int i = 0, j = 0, p = 0;

    while (i < nb || j < nc) {
        int endB = min(i + k, nb);
        int endC = min(j + k, nc);

        while (i < endB && j < endC) {
            if (b[i] <= c[j]) {
                a[p++] = b[i++];
            } else {
                a[p++] = c[j++];
            }
        }

        while (i < endB) a[p++] = b[i++];
        while (j < endC) a[p++] = c[j++];
    }
}

void mergeSort(int a[], int n) {
    for (int k = 1; k < n; k *= 2) {
        cout << "k = " << k << "\n";
        cout << "Mang A (truoc khi chia): ";
        Output(a, n);

        int b[200], c[200];
        int nb = 0, nc = 0, p = 0;

        while (p < n) {
            for (int i = 0; i < k && p < n; i++) {
                b[nb++] = a[p++];
            }

            for (int i = 0; i < k && p < n; i++) {
                c[nc++] = a[p++];
            }
        }

        cout << "Mang B: ";
        Output(b, nb);

        cout << "Mang C: ";
        Output(c, nc);

        merge(a, b, c, nb, nc, k);

        cout << "Mang A (sau khi gop): ";
        Output(a, n);
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    Output(a, n);

    cout << "\nSap xep:\n";
    mergeSort(a, n);

    cout << "Mang sau khi sap xep:\n";
    Output(a, n);

    delete[] a;
    return 0;
}