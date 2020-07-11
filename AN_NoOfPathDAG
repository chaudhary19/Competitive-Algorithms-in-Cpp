#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio; cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
#define MAXN 100005

vector<int> tree[MAXN];
int source, destination, n, m;
int dp[MAXN];

int solve(int node)
{
    if(node == destination) return 1;

    if(dp[node] != -1) return dp[node];

    int ans = 0;
    for(auto child : tree[node])
    {
        ans += solve(child);
    }
    return dp[node] = ans;
}

int32_t main()
{
    cin>>n>>m;   // no of nodes in DAG 
    for(int i = 1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        tree[x].push_back(y);           // child of x is y
    }

    cin>>source>>destination;

    memset(dp, -1, sizeof dp);
    int ans = solve(source);

    cout<<ans<<endl;

}

// returns no. of unique path from source to destination in a Directed Acyclic Graph
