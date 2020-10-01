#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;

int n;
int Arr[101], dp[101];

int32_t main()
{
    IOS
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }
    int maxi = 0;
    for(int k = 0; k<n; k++)
    {
        dp[k] = 1;
        for(int i = 0; i<k; i++)
        {
            if(Arr[i] < Arr[k])
            dp[k] = max(dp[k], dp[i] + 1);
        }
        maxi = max(maxi, dp[k]);
    }

    cout<<"Length of Longest Increasing Subsequence is "<<maxi<<endl;
}

// Time Complexity : O(n^2)
// space complexity : O(n)
