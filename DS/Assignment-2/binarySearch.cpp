#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

	int a[50], n, i,low,high,mid,ele,f=0;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	cout << "enter serach ele";
	cin >> ele;
	low = 0; high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ele < a[mid])
			high = mid - 1;
		else if (ele > a[mid])
			low = mid + 1;
		else
		{
			cout << "element found at location : " << mid;
			f++;
			break;
		}
	}
	if (f == 0)
		cout << "element not found\n";
	return 0;
}