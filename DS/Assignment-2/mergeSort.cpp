#include<stdio.h>
#include<iostream>
void merge(int a[], int i1, int mid, int high)
{
	int i, k,l=0;
	i = i1;
	k = mid + 1;
	int *b;
	b= new int[high - i1 + 1];
	while (i <= mid && k <= high)
	{
		if (a[i] < a[k])
			b[l++] = a[i++];
		else
			b[l++] = a[k++];
	}
	while (i <= mid)
		b[l++] = a[i++];
	while (k <= high)
		b[l++] = a[k++];
	l = 0;
	for (i = i1; i <= high; i++)
		a[i] = b[l++];
}
void mergeSort(int a[], int i, int n)
{
	if (i < n)
	{
		int mid;
		mid = (i + n) / 2;
		mergeSort(a, i, mid);
		mergeSort(a, mid + 1, n);
		merge(a, i, mid, n);
	}
}
using namespace std;
int main()
{
	int a[50], n, i, loc, j, min, t;
	cout << "enter n\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	mergeSort(a, 0, n - 1);
	cout << "after sorting elements are\n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}