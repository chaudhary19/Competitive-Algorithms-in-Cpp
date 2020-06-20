#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int n, m, u, v;
vector<int> graph[100005];
int visited[100005];
queue<int> Q;

void bfs(int start)
{
    Q.push(start);
    visited[start] = 1;

    while(!Q.empty())
    {
      int node = Q.front();
      Q.pop();

      // process the node

      for(int child : graph[node])
      {
        if(!visited[child])
            visited[child] = 1;
            Q.push(child);
      }

    }
}


int32_t main()
{
  	IOS
    cin>>n>>m;

    for(int i = 1; i<=m; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);

}
