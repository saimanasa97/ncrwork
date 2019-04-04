#pragma once

struct alloc {
	int line;
	int isAllocated; //true->1 , false->0
};

int isKeyword(char[]);
int isOperator(char);
void deprecated(char[]);