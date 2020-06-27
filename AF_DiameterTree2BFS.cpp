#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

int n, u, v;
vector<int> tree[100005];
int diameter[100005];

int bfs(int source)
{
    int visited[100005];
    for(int i = 0; i<100005; i++)
    {
        diameter[i] = 0;
        visited[i] = 0;
    }

    queue<int> q;
    q.push(source);
    visited[source] = 1;

    int maxDia = 0;
    int ans = source;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int child : tree[node])
        {
            if(!visited[child])
            {
                visited[child] = 1;
                diameter[child] = diameter[node] + 1;

                if(diameter[child] > maxDia)
                {
                    maxDia = diameter[child];
                    ans = child;
                }

                q.push(child);
            }
        }
    }

    return ans;

}

int TwoBfs()
{
    int b = bfs(1);
    int c = bfs(b);
    return diameter[c];
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

    int ans = TwoBfs();
    cout<<"Diameter of the tree is "<<ans<<endl;

}


// Example test case for better understanding

// 7
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 4 7

// Diameter of the tree is 4
