#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> d;

    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] >= d) {
      
            ans = a[mid];
            r = mid - 1;
        }
        else {
       
            l = mid + 1;
        }
    }

    if (ans == -1)
        cout << "No suitable classroom";
    else
        cout << ans;

    return 0;
}