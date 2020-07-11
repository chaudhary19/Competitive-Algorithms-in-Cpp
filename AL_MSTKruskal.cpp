#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int size[100005];
int link[100005];
int n, m;
vector<tuple<int, int, int>> edge;

int find(int x)
{
    while(x != link[x])
    {
        x = link[x];
    }
    return x;
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int32_t main()
{   
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
        link[i] = i;

    for(int i = 1; i<=n; i++)
        size[i] = 1;

    for(int i = 1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edge.push_back({w, u, v});
    }

    sort(edge.begin(), edge.end());
    int cost = 0;

    for(auto e : edge)
    {
        int w, u, v;
        tie(w, u, v) = e;

        if(!same(u, v))
        {
            unite(u, v);
            cost += w;
        }
    }

    cout<<"Total cost to build Minimum Spanning Tree: "<<cost<<endl;

}

/*

6 8
1 2 3
1 5 5
2 5 6
2 3 5
5 6 2
3 6 3
3 4 9
6 4 7
Total cost to build Minimum Spanning Tree: 20

*/
