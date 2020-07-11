#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

// Successor Graph --> A graph in which each node has outdegree = 1
// find cycle, first node of cycle and length of cycle

int succ[100005];

int32_t main()
{   
    int a = succ[1];
    int b = succ[succ[1]];

    while(a != b)
    {
        a = succ[a];
        b = succ[succ[b]];
    }

    // now we have find that there is cycle present in successor graph
    // now we will find the first node where cycle starts

    a = 1;
    while(a != b)
    {
        a = succ[a];
        b = succ[b];
    }

    cout<<"The first node where cycle begins is : "<<a<<endl;
    // now lets calculate the length of cycle

    b = succ[a];
    int length = 1;
    while(a != b)
    {
        b = succ[b];
        length++;
    }

    cout<<"length of the cycle is : "<<length<<endl;

}


