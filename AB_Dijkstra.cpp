#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

const int MOD = 1e9 + 7;
const int INF = 1e15 + 7;

vector<pair<int, int>> graph[100005];
int dist[100005];
priority_queue<pair<int, int>> pq;      // max heap kinda
int visited[100005];

// complexity -> O(n + mlogm)
void dijkstra(int n, int m, int source)
{
    for(int i = 1; i<100005; i++) dist[i] = INF;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = 1;

        for(auto u : graph[node])
        {   
            int d, v;
            tie(d, v) = u;
            // int d = u.first;
            // int v = u.second;

            if(dist[node] + d < dist[v])
            {
                dist[v] = dist[node] + d;
                pq.push({-dist[v], v});
            }
        }
    }

}

int32_t main()
{
    IOS;

    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=m; i++)
    {
        int u, v, d;
        cin>>u>>v>>d;

        graph[u].pb({v, d});
        graph[v].pb({u, d});
    }

    dijkstra(n, m, 1);

}
