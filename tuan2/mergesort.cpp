

#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};
void merge(SanPham a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    SanPham* b = new SanPham[r - l + 1];

    while (i <= m && j <= r) {
        if (a[i].gia < a[j].gia || (a[i].gia == a[j].gia && a[i].ma < a[j].ma)) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (int p = 0; p < k; p++) {
        a[l + p] = b[p];
    }

    delete[] b;
}

void mergeSort(SanPham a[], int x, int n) {
    if (x >= n) return;
    
    int m = x + (n - x) / 2;
    
    mergeSort(a, x, m);
    mergeSort(a, m + 1, n);
    merge(a, x, m, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}
