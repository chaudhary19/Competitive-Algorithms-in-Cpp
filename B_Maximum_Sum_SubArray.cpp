#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int32_t main()
{
    IOS;
    int n;     // size of the array;
    cin>>n;

    int Arr[n+1];
    for(int i = 1; i<=n; i++)
    {
        cin>>Arr[i];
    }

    int best = 0, curr = 0;
    for(int i = 1; i<=n; i++)
    {
        curr = max(curr + Arr[i], Arr[i]);
        best = max(best, curr);
    }

    cout<<"Maximum Sum Sub-Array is "<<best<<endl;

}


// time complexit : O(n)
// space Complexity : O(1) ** no extra space used
