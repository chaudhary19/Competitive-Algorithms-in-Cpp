#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"


/*

Subtree Queries:

1) Update the value of the Node  ---- 1 value node
2) Calculate the Sum of values of Subtree of a Node.  ---- 2 node

*/

const int MAXN = 100005;

int n;
vector<int> tree[MAXN], inTime;
int visited[MAXN], Hash[MAXN], size[MAXN], value[MAXN], bit[MAXN];

void dfs(int node, int parent)
{
    visited[node] = 1;
    inTime.push_back(node);

    for(int child: tree[node])
    {
        if(child != parent and !visited[child])
            dfs(child, node);
    } 
}

void DFS(int node, int parent)
{
    visited[node] = 1;
    size[Hash[node]] = 1;

    for(int child: tree[node])
    {
        if(child != parent and !visited[child])
        {
            DFS(child, node);
            size[Hash[node]] += size[Hash[child]];
        }
    }
}

void update(int idx, int v)
{
    while(idx <= MAXN)
    {
        bit[idx] += v;
        idx += idx&-idx;
    }
}

int prefix(int idx)
{   
    int ans = 0;
    while(idx >= 1)
    {
        ans += bit[idx];
        idx -= idx&-idx;
    }
    return ans;
}

int Sum(int left, int right)
{
    return prefix(right) - prefix(left-1);
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

    inTime.push_back(0);

    dfs(1, -1);

    for(int i = 1; i<=n; i++)
    {
        Hash[inTime[i]] = i;
    }

    memset(visited, 0, sizeof visited);

    DFS(1, -1);

    for(int i = 1; i<=n; i++)
    {
        int x;
        cin>>x;
        value[Hash[i]] = x;
        update(Hash[i], x);
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<inTime[i]<<" ";
    // }
    // cout<<endl;

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<size[i]<<" ";
    // }
    // cout<<endl;

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<value[i]<<" ";
    // }
    // cout<<endl;

    int q;
    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if(type == 1)
        {
            int n, v;
            cin>>n>>v;

            n = Hash[n];
            int add = v - value[n];
            update(n, add);
            value[n] += add;
        }
        else
        {
            int n;
            cin>>n;
            n = Hash[n];
            int r = n + size[n] - 1;
            int l = n;
            int ans = Sum(l, r);
            cout<<ans<<endl;
        }
        
    }


}


/*

TestCase: 

9
1 2
1 3
1 4
1 5
2 6
4 7
4 8
4 9
2 3 5 3 1 4 4 3 1
10
2 4
11
2 1
26
1 4 7
2 4
15
2 7
4
2 2
7
2 5
1
2 1
30
1 5 0
2 1
29

*/
