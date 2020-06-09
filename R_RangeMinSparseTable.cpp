#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MAXN = 1005;
const int K = 25;

int n, q, l, r;
int Arr[MAXN], st[MAXN][K + 1], Log[MAXN + 1];

// Range Min/Max/GCD queries in O(1)

void precompute()
{   
    // also precalculate the floor log table
    Log[1] = 0;
    for(int i = 2; i<=MAXN; i++)
    {
        Log[i] = Log[i/2] + 1;
    }

    for(int i = 0; i<n; i++)
    {
        st[i][0] = Arr[i];
    }

    for(int j = 1; j<=K; j++)
    {
        for(int i = 0; (i + (1<<j)) <= n; i++)
        {
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
}

int query(int left, int right)         // ( 0 based indexing)
{
    int j = Log[right - left + 1];
    int minimum = min(st[left][j], st[right - (1<<j) + 1][j]);
    return minimum;
}

int32_t main()
{
    IOS
    cin>>n>>q;       // size of the array
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    precompute();             // O(nlogn)

    while(q--)
    {
        cin>>l>>r;
        int ans = query(l, r);          // O(1)
        cout<<ans<<endl;
    }

}
