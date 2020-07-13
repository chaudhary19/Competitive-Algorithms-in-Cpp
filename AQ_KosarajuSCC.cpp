#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
   
// Kosaraju's Algo for Strongly connected components in Directed Graph

const int N = 100005;

int n, m, grp = 0;
vector<int> graph[N], revgraph[N], todo;
int comp[N], sz[N];
bool visited[N];

void AddEdge(int from, int to)
{
    graph[from].push_back(to);
    revgraph[to].push_back(from);
}

void dfs(int node)
{
    visited[node] = 1;
    for(int &child: graph[node])
    {
        if(!visited[child])
            dfs(child);
    }
    todo.push_back(node);
}

void dfs2(int node, int val)
{
    comp[node] = val;
    sz[val]++;

    for(int &child: revgraph[node])
    {
        if(comp[child] == -1)
            dfs2(child, val);
    }
    
}

int32_t main()
{
    cin>>n>>m;
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        AddEdge(u, v);
    }

    memset(comp, -1, sizeof comp);

    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    reverse(todo.begin(), todo.end());

    for(int &node: todo)
    {
        if(comp[node] == -1)
        {
            dfs2(node, ++grp);
        }
    }

}
