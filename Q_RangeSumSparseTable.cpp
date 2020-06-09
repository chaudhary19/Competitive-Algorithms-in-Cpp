#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MAXN = 1005;
const int K = 25;

int n, q, l, r;
int Arr[MAXN], st[MAXN][K + 1];

// Range Query Sum - using Sparse table

void precompute()
{
    for(int i = 0; i<n; i++)
    {
        st[i][0] = Arr[i];
    }

    for(int j = 1; j<=K; j++)
    {
        for(int i = 0; (i + (1<<j)) <= n; i++)
        {
            st[i][j] = st[i][j-1] + st[i + (1<<(j-1))][j-1];
        }
    }
}

int query(int left, int right)         // ( 0 based indexing)
{
    int ans = 0;
    for(int j = K; j>=0; j--)
    {
        if((1<<j) <= (right - left + 1))
        {
            ans += st[left][j];
            left += (1<<j);
        }
    }
    return ans;
}

int32_t main()
{
    IOS
    cin>>n>>q;       // size of the array
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    precompute();

    while(q--)
    {
        cin>>l>>r;
        int ans = query(l, r);
        cout<<ans<<endl;
    }

}
