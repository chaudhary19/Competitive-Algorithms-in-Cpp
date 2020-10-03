#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

// Dutch National Flag Algorithm
int DNF(int A[], int end)
{
	int start = 0, mid = 0;
	int pivot = 1;
	while (mid <= end)
	{
		if (A[mid] < pivot)		 
		{
      int temp=A[start];
      A[start]=A[mid];
      A[mid]=temp;
			++start, ++mid;
		}
		else if (A[mid] > pivot)	
		{
			int temp=A[mid];
      A[mid]=A[end];
      A[end]=temp;
			--end;
		}
		else						 
		{
			++mid;
		}
	}
}
 
int32_t main()
{
    IOS
    int A[] = { 0, 0, 1, 2, 2, 2, 1, 1, 0, 1, 2, 0, 1 };
    int n = sizeof(A)/sizeof(A[0]);
    DNF(A, n - 1);
    for (int i = 0 ; i < n; i++) {
      cout<< A[i] <<" ";
    }
}
