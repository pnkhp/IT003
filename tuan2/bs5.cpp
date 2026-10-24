#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int l = 0, r = n-1;
    while(l<r){
        int mid = l + (r - l)/2;

        if ( a[mid] < a[mid + 1]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    } 
    cout<<a[l];
    return 0;

}