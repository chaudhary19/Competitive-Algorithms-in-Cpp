#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int n, m, u, v;
int size[100005];
vector<int> tree[100005];

void dfs(int node, int parent)
{
    size[node] = 1;
    for(int child : tree[node])
    {
        if(child == parent) continue;
        dfs(child, node);
        size[node] += size[child];
    }
}

int32_t main()
{
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }   

    // count of size of each subtree using dfs

    dfs(1, -1);

    
}
