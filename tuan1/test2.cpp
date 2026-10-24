#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n; 
    if (n<0) return 0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x; cin>>x;
    vector<int>c(n);
    int count = 0;
    int tmp = 0;
    for (int i=0; i<n;i++){
        if (x == a[i]){
            tmp++;
            c[count]=i;
            count++;
        }
    }
    
    cout<<tmp<<'\n';
    if (count != 0){
    for(int j = 0; j < count; j++){
        cout<<c[j]<<" "<<c[j]+1<<'\n';
    }
}

}