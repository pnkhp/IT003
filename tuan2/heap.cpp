#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

void Output(const vector<ll> &a, ll n) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        if (i == n && n != (ll)a.size()) {
            cout << "| ";
        }
        cout << a[i] << " ";
    }
    cout << "\n";
}

void heapify(vector<ll> &a, ll i, ll n) {
    ll j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && a[j] < a[j + 1]) {
            j++;
        }

        if (a[j] < a[i]) {
            return;
        }

        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void buildHeap(vector<ll> &a, ll n) {
    for (ll i = (n - 1) / 2; i >= 0; i--) {
        heapify(a, i, n);
    }
}

void HeapSort(vector<ll> &a, ll n) {
    buildHeap(a, n);

    cout << "Mang sau khi BuildHeap: ";
    Output(a, n);

    while (n > 1) {
        cout << "Swap " << a[0] << " va " << a[n - 1] << "\n";

        swap(a[0], a[n - 1]);
        n--;

        heapify(a, 0, n);

        cout << "\nMang sau khi heapify voi n = " << n << ": ";
        Output(a, n);
    }
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    Output(a, n);

    cout << "\nSap xep:\n";
    HeapSort(a, n);

    cout << "Mang sau khi sap xep:\n";
    Output(a, n);

    return 0;
}