#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<string, string>> students(N);

    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }

    for (int i = 0; i < N; i++) {
        if (students[i].second == "A") {
            cout << students[i].first << '\n';
            return 0;
        }
    }

    cout << "All Present" << '\n';

    

    return 0;
}