#include <iostream>
#include<vector>
using namespace std;
#define ll long long 



void BubbleSort(vector<int> &a, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}


int main() {
    
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    BubbleSort(a, n);
   

    return 0;
}