#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int n, m;
vector<int> graph[100005];
vector<int> topoSort;
int visited[100005];

int checkloop(int node)
{
    if(visited[node] == 1) return 1;      // under processing node
    if(visited[node] == 2) return 0;      // already processed

    visited[node] = 1;

    for(int child : graph[node])
    {
        if(checkloop(child))
            return 1;
    }
    visited[node] = 2;
    topoSort.push_back(node);
    return 0;

}

int findloop()
{
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i] && checkloop(i))
            return 1;
    }
    return 0;
}

int32_t main()
{   
    cin>>n>>m;
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    memset(visited, 0, sizeof visited);

    if(!findloop())
    {
        cout<<"Given Graph is Directed Acyclic Graph"<<endl;
        cout<<"Topological Sort: "<<endl;
        reverse(topoSort.begin(), topoSort.end());
        for(int i : topoSort)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Given Graph has cycle so Topological sort does not exist"<<endl;
    }
}


/*

vis[i] = 0 ---> node not processed yet
vis[i] = 1 ---> node is under processing
vis[i] = 2 ---> node already processed

6 7
1 2
2 3
4 1
4 5
5 2
5 3
3 6
Given Graph is Directed Acyclic Graph
Topological Sort:
4 5 1 2 3 6

*/
