#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

const int MOD = 1e9 + 7;

vi graph[100005];
int visited[100005];
int color[100005];

bool is_bipartite(int n)      // n is the size of graph (n - 1) nodes available in graph
{
    memset(color, -1, sizeof color);
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == -1)       // did not gave color this node
        {
            color[i] = 0;
            stack<int> S;
            S.push(i);

            while(!S.empty())
            {
                int parent = S.top();
                S.pop();

                for(int child : graph[parent])
                {
                    if(color[child] == -1)
                    {
                        color[child] = 1 ^ color[parent];
                        S.push(child);
                    }
                    else if(color[child] == color[parent])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

int32_t main()
{
    IOS;
}
