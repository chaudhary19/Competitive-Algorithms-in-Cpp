#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int n, m, u, v;
vector<int> graph[100005];
int visited[100005];
int flag = 0;

// check whether cycle is present in Undirected graph or not using dfs

void check_cycle(int node, int parent)
{
  visited[node] = 1;

  for(int child : graph[node])
  {
    if(child == parent) continue;
    if(!visited[child]) check_cycle(child, node);
    if(visited[child])
    {
       flag = 1;
       break;
    }
  }
}


int32_t main()
{
  cin>>n>>m;
  for(int i = 1; i<=m; i++)
  {
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  check_cycle(1, -1);
  if(flag) cout<<"Cycle is present in Given Undirected Graph"<<endl;
  else cout<<"Cycle is not presemt in Given Undirected Graph"<<endl;

}
