#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    if (n <0) return 0;
    vector<int>a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    int mex = 0;
    vector<int>b(n+1, 0);
    int p= 0;
    for (int i=0; i<n;i++){
        if(a[i] > 0 && a[i]<=n){
         b[a[i]]=1;
        }
        while (mex <= n && b[mex] == 1){
            mex++;
        }
        cout<<mex<<" ";

    }
}