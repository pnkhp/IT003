#include <iostream>
using namespace std;

bool check(long long a, long long k,
           long long b, long long m,
           long long d, long long n) {

    long long day1 = d - d / k;
    long long day2 = d - d / m;
    long long tree1 = day1 * a;
    long long tree2 = day2 * b;

    return tree1 + tree2 >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;

    long long l = 1;
    long long r = n;

    while (l < r) {
        long long d = l + (r - l) / 2;

        if (check(a, k, b, m, d, n)) {
            r = d;
        } else {
            l = d + 1;
        }
    }

    cout << l;

    return 0;
}