#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

void in(const vector<ll> &a) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void QuickSort(vector<ll> &a, ll left, ll right) {
    if (left >= right) return;

    ll i = left;
    ll j = right;
    ll pivot = a[(left + right) / 2];

    cout << "Truoc: ";
    in(a);
    cout << "Left=" << left
         << " - Right=" << right
         << " - Pivot=" << pivot << "\n";

    while (i < j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    cout << "Sau: ";
    in(a);
    cout << "\n";

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    in(a);

    cout << "\nSap xep:\n";
    QuickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep:\n";
    in(a);

    return 0;
}