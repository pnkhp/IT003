#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myBinarySearch(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
   

    while (l <= r) {
        int mid = l + (r - l) / 2;
       

        if (a[mid] == x) {
            return 1;
        } 
        if ( a[l] <= a[mid] ){
            if( a[l] <=x && x<a[mid] ){
                r = mid -1;
            }
            else l = mid +1;
        }
        else{
            if(a[r]>=x && x>a[mid]){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n<0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;


    if (myBinarySearch(a, x)) cout<<"YES";
    else cout<<"NO";

   

    return 0;
}