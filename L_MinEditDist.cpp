#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 105;

// Edit distance

string A, B;
int n, m;

int dp[N][N];

int32_t main()
{
    IOS
    cin>>n>>m;      // length of string A and B
    cin>>A>>B;

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else
            {
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + (A[i-1] == B[j-1])));
            }
            
        }
    }

    cout<<"Minimum Edit Distance "<<dp[n][m]<<endl;
    
}
