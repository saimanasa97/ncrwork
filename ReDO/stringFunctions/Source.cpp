#include<stdio.h>
#pragma warning(disable:4996)
	void strcpy(char *s2, char *s1)
{
	while (*s1)
	{
		*s2 = *s1;
		*s2++;
		*s1++;
	}
	*s2 = '\0';
}
void strcat(char *s1, char *s2)
{
	while (*s1)
	{
		*s1++;
	}
	while (*s2)
	{
		*s1 = *s2;
		*s2++;
		*s1++;
	}
	*s1 = '\0';
}
int strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
	{
		if ((*s1) == '\0' && (*s2)=='\0')
			return 0;
	}
	
	return (*s1 - *s2);
	
}
void strrev(char *str)
{
	char *p, *q, ch;
	p = str; q = str;
	int l, i,length;
	for ( length = 0; str[length] != '\0'; ++length);

	for (i = 0; i < length - 1; i++)
		q++;
	for (i = 0; i < length / 2; i++)
	{
		ch = *p;
		*p = *q;
		*q = ch;
		p++;
		q--;
	}
}
int main()
{
	char s[50], s2[50];
	int choice, res;
	printf("enter string\n");
	scanf("%[^\t\n]s", s); //input string
	printf("enter choice 1.Reverse 2.Copy 3.Concatenate 4.Compare\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:strrev(s); printf("%s ", s);
		break;
	case 2:strcpy(s2, s); printf("%s ", s2);
		break;
	case 3:printf("enter string2\n"); scanf("%s", s2);
		strcat(s, s2); printf("%s", s);
		break;
	case 4:printf("enter string2\n"); scanf("%s", s2);
		res = strcmp(s, s2);
		printf("%d", res);
		break;
		
	}
	
	return 0;
}
