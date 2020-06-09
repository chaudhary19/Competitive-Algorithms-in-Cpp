#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 1005;

int n;
int Arr[N];

int32_t main()
{
    IOS
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    vector<int> ans(n, -1);
    stack<int> s;

    for(int i = 0; i<n; i++)
    {
        while(!s.empty() && Arr[s.top()] > Arr[i])
        {
            int index = s.top();
            s.pop();

            ans[index] = Arr[i];
        }

        s.push(i);
    }

    for(int it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}


