#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

// Flood Fill Algorithm: Flood Fill (x,y) index from prevColor to newColor
#define M 6 
#define N 6 

void floodFill(int image[M][N], int x, int y, int prevColor, int newColor) 
{ 
	if (x < 0 || x >= M || y < 0 || y >= N) 
		return; 
	if (image[x][y] != prevColor) 
		return; 
	if (image[x][y] == newColor) 
		return; 
	image[x][y] = newColor; 
	floodFill(image, x+1, y, prevColor, newColor); 
	floodFill(image, x-1, y, prevColor, newColor); 
	floodFill(image, x, y+1, prevColor, newColor); 
	floodFill(image, x, y-1, prevColor, newColor); 
} 

void floodFill(int image[M][N], int x, int y, int newColor) 
{ 
	int prevColor = image[x][y]; 
	floodFill(image, x, y, prevColor, newColor); 
} 

int32_t main()
{
    IOS
    int image[M][N] = { {1, 1, 1, 2, 1, 2}, 
                        {1, 1, 1, 0, 1, 1}, 
                        {1, 1, 0, 2, 1, 0}, 
                        {1, 1, 2, 1, 1, 0}, 
                        {1, 1, 1, 2, 1, 1}, 
                        {2, 1, 1, 0, 0, 1},  
		      }; 
    int x = 1, y = 1, newColor = 3; 
    floodFill(image, x, y, newColor); 
    cout << "After FloodFill: "<<endl; 
    for (int i=0; i<M; i++) 
    { 
      for (int j=0; j<N; j++) 
      {
        cout << image[i][j] << " "; 
      }
      cout << endl; 
    } 
}
