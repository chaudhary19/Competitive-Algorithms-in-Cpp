#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int K = 25;

int n;
vector<int> tree[100005];
int sparse[100005][K + 1];
int parent[100005];

void preCompute()
{
    for(int j = 0; j<K; j++)
    {
        for(int i = 1; i<=n; i++)
        {
            if(j == 0)
                sparse[i][j] = parent[i];
            else
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}

int bin_pow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
            ans *= a;
        b /= 2;
        a *= a;
    }
    return ans;
}

int query(int node, int dist)
{
    while(dist > 0)
    {
        int p = (int)log2(dist);
        node = sparse[node][p];
        dist -= bin_pow(2, p);
    }
    return node;
}

int32_t main()
{   
    IOS

    cin>>n;
    memset(sparse, 0, sizeof sparse);

    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;

        tree[u].push_back(v);
        parent[v] = u; 
    }

    preCompute();

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<5; j++)
        {
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }

    int q;
    cin>>q;

    while(q--)
    {
        int node, dist;
        cin>>node>>dist;

        int ans = query(node, dist);
        cout<<"Kth ancestor of node "<<node<<" is "<<ans<<endl;
    }

}
