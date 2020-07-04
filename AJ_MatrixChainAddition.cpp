#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int Arr[1005];
int dp[105][105];
int prefix[1005];

int solve(int i, int j)
{
    if(i >= j) return 0;
    int ans = INT_MAX;
    int Sum = prefix[j] - prefix[i - 1];

    if(dp[i][j] != -1) return dp[i][j];

    for(int k = i; k < j; k++)
    {
        int temp = solve(i, k) + solve(k+1, j) + Sum;
        ans = min(ans, temp);
    }

    return dp[i][j] = ans;
}

int32_t main()
{
    int n;
    cin>>n;

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++)
    {
        cin>>Arr[i];
        prefix[i] = Arr[i];
    }
    for(int i = 2; i<=n; i++){
        prefix[i] += prefix[i-1];
    }

    int ans = solve(1, n);
    cout<<ans<<endl;
}
