#include<iostream>
#include<string.h>
using namespace std;
class String{
char *str;
int len;
public:
    String(char *p="",int l=0){
    str= new char[l];
    len=l;
    strcpy(str,p);
    }
    ~String(){
    delete []str;
    }

    String operator+(String &s){
    str=strcat(str,s.str);
    len=strlen(str);
    return *this;
    }
    char operator[](int n){
        return str[n];
    }
    String operator=(String &s){
        delete [] str;
        str=new char[s.len +1];
        strcpy(str,s.str);
        len=s.len;
        return *this;
    }
    friend istream & operator>> (istream &, String &c);
	friend ostream & operator<<(ostream &, String &c);
};
istream & operator>> (istream &in, String &c) {
	cout << "enter string\n";
	in >> c.str;
	c.len=strlen(c.str);
	return in;
}
ostream & operator<< (ostream &out, String &c) {
	out << c.str<<","<<c.len<<"\n";
	return out;
}
int main(){
    String s1,s2,s3;
    cin>>s1>>s2;
    s1+s2;
    cout<<s1;
    cin>>s3;
    s1=s3;
    cout<<s1;
    cout<<s1[2];
return 0;
}
