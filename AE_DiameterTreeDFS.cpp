#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int n, m, u, v;
vector<int> tree[100005];

int toLeaf[100005];
int maxLength[100005];

void dfs(int node, int parent)
{
    toLeaf[node] = 0;
    maxLength[node] = 0;
    int first_max = 0;
    int sec_max = 0;

    for(int child : tree[node])
    {
        if(child == parent) continue;
        dfs(child, node);

        toLeaf[node] = max(toLeaf[child] + 1, toLeaf[node]);
        if(toLeaf[child] + 1 > first_max)
        {
            sec_max = first_max;
            first_max = toLeaf[child] + 1;
        }
        else if(toLeaf[child] + 1 > sec_max)
        {
            sec_max = toLeaf[child] + 1;
        }
    }
    maxLength[node] = first_max + sec_max;
}

int32_t main()
{
    cin>>n;
    for(int i = 1; i<n; i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }   

    dfs(1, -1);

    int maxDiameter = 0;
    int maxHeight = 0;

    int node1, node2;

    for(int i = 1; i<=n; i++)
    {
        if(toLeaf[i] > maxHeight)
        {
            maxHeight = toLeaf[i];
            node1 = i;
        }

        if(maxLength[i] > maxDiameter)
        {
            maxDiameter = maxLength[i];
            node2 = i;
        }
    }
    
    cout<<"node with max height is "<<node1<<" with height "<<maxHeight<<endl;
    cout<<"node which passes through max diameter is "<<node2<<" with diameter "<<maxDiameter<<endl; 

}


// Example test case for better understanding

// 7
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 4 7
// node with max height is 1 with height 2
// node which passes through max diameter is 1 with diameter 4
