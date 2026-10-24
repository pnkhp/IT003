#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<string, int>> students(N);

    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }
    int x; cin>>x;
int tmp = 0;
    for (int i = 0; i < N; i++) {
        
        if (x >= students[i].second) {
            cout << students[i].first << '\n';
            tmp++;
        }
    }
if(tmp==0)
    cout << "No items found" << '\n';

    

    return 0;
}