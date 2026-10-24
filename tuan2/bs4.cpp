#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool check(const vector<int>& a, int W, int D) {
    int days = 1;
    int load = 0;

    for (int i = 0; i < a.size(); i++) {
        if (load + a[i] <= W) {
            load = load + a[i];
        } else {
            days = days+1;
            load = a[i];
        }
    }

    return days <= D;
}

int main(){
    int n, d; cin>>n>>d;
    int l = 0; int r = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
        if (a[i] > l) l = a[i];
        r = r + a[i];
    }
    while (l < r){
        int mid = l + (r - l)/2;

        if(check(a, mid, d)){
            r = mid;
        }
        else{
            l = mid +1;
        }
    }
    cout<<l;


    return 0;
}