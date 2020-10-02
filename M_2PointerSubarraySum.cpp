#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 105;

int n, X;
int Arr[N];

bool subArray_Sum()
{   

    int start = 0;
    int curr = 0;
    for(int i = 0; i<n; i++)
    {
        curr += Arr[i];
        while(curr > X)
        {
            curr -= Arr[start];
            start++;
        }
        if(curr == X) return true;
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

    if(subArray_Sum())
    cout<<X<<" sum is possible in Given array"<<endl;
    else
    cout<<X<<" sum is not possible in Given array"<<endl;
}


