#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

// Successor Graph --> A graph in which each node has outdegree = 1

int succ[100005];
vector<int> graph[100005];
int n, m, q;
const int K = 25;
int sparse[100005][K + 1];

void preCompute()
{
    for(int j = 0; j<=K; j++)
    {
        for(int i = 1; i<=n; i++)
        {
            if(j == 0)
            {
                sparse[i][j] = succ[i];
            }
            else
            {
                sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
            }          
        }
    }
}

int bin_pow(int a, int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a);
		b/=2;
		a=(a*a);
	}
	return ans;
}

int query(int node, int dist)
{
    while(dist>0)
    {
        int p = (int)log2(dist);
        node = sparse[node][p];
        dist -= bin_pow(2, p);
    }
    return node;
}

int32_t main()
{   
    cin>>n>>m;
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        succ[u] = v;
    }
    memset(sparse, 0, sizeof sparse);
    preCompute();


    // for(int i = 1; i<=n; i++)
    // {
    //     for(int j = 0; j<=K; j++)
    //     {
    //         cout<<sparse[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    cin>>q;    // queries
    while(q--)
    {
        int node, dist;
        cin>>node>>dist;

        int ans = query(node, dist);
        cout<<ans<<" is present at "<<dist<<" dist from node "<<node<<endl;
    }
}


/*
9 9
1 3
9 3
3 7
7 9
2 5
5 2
6 2
4 6
8 6
10
1 1
3 is present at 1 dist from node 1
1 2
7 is present at 2 dist from node 1
1 3
9 is present at 3 dist from node 1
1 4
3 is present at 4 dist from node 1
1 5
7 is present at 5 dist from node 1
6 4
5 is present at 4 dist from node 6
4 10
2 is present at 10 dist from node 4
8 5
5 is present at 5 dist from node 8
9 9
9 is present at 9 dist from node 9
5 7
2 is present at 7 dist from node 5
*/
