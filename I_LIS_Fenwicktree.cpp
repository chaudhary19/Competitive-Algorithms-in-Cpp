#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 1001;

int n;
int Arr[1001], BIT[1001];            // Array to store numbers

void coordinate_compression()         // to reduce the values 
{
    set<int> s;
    for(int i = 0; i<n; i++)
    {
        s.insert(Arr[i]);
    }
    int index = 0;
    map<int, int> mp;

    for(auto it : s)
    {
        index++;
        mp[it] = index;
    }
    for(int i = 0; i<n; i++)
    {
        Arr[i] = mp[Arr[i]];
    }
}

// quey for Fenwick tree
int query(int index)
{
    int ans = 0;
    while(index > 0)
    {
        ans = max(ans, BIT[index]);
        index -= index & (-index);
    }
    return ans;
}

// update in Fenwick Tree
void update(int index)
{
    int x = query(index - 1);
    int value = x + 1;

    while(index<=n)
    {
        BIT[index] = max(BIT[index], value);
        index += index & (-index);
    }
}

int32_t main()
{
    IOS
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }
    coordinate_compression();   // helpful in dealing with large numbers
    
    for(int i = 0; i<n; i++)
    {
        update(Arr[i]);
    }
    int ans = query(n);
    cout<<"Length of the longest increasing Subsequence is "<<ans<<endl;
}


