#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int INF = 1e18;
const int N = 105;

// Maximum path Sum in a 2D Grid

int n, m;
int mat[N][N];

int32_t main()
{
    IOS
    cin>>n>>m;
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin>>mat[i][j];
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            mat[i][j] += max(mat[i-1][j], mat[i][j-1]);  
        }
    }

    cout<<"Maximum Path Sum is "<<mat[n][m]<<endl;
}


