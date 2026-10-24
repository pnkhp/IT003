#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


void in(const vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    in(a, n);

    cout << "Sap xep:\n";
    for (int i = 0; i < n - 1; i++) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi swap: ";
        in(a, n);


        int min_idx = i + 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        cout << "Phan tu nho nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << a[min_idx] << "\n";
        cout << "Swap " << a[i] << " va " << a[min_idx] << "\n";
        swap(a[i], a[min_idx]);

        cout << "Mang sau khi swap: ";
        in(a, n);
    }

    cout << "Mang sau khi sap xep:\n";
    in(a, n);

    return 0;
}