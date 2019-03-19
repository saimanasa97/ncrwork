#include<stdio.h>
#include<iostream>
using namespace std;
int partition(int a[], int i1, int n1)
{
	int pivot = a[i1];
	int i = i1 + 1, j = n1,t;
	while (1)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		else
			break;
	}
	t = a[j];
	a[j] = pivot;
	a[i1] = t;
	return j;

}
void Quicksort(int a[], int i, int n)
{
	if (i < n)
	{
		int j = partition(a, i, n);
		Quicksort(a, i, j - 1);
		Quicksort(a, j + 1, n);
	}
}
int main()
{
	int a[50], n, i;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	Quicksort(a, 0, n - 1);
	cout << "after sorting elements are\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}