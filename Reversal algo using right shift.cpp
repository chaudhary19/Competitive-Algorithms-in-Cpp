#include <bits/stdc++.h> 

void reverseArray(int arr[], int start, 
							int end) 
{ 
	while (start < end) 
	{ 
		std::swap(arr[start], arr[end]); 
		start++; 
		end--; 
	} 
} 

void rightRotate(int arr[], int d, int n) 
{ 
	reverseArray(arr, 0, n-1); 
	reverseArray(arr, 0, d-1); 
	reverseArray(arr, d, n-1); 
} 

void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		std::cout << arr[i] << " "; 
}