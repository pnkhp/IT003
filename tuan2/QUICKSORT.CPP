#include <iostream>
using namespace std;

void quickSort(int *a, int l, int r)
{
  if (l>=r) return;
  int i = l;
  int j = l;
  int pivot = a[r];
  for (; j<r;j++){
    if(a[j] < pivot){
        swap(a[j], a[i]);
        i++;
    }
  }
  swap(a[r], a[i]);
  quickSort(a, l, i-1);
  quickSort(a, i+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n > 0) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}