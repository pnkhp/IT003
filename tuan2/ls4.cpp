#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {


    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        long long min1 = 2e18, min2 = 2e18;
        long long max1 = -1, max2 = -1;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

   
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }

         
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }

        long long ans = (max1 - min1) + (max2 - min2);
        cout << ans << '\n';
    }

    return 0;
}