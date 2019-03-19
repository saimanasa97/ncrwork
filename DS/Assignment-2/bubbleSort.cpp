#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[50],n,i,j,t,f=0;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		f = 0;
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				f++;
			}
		}
		if (f == 0)
			break;
	}
	cout << "after sorting elements are\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}