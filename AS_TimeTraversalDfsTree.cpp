#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int n;
vector<int> tree[100005];
vector<int> in;
bool visited[100005];

void dfs(int node)
{
    visited[node] = 1;
    in.push_back(node);

    for(int child: tree[node])
    {
        if(!visited[child])
            dfs(child);
    }
}

int32_t main()
{   
    cin>>n;
    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int source;
    cin>>source;

    dfs(source);

    cout<<"Here's the dfs time traversal of tree : ";

    for(int node: in)
    {
        cout<<node<<" ";
    }
}


/*
9
1 2
1 3
1 4
1 5
2 6
4 7
4 8
4 9

Here's the dfs time traversal of tree: 1 2 6 3 4 7 8 9 5

*/
