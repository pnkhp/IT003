#include <iostream>
#include <vector>
#define ll long long
using namespace std;
void swap(ll &a, ll &b) {
    ll tmp = a;
    a = b;
    b = tmp;
}


void in(const vector<ll> &a, ll n) {
    for (ll i = 0; i < n; i++) {
        cout << a[i]<<" ";
    }
    cout << "\n";
}
int main(){
    ll n;
    cin>> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout<<"Mang truoc khi sap xep:"<<endl;
    in(a, n);
    cout<<"Sap xep:"<<endl;
    for (ll i = 0; i<n-1; i++){
        cout<<"i = "<< i<<endl;
        cout<<"Mang truoc khi swap: ";
        in(a,n);
        
        ll min = i;
        for(ll j = i + 1; j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        cout<<"Phan tu nho nhat trong doan [" << i + 1<<", "<<n -1<<"]:"<<a[min]<<endl;
        cout<<"Swap "<< a[i]<<" va "<<a[min]<<endl;
        if (min != i){
            swap(a[i], a[min]);
        }
        cout<<"Mang sau khi swap: ";
        in(a, n);
    }

    in(a, n);

    return 0;

}