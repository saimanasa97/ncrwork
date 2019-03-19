#include<stdio.h>
#include<iostream>
using namespace std;
void buildHeap(int a[],int i, int n)
{
	int temp = a[i];
	int c;
	while ((2 * i + 1) < n)
	{
		c = 2 * i + 1;
		if (c + 1 < n && a[c + 1] > a[c])
			c++;
		if (temp < a[c])
			a[i] = a[c];
		else
			break;
		i = c;
	}
	a[i] = temp;
}
int main()
{
	int a[50], n, i,t;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = n / 2 - 1; i >= 0; i--)
		buildHeap(a,i, n);
	cout << "After building heap\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	for (i = 0; i < n - 1; i++)
	{
		t = a[0];
		a[0] = a[n - i-1];
		a[n -1- i] = t;
		buildHeap(a, 0, n - i-1);
	}
	cout << "After Sorting\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}