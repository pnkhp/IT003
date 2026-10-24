#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n;
    cin>>n;
    
    if (n < 0) return 0;
    vector<int> a(n);
    for(int i= 0; i < n; i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;

    int trai = -1;
    for(int i=0; i<n; i++){
        if (x == a[i])
        {
            trai = i;
            break;
        }
    }

    if (trai == -1){
        cout<<-1<<'\n';
    }
    else {
        cout<<trai<<'\n'<<trai+1<<endl;
    }

    int phai = -1;
    int kq = 0 ;
    for (int j= n-1; j>=0; j--)
    {
         if (x == a[j])
        {
            phai = n - j - 1;
            kq = n - j;
            break;
        }
    }
    
    if (phai ==-1){
        cout<<-1<<'\n';

    }
    else {
        cout<<phai<<'\n'<<kq<<'\n';
    }

    
    
    
    
    return 0;}