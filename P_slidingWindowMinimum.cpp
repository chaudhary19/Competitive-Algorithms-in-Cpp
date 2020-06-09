#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 1005;

int n, k;
int Arr[N];

// find minimum in every window of size K

void slidingWindowMin()
{
    vector<int> ans;
    deque<int> DQ;

    for(int i = 0; i<k; i++)
    {
        while(!DQ.empty() && Arr[DQ.back()] >= Arr[i])
        {
            DQ.pop_back();
        }
        DQ.push_back(i);
    }

    for(int i = k; i<n; i++)
    {
        ans.push_back(Arr[DQ.front()]);
        while(!DQ.empty() && DQ.front() <= i - k)
            DQ.pop_front();

        while(!DQ.empty() && Arr[DQ.back()] >= Arr[i])
        {
            DQ.pop_back();
        } 

        DQ.push_back(i);
    }

    ans.push_back(Arr[DQ.front()]);

    for(int it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    IOS
    cin>>n>>k;     // array size and window size 
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    slidingWindowMin();

}
