#include<iostream>
using namespace std;
class matrix {
	int m[3][3];

public:
	matrix()
	{

	}
	matrix(int x)
	{
		cout << "enter matrix values";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cin >> m[i][j];
		}
	}
	friend matrix mat_mul(matrix, matrix);
	void display()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << m[i][j] << " ";
			cout << endl;
		}
	}


};
matrix mat_mul(matrix m1, matrix m2)
{
	matrix m3;
	int i, j, k;


	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			m3.m[i][j] = 0;
		}
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			for (k = 0; k<3; ++k)
			{
				m3.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return m3;

}


void main()
{
	matrix m1(1), m2(1);
	matrix res= mat_mul(m1, m2);
	res.display();
	getchar();
}
