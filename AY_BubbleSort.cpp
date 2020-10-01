#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

// Bubble Sort
void bubbleSort(int a[], int n)  
{  
  for (int i = 0; i < n-1; i++)      
    for (int j = 0; j < n-i-1; j++) 
     if (a[j] > a[j+1])  
      {
        int temp = a[j];  
        a[j] = a[j+1];  
        a[j+1] = temp;
      }
}  
 
int32_t main()
{
    IOS
    int a[] = {80, 40, 50, 30, 10, 20, 60, 70};  
    int n = sizeof(a)/sizeof(a[0]);  
    bubbleSort(a, n);  
    cout<<"Sorted array is: "<<endl;  
    for (int i = 0; i < n; i++)  
        cout << a[i] << " ";  
    cout << endl; 
}
