#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<string, pair<int, int>>> patients(N);

    for (int i = 0; i < N; i++) {
        cin >> patients[i].first
            >> patients[i].second.first
            >> patients[i].second.second;
    }

    bool found = false;
    string result;
    int maxSeverity = -1;

    for (int i = 0; i < N; i++) {

        string name = patients[i].first;
        int severity = patients[i].second.first;
        int seen = patients[i].second.second;

        if (seen == 0 && severity > maxSeverity) {
            maxSeverity = severity;
            result = name;
            found = true;
        }
    }

    if (found) {
        cout << result << '\n';
    }
    else {
        cout << "All patients seen" << '\n';
    }

    return 0;
}