#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;

int n, m, u, v, d;
bool inqueue[100005];
vector<pair<int, int>> graph[100005];
int dist[100005], cnt[100005];

bool SPFA(int source)
{
  queue<int> q;
  for(int i = 1; i<100005; i++)
  {
    dist[i] = INF;
    cnt[i] = 0;
  }

  dist[source] = 0;
  q.push(source);
  inqueue[source] = true;

  while(!q.empty())
  {
    int node = q.front();
    q.pop();

    inqueue[node] = false;

    for(auto child : graph[node])
    {
      int to, weight;
      tie(to, weight) = child;

      if(dist[node] + weight < dist[to])
      {
        dist[to] = dist[node] + weight;
        dist[to] = max(dist[to], -INF);

        if(!inqueue[to])
        {
          inqueue[to] = true;
          q.push(to);
          cnt[to]++;
          if(cnt[to] > n) return true;

        }
      }
    }
  }

  return false;
}


int32_t main()
{
    cin>>n>>m;
    for(int i = 1; i<=m; i++)
    {
      cin>>u>>v>>d;
      graph[u].push_back({v, d});
    }

    if(SPFA(1)) cout<<"Negative Cycle Present"<<endl;
    else cout<<"Negative cycle not present"<<endl;

}

// worst case time complexity is equal to Bellman ford
