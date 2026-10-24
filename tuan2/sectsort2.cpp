#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    string ten;
    int diem;
};
void insertionSort(SinhVien A[], int n) {
    for (int i = 1; i < n; i++) {
        SinhVien e = A[i]; int k;
        for (k = i-1; k>-1; k--) {
            if (!(e.diem > A[k].diem || (e.diem == A[k].diem && e.ten < A[k].ten))) break;
            A[k+1] = A[k];
    }
        A[k+1] = e;
    }
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SinhVien* a = new SinhVien[n];
    for (int i = 0; i < n; i++) cin >> a[i].maso >> a[i].ten >> a[i].diem;

    insertionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i].maso << ' ' << a[i].ten << ' ' << a[i].diem << '\n';
    }
    return 0;
}
