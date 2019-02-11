#include<stdio.h>
int main(){
char *color[6] = {"red", "green", "blue", "white", "black", "yellow"};
printf("%u\n",color);
printf("%u\n",(color+2));
printf("%s",*color);
printf("%s",*(color+2));
printf("%s",*(color + 5));
return 0;
}