#include <iostream>
using namespace std;

void Output(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void heapify(int *A, int i, int n){
    int j = 2 * i + 1;
    while (j < n){
        if (j + 1 < n && A[j] < A[j + 1])
            j++;
        if (A[j] < A[i])
            return;
        swap(A[i], A[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void buildHeap(int *A, int n){
    int i = (n - 1) / 2;
    while (i >= 0){
        heapify(A, i, n);
        i--;
    }
}


void HeapSort(int *A, int n){
    buildHeap(A, n);
    while (n > 1){
        swap(A[0], A[n - 1]);
        n--;
        heapify(A, 0, n);
    }
}

int main() {
    int A[] = {3, 0, 8, 2, 1, 4, 7};
    int n = 7;

    
    Output(A, n);

    HeapSort(A, n);

    
    Output(A, n);

    return 0;
}