#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a==0) return b;
    else
       return gcd(b%a,a);
}
int main()
{
    int n,i,result;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
   
     result=arr[0];   
    for(i=1;i<n;i++)
     {
         result=gcd(arr[i],result);
         if(result==1) break;
     }   
     cout<<result;
     return 0;
}
        