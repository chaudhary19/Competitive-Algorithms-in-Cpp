#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define endl "\n"
#define pb push_back

const int INF = 1e15 + 7;
const int MOD = 1e9 + 7;

vector<tuple<int, int, int>> edges;
int dist[100005];
int pred[100005];

bool bellman_ford(int n, int m, int source)
{
    for(int i = 0; i<100005; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;
    for(int i = 0; i<n; i++)
    {
        for(auto e : edges)
        {
            int u, v, d;
            tie(u, v, d) = e;
            if(dist[u] + d < dist[v])
            {
                dist[v] = dist[u] + d;
                pred[v] = u;
            }
        }
    }

    // to check for negative cycle
    for(auto e : edges)
    {
        int u, v, d;
        tie(u, v, d) = e;
        if(dist[u] + d < dist[v]) return true;
    }

    return false;

}

int32_t main()
{
    IOS;
    int n, m;    // nodes and edges
    cin>>n>>m;

    for(int i = 1; i<=m; i++)
    {
        int u, v, d;
        cin>>u>>v>>d;

        edges.pb({u, v, d});
    }

    bool ans = bellman_ford(n, m, 1);
    if(ans) cout<<"Graph has negative cycle"<<endl;
    else cout<<"Graph has no negative cycle"<<endl;

}
