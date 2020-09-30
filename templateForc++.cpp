#include<bits/stdc++.h>
#include<fstream>
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define prime 1000000007
#define pb push_back
#define mp make_pair
#define fo(i,a,b) for (int i = a; i <b; i++)
#define forn(i,a,b) for (int i = a; i <=b; i++)
#define num 1000000000
#define ALL(v) v.begin(), v.end()
#define INF INT_MAX
typedef long long ll;
#define TO ll t;cin>>t;while(TO--)
using namespace std;

//For getting SUM
ll getSum(ll n) 
{  
   ll sum = 0; 
   while (n != 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
}


ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     
    x = x % p;   
             
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
        if (y & 1)  
        res = (res*x) % p;
        
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 

string getString(char x) 
{ 
    string s(1, x);   
    return s;    
}

int main()
 { 
   IO
   #ifndef ONLINE_JUDGE  
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   freopen("log.txt", "w", stderr);
   #endif
   //WRITE YOUR CODE HERE
   return 0;
 }
