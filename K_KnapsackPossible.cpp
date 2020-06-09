#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 105;

// knapsack problem 
// given Weights and X
// find from 1 to X, how many are possible
// using given weights atmost once

int n, X;
int weight[101];
bool dp[101][101];

int32_t main()
{
    IOS
    cin>>n>>X;
    for(int i = 1; i<=n; i++)
    {
        cin>>weight[i];
    }
    dp[0][0] = true;
    for(int k = 1; k<=n; k++)
    {
        for(int i = 0; i<=X; i++)
        {
            if(i-weight[k] >= 0)
                dp[k][i] |= dp[k-1][i-weight[k]];
            dp[k][i] |= dp[k-1][i];
        }
    }

    for(int i = 0; i<=X; i++)
    {
        if(dp[n][i])
            cout<<i<<" "<<"Possible"<<endl;
        else cout<<i<<" "<<"Not possible"<<endl;
    }
    
}


