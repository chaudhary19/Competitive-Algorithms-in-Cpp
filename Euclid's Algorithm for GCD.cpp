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
    int a,b;
    cin>>a>>b;
    int result=gcd(a,b);
    cout<<result<<endl;
    return 0;
}
    
