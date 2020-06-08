#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

int n;
int Arr[51];
vector<int> subset;

void PrintSubset()          // function to print the current subset
{
    for(int i : subset)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void search(int index)
{
    if(index == n)
    {
        PrintSubset();
    }
    else
    {
        search(index + 1);
        subset.push_back(Arr[index]);

        search(index + 1);
        subset.pop_back();
    }
    
}

void iterative()
{
    for(int b = 0; b < (1<<n); b++)
    {
        vector<int> subset;
        for(int i = 0; i<n; i++)
        {
            if(b&(1<<i))
                subset.push_back(Arr[i]);
        }
    }
}


int32_t main()
{
    IOS;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>Arr[i];
    }

    // recursive way to print All the subsets of Array
    search(0);    // pass the starting index of Array


    // iterative bitset way to print All the subsets
    iterative();
}


