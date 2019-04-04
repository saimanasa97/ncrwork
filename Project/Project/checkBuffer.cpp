#include<string.h>
#include<ctype.h>
int isKeyword(char buffer[]) {

	char keywords[40][10] = { "main","int","long","float","char","double","short" ,"auto","break","case","const","continue","default",
							"do","else","enum","extern","for","goto","if","return","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","FILE","fopen","printf","fclose","strcat","strlen","strrev","strcpy" };

	char mcalloc[2][8] = { "malloc","calloc" };

	int i, flag = 0;
	for (i = 0; i < 2; i++)
		if (strcmp(mcalloc[i], buffer) == 0)
			return 5; //return 5 for malloc or calloc
	if (strcmp("free", buffer) == 0)
		return 6;
	for (i = 0; i < 33; ++i) 
	{
			if (strcmp(keywords[i], buffer) == 0)
			{
				return 1; //return 1 if keyword
		    }
	}
	if (isalpha(buffer[0]) || buffer[0] == '_')
		return 2; ///return 2 if identifier
	return flag;
}

int isOperator(char ch)
{
	int i;
	char operators[] = "+-*/%=<>";
	for (i = 0; i < 6; ++i) {

		if (ch == operators[i])
			return 1;

	}
	return 0;
}