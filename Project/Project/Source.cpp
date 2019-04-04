#include<iostream>
#include "analyser.h""

int main() {

	char filename[50];
	std::cout << "Enter the name of the file to analyse:\n";
	std::cin >> filename;
	analyse(filename);

	return 0;
}