#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MAXN = 1005;

// FenWick Tree - Binary Indexed tree (1 based indexing)

int n, q;
int Arr[MAXN], BIT[MAXN];

void update(int index, int value)
{
    while(index<=n)
    {
        BIT[index] += value;
        index += index & -index;
    }
}

int query(int index)                   // sum(1, index)
{
    int ans = 0;
    while(index>=1)
    {
        ans += BIT[index];
        index -= index & -index;
    }
    return ans;
}

int32_t main()
{
    IOS
    cin>>n>>q;
    for(int i = 1; i<=n; i++)
    {
        cin>>Arr[i];
    }

    for(int i = 1; i<=n; i++)
    {
        update(i, Arr[i]);
    }

    while(q--)
    {
        int left, right;
        cin>>left>>right;

        int ans = query(right) - query(left - 1);
        cout<<ans<<endl;
    }

    
}
