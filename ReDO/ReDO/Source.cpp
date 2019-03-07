#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
bool Expand(string &s1, string &s2)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '-' || isalnum(s1[i])) {
			if (s1[i] != '-')
				s2.push_back(s1[i]);
			else
			{
				if (s1[i - 1] < s1[i + 1])
				{
					for (char c = s1[i - 1] + 1; c < s1[i + 1]; c++)
						s2.push_back(c);
				}
				else
				{
					cout << s1[i - 1] << "-" << s1[i + 1] << " is not possible";
					return false;
				}
			}
		}
		else
		{
			cout << "Shorthand notation is inappropriate\n";
			return false;

		}

	}
	return true;
}


int main()
{
	string s1, s2;
	cout << "enter the shorthand notation";
	cin >> s1;
	bool result = Expand(s1, s2);
	if (result)
		cout << "Expanded string is " << s2;

	return 0;
}
