#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[50], n, i,loc,j,min,t;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		min = a[i]; loc = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				loc = j;
			}
		}
		
			t = a[i];
			a[i] = a[loc];
			a[loc] = t;
	}
	cout << "after sorting elements are\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}