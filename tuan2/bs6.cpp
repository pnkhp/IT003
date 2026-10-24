#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int query;
    cin >> query;

    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid].first == query) {
            cout << a[mid].second << '\n';
            return 0;
        }

        if (a[mid].first < query) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Not Found\n";

    return 0;
}