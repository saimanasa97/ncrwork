#include<iostream>
#include<map>
#include<set>
#include<string>
#include<ctype.h>
#include "helper.h"
#pragma warning(disable:4996)
using namespace std;


void analyse(char filename[]) {
	char ch,  buffer[15];
	FILE *fp, *fp1;
	FILE *sugg;
	int  j = 0,  line = 1,  freeflag = 0;
	map <string, int> identifiers; //used->1, unused->0
	map<string, alloc> allocations;
	set<int> comment; //identifier
	map<string, int> dangling; //identifier, line number
	fp = fopen(filename, "r");
	fp1 = fopen(filename, "r");
	if (fp == NULL || fp1 == NULL) {
		printf("error while opening the file\n");
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF) {

		if (ch == '\n')
		{
			line++;
			long pos = ftell(fp);
			fseek(fp1, pos, SEEK_SET);
		}
		if (ch == '#')
		{
			while ((ch = fgetc(fp)) != '\n');
			line++;
		}
		if (ch == '\/') {
			if ((ch = fgetc(fp)) == '\/')
			{
				comment.insert(line);
				while ((ch = fgetc(fp)) != '\n');
				line++;
			}
			else if (ch == '*')
			{
				while (ch = fgetc(fp))
				{
					if (ch == '*') {
						if ((ch = fgetc(fp)) == '\/')
						{
							comment.insert(line);
							break;
						}
					}
					if (ch == '\n') {
						comment.insert(line++);
					}
				}
			}
		}

		else if (isalnum(ch) || ch == '_') {
			buffer[j++] = ch;
		}
		else if ((ch == ' ' || ch == '\n' || ch == ',' || ch == ';') && (j != 0)) {
			buffer[j] = '\0';

			if (isKeyword(buffer) == 2) {
				string buff(buffer);
				if (identifiers.count(buff))
					identifiers[buff] = 1;
				else
					identifiers.insert(pair<string, int>(buff, 0));
				if (allocations.count(buff) && allocations[buff].isAllocated == 0) {
					dangling.insert(pair<string, int>(buff, line));
				}

			}
			j = 0;
		}
		else if (isOperator(ch))
		{
			buffer[j] = '\0';

			if (isKeyword(buffer) == 2)
			{
				string buff(buffer);
				if (identifiers.count(buff))
					identifiers[buff] = 1;
				else
					identifiers.insert(pair<string, int>(buff, 0));
				if (allocations.count(buff) && allocations[buff].isAllocated == 0) {
					dangling.insert(pair<string, int>(buff, line));
				}

				j = 0;
			}
		}
		else if (ch == '(') {
			buffer[j] = '\0';
			int check = isKeyword(buffer);
			if (check == 5) {
			findDangling:
				j = 0;
				while ((ch = fgetc(fp1))) {
					if (ch == '=' || ch == ' ')
						break;
					else if (isalnum(ch) || ch == '_')
						buffer[j++] = ch;
				}
				buffer[j] = '\0';
				if (isKeyword(buffer) == 2) {
					struct alloc obj;
					obj.isAllocated = 1;
					obj.line = line;
					string buff(buffer);
					allocations.insert(pair<string, alloc>(buff, obj));
				}
				else
					goto findDangling;
			}
			else if (check == 6) {
				freeflag = 1;
			}
			else if (check==2 ) {
				deprecated(buffer);
			}
			j = 0;
		}
		else if (ch == '[') {
			buffer[j] = '\0';

			if (isKeyword(buffer) == 2)
			{
				string buff(buffer);
				if (identifiers.count(buff))
					identifiers[buff] = 1;
				else
					identifiers.insert(pair<string, int>(buff, 0));
				if (allocations.count(buff) && allocations[buff].isAllocated == 0) {
					dangling.insert(pair<string, int>(buff, line));
				}

				j = 0;
			}
		}
		else if (ch == ')' || ch == ']') {
			buffer[j] = '\0';
			string buff(buffer);
			if (allocations.count(buff) && allocations[buff].isAllocated == 0) {
				dangling.insert(pair<string, int>(buff, line));
			}
			if (freeflag == 1)
			{
				allocations[buff].isAllocated = 0;
				freeflag = 0;
			}
			if (identifiers.count(buff))
				identifiers[buff] = 1;
			else if (isKeyword(buffer) == 2)
				identifiers.insert(pair<string, int>(buff, 0));
			
			j = 0;
		}
		else if (ch == '"')
		{
			while ((ch = fgetc(fp)) != '"');
		}
	}
	if (identifiers.size()) {
		sugg = fopen("suggest.txt", "a");
		map <string, int> ::iterator itr;
		cout << "Unused variables are:\n";
		for (itr = identifiers.begin(); itr != identifiers.end(); ++itr)
		{
			if (itr->second == 0)
				cout << itr->first << " ";
			if (itr->first.length() <= 3)
			{
				fprintf(sugg, "A readable name can be given to variable %s.\n", itr->first.c_str());
			}
		}
		fclose(sugg);
		cout << endl;
	}
	if (allocations.size()) {
		map <string, alloc>::iterator itr1;
		cout << "memory leaks are for variables: \n";
		for (itr1 = allocations.begin(); itr1 != allocations.end(); ++itr1)
		{
			if (itr1->second.isAllocated == 1)
				cout << itr1->first << " " << itr1->second.line << endl;
		}
		cout << endl;
	}
	if (comment.size()) {
		set <int>::iterator itr2;
		cout << "Dead code is in lines: \n";
		for (itr2 = comment.begin(); itr2 != comment.end(); ++itr2)
		{
			cout << *itr2 << " ";
		}
		cout << endl;
	}
	if (dangling.size()) {
		map <string, int> ::iterator itr3;
		cout << "Dangling references are:\n";
		for (itr3 = dangling.begin(); itr3 != dangling.end(); ++itr3)
		{
			cout << itr3->first << " " << itr3->second << endl;
		}
		cout << endl;
	}
	cout << "WARNINGS:\n";
	sugg = fopen("suggest.txt", "r");
	while ((ch = fgetc(sugg)) != EOF) {
		cout << ch;
	}
	cout << endl;
	fclose(sugg);
	sugg = fopen("suggest.txt", "w");
	fclose(sugg);
	fclose(fp);
	fclose(fp1);
}