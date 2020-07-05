#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int faces, throws, Sum;
int dp[1005][1005];

int solve(int Sum, int throws)
{
    if(throws == 0)
    {
        if(Sum == 0)
            return 1;
        else
            return 0;
    }

    if(Sum < 0) return 0;

    if(dp[Sum][throws] != -1) return dp[Sum][throws];

    int ans = 0;
    for(int i = 1; i<=faces; i++)
    {
        ans += solve(Sum - i, throws - 1);
    }

    return dp[Sum][throws] = ans;
}

int32_t main()
{
    cin>>faces>>throws>>Sum;

    memset(dp, -1, sizeof dp);
    int ans = solve(Sum, throws);
    cout<<ans<<endl;
}
