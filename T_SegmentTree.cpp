#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int MAXN = 1005;

int n;
int Stree[2 * MAXN];

void build()
{
    for(int i = n-1; i>0; i--)
    {
        Stree[i] = Stree[2*i] + Stree[2*i + 1];
    }
}

void modify(int index, int value)           // 0 - based indexing Segment Tree
{
    index += n;
    while(index>0)
    {
        Stree[index] += value;
        index >>= 1;
    }
}

int query(int left, int right)          // calculates for [left, right)  - be careful for this
{
    left += n;
    right += n;

    int ans = 0;
    while(left < right)
    {
        if(left&1)
        {
            ans += Stree[left];
            left++;
        }
        if(right&1)
        {
            right--;
            ans += Stree[right];
        }
        left >>= 1;
        right >>= 1;
    }

    return ans;
}

int32_t main()
{
    IOS
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>Stree[n + i];
    }

    build();
    modify(0, 1);      // 0 based indexing - add 1 to 0th index
    cout<<query(3, 6)<<endl;

}   
