#include<iostream>
using namespace std;
class Student{
    int rollno;
    char name[20];
    int marks[3];
    int total;
    char grade;
public:
    friend istream & operator>>(istream &, Student &);
    friend ostream & operator<<(ostream &, Student &);
    friend void generate_results(Student [], int n);
};
istream & operator>>(istream &in, Student &s){
        cout<<"enter roll no, name, marks of 3 subjects\n";
        in>>s.rollno>>s.name;
        for(int i=0;i<3;i++)
            cin>>s.marks[i];
        return in;
    }
ostream & operator<<(ostream &out, Student &s){
        out<<"Name: "<<s.name<<endl;
        out<<"roll no: "<<s.rollno<<endl;
        out<<"Marks in 3 subjects: ";
        for(int i=0;i<3;i++)
            out<<s.marks[i]<<" ";
        out<<"\nTotal marks: "<<s.total<<endl;
        out<<"Grade: "<<s.grade<<endl;
        return out;
    }
void generate_results(Student s[], int n){
    for(int j=0;j<n;j++){
            s[j].total=0;
        for(int i=0;i<3;i++)
            s[j].total += s[j].marks[i];

    float avg=s[j].total/3;
    if (avg >= 60)
			s[j].grade = 'A';
		else if (avg >= 50 && avg < 60)
			s[j].grade = 'B';
		else if (avg >= 40 && avg < 50)
			s[j].grade = 'C';
		else
			s[j].grade = 'F';
    }
}

int main(){
    int n;
    cout<<"enter no of students: ";
    cin>>n;
    Student s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    generate_results(s,n);
    for(int i=0;i<n;i++){
        cout << s[i];
    }
return 0;
}
