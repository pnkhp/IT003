#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> books(N);

    for (int i = 0; i < N; i++) {
        cin >> books[i];
    }
    int count,tmp = -1;
    int tim;
    cin >> tim;

    for (int i = 0; i < N; i++) {
        count++;
        if (books[i] == tim) {

            cout << count << '\n';
            return 0;
        }
    }

    cout << tmp << '\n';

    return 0;
}