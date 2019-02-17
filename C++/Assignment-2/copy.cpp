#include<iostream>
#include<string.h>
using namespace std;
class String{
char *str;
int len;
public:
    String(char *p="",int l=0){
    str= new char[l+1];
    len=strlen(p);
    strcpy(str,p);
    }
    String(String &s){
    delete [] str;
    str= new char[s.len +1];
    len=s.len;
    strcpy(str,s.str);
    }
    void display(){
    cout<<str<<" "<<len<<endl;
    }
    ~String(){
    delete[] str;
    }
};
int main(){
String s1("sample1",7),s3(s1),s4;
s4=s1;
s3.display();
s4.display();
return 0;
}
