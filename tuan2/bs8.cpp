#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int query;
    cin >> query;

    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == query) {
            cout <<"YES"<< '\n';
            return 0;
        }

        if (a[mid] < query) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "NO\n";

    return 0;
}