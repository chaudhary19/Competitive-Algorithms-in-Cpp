#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

// Josephus problem :)

int Jos(int n, int k)
{
    if(n == 1) return 0;
    return (Jos(n-1, k)+k)%n;
}

int32_t main()
{
    IOS
    int n, k;
    cin>>n>>k;

    int ans = Jos(n, k);
    cout<<"Last man standing is : "<<ans+1<<endl;
    
}
