#include <iostream>
#include <vector>
using namespace std;

int myBinarySearch(const vector<string>& a,const string& x, int& count) {
    int l = 0, r = (int)a.size() - 1;
    count = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        count++;

        if (a[mid] == x) {
            return mid +1;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n<0) return 0;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string x;
    cin >> x;

    int count = 0;
    int kq = myBinarySearch(a, x, count);

    //cout << kq << '\n';
    if (kq != -1) {
        cout << count << '\n';
    } 

    return 0;
}