#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"

void TowerOfHanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        cout<<"move "<<1<<" from "<<A<<" to "<<C<<endl;
        return;
    }
    TowerOfHanoi(n - 1, A, C, B);
    cout<<"move "<<n<<" from "<<A<<" to "<<C<<endl;
    TowerOfHanoi(n - 1, B, A, C);
}

int32_t main()
{
    IOS
    int n = 3;
    TowerOfHanoi(n, 'A', 'B', 'C');    
}

/*
Output: 
move 1 from A to C
move 2 from A to B
move 1 from C to B
move 3 from A to C
move 1 from B to A
move 2 from B to C
move 1 from A to C

*/
