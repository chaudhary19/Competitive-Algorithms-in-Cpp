#include <iostream>
#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
typedef long long ll;
void mm(void);
ll Chinese_Remainder_Theorem();
ll gcd(ll a,ll b,ll &x,ll &y);
ll ans=0;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    ll x=Chinese_Remainder_Theorem();
    cout<<x<<"\n";
    return 0;
}
ll Chinese_Remainder_Theorem()
{
    mm();
    cout<<"ENTER THE NUMBER OF EQUATIONS\n";
    ll n,i,num1,num2;
    cin>>n;
    pair <ll,ll> p1[n+1];
    cout<<"Enter the number and mod value\nMake sure that GCD of number and mod value should be 1\n";
    for(i=1;i<=n;i++)
    {
        cin>>num1>>num2;
        p1[i]=make_pair(num1,num2);
    }
    vector <ll> v1(n+1);
    ll M=1;
    for(i=1;i<=n;i++) { M*=p1[i].second;      }
    for(i=1;i<=n;i++) { v1[i]=M/p1[i].second; }
    ll X,sum=0;
    ll a,b,x,y;
    for(i=1;i<=n;i++)
    {
        a=v1[i];
        b=p1[i].second;
        gcd(a,b,x,y);
        x=p1[i].first*v1[i]*ans;
        sum+=x%M;
    }
    return sum%M;
}
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x=0; y=1;
        return b;
    }
    ll x1,y1;
    ll d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    ans=(x+b)%b;
    return d;
}
void mm()
{
    cout<<"Best way to understand CHINESE REMAINDER THEOREM is by an example\n\n";
    cout<<" (2 * X) % 3 = 1  -eq1\n";
    cout<<" (4 * X) % 5 = 1  -eq2\n";
    cout<<" (5 * X) % 7 = 1  -eq3\n\n";
    cout<<"Find common value of x which satisfied all 3 equations\n\n";
    cout<<"Answer: X=89\n\n";
}
