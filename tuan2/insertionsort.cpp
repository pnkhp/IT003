#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void in(const vector<ll> &a, ll n) {
    for (ll i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Mang truoc khi sap xep:\n";
    in(a, n);

    cout << "\nSap xep:\n";

    for (ll i = 1; i < n; i++) {
        cout << "i = " << i << "\n";
        cout << "Mang truoc khi xu ly: ";
        in(a, n);

        ll x = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << x << "\n";

        ll j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }

        ll k = j + 1;
        a[k] = x;

        cout << "Chen " << x << " vao vi tri k = " << k << "\n";
        cout << "Mang sau khi xu ly: ";
        in(a, n);
        cout << "\n";
    }

    cout << "Mang sau khi sap xep:\n";
    in(a, n);

    return 0;
}