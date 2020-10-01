#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;

int n;
int Arr[101];            // Array to store numbers

int32_t main()
{
    IOS
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    vector<int> dp(n+1, INF);   // dp vector to store values initialized with Infinity
    dp[0] = -INF;

    for(int i = 0; i<n; i++)
    {
        int j = upper_bound(dp.begin(), dp.end(), Arr[i]) - dp.begin();
        if(dp[j-1] < Arr[i] and Arr[i] < dp[j])
            dp[j] = Arr[i];
    }

    int ans = 0;
    for(int i = 0; i<=n; i++)
    {
        if(dp[i] < INF)
            ans = i;
    }

    cout<<"Length of Longest Increasing SubSequence is "<<ans<<endl;
}


