#include <iostream>
#include <vector>
using namespace std;

int b;

bool isBad(int k) {
    return k >= b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> b;

    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isBad(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}