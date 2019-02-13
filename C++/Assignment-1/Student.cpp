#include<iostream>
#include<string.h>
#pragma warning(disable : 4996)
using namespace std;
class Student {
	char *studentName;
	char grade;
	int marks[3];
public:
	void set_Data(char studentName[50], char grade, int marks1, int marks2, int marks3) {
		int len = strlen(studentName);
		this->studentName = (char *)malloc((len+1)*sizeof(char));
		strcpy(this->studentName, studentName);
		this->grade = grade;
		marks[0] = marks1;
		marks[1] = marks2;
		marks[2] = marks3;
	}
	float calculateAverage() {
		float avg = 0;
		for (int i = 0;i < 3;i++) {
			avg += marks[i];
		}
		return avg / 3;
	}
	void ComputeGrade() {
		float avg = calculateAverage();
		if (avg >= 60)
			grade = 'A';
		else if (avg >= 50 && avg < 60)
			grade = 'B';
		else if (avg >= 40 && avg < 50)
			grade = 'C';
		else
			grade = 'F';
	}
	void display()
	{
		cout << "Name: " << studentName<<endl;
		cout << "Grade : " << grade<<endl;
		cout << "Marks 1: " << marks[0]<<endl;
		cout << "Marks 2: " << marks[1]<<endl;
		cout << "Marks 3: " << marks[2]<<endl;
	}
};
int main() {
	Student s;
	s.set_Data("Damon", ' ', 100, 40, 50);
	s.ComputeGrade();
	s.display();
	getchar();
	return 0;
}