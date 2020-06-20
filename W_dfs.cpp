#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int n, m;
int visited[100005];
vector<int> graph[100005];

void dfs(int node)
{
  if(visited[node]) return;
  visited[node] = 1;

  // process the node

  for(int child : graph[node])
  {
    dfs(child);
  }
}

int32_t main()
{
  	IOS
    cin>>n>>m;

    for(int i = 1; i<=m; i++)
    {
      int u, v;
      cin>>u>>v;

      graph[u].push_back(v);
      graph[v].push_back(u);

    }

    dfs(1);     // start dfs from node 1

}
