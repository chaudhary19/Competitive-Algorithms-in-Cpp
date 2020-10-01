#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

// Merge Sort
void merge(int a[], int left, int mid, int right) 
{ 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int Left[n1], Right[n2]; 
    for (int i= 0; i < n1; i++) 
        Left[i] = a[left + i]; 
    for (int j = 0; j < n2; j++) 
        Right[j] = a[mid + 1 + j]; 
    int i = 0, j = 0, k = left; 
    while (i < n1 && j < n2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            a[k] = Left[i]; 
            i++; 
        } 
        else 
        { 
            a[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        a[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        a[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int a[], int left, int right) 
{ 
    if (left < right) 
    { 
        int mid = left + (right - left) / 2; 
        mergeSort(a, left, mid); 
        mergeSort(a, mid + 1, right); 
        merge(a, left, mid, right); 
    } 
} 
  
int32_t main()
{
    IOS
    int a[] = {80, 40, 50, 30, 10, 20, 60, 70};  
    int n = sizeof(a)/sizeof(a[0]);  
    mergeSort(a, 0, n);  
    cout<<"Sorted array is: "<<endl;  
    for (int i = 0; i < n; i++)  
        cout << a[i] << " ";  
    cout << endl; 
}
