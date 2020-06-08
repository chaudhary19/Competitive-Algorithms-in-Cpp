#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;

int n, need;
int coins[105], dp[105];

int solve(int x)
{
    if(x < 0) return INF;
    if(x == 0) return 0;

    if(dp[x] != -1) return dp[x];

    int ans = INF;
    for(int i = 0; i<n; i++)
    {
        ans = min(ans, 1 + solve(x - coins[i]));
    }

    return dp[x] = ans;
}

int32_t main()
{
    IOS
    cin>>n>>need;
    for(int i = 0; i<n; i++)
    {
        cin>>coins[i];
    }

    memset(dp, -1, sizeof dp);    // size of dp >= need

    int ans = solve(need);
    cout<<ans<<endl;
}


