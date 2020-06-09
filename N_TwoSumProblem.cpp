#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 105;

// Two Sum problem
int n, X;
int Arr[N];

bool two_sum()
{
    sort(Arr, Arr+n);
    int i = 0, j = n-1;

    while(i < j)
    {
        int p = Arr[i] + Arr[j];
        if(p == X) return true;
        else if(p < X) i++;
        else j--;
    }
    return false;
}

int32_t main()
{
    IOS
    cin>>n>>X;
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    if(two_sum())
    cout<<X<<" is possible using two elements"<<endl;
    else cout<<X<<" is not possible using two elements"<<endl;
}


