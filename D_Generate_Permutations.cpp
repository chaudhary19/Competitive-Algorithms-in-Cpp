#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int n;
int Arr[51], chosen[51];
vector<int> perm;

void PrintPermutation()     // print the permutation
{
    for(int i : perm)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void search()
{
    if(perm.size() == n)
    {
        PrintPermutation();
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(chosen[i]) continue;
            chosen[i] = 1;
            perm.push_back(Arr[i]);

            search();
            chosen[i] = 0;
            perm.pop_back();
        }
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

    search();     // pass the initial index
}


