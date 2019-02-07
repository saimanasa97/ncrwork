#include<stdio.h>
#include<math.h>
int main(){
int n,len,d,i=1,choice,m,s,decimal=0,base=1,b,count=0,a=1;
unsigned int comp=0,mask;
char buff[50];
printf("enter hexadecimal number\n");
scanf("%x",&n);
len=sprintf(buff,"%d",n);
d=atoi(buff);
printf("enter your choice\n");
printf("1.one's complement of the hexadecimal number\n2.Masking\n3.Shifting\n4.Exit\n");
scanf("%d",&choice);
switch(choice){
case 1:	while(d>0){
	comp+=(1-(d%2))*i;
	i=i*10;
	d=d/2;
	count++;
	}
	if(count%4!=0){
	for(i=count%4;i>1;i--)
	a=(a*10)+1;
	}
	comp+=a*pow(10,count);
	printf("One's complement = %u\n",comp);
	while(comp>0){
	decimal += (comp%10)*base;
	base=base*2;
	comp=comp/10;
	}
	printf("%x",decimal);
	break;
case 2: printf("enter your choice\n");
	printf("1.AND\n2.EXCLUSIVE\n3.OR\n");
	scanf("%d",&m);
	printf("enter mask value:\n");
	scanf("%x",&mask);
	switch(m){
	
	case 1: len=n&mask;break;
	case 2: len=n^mask;break;
	case 3: len=n|mask;break;
	}
	printf("%x",len);
	break;
case 3: printf("enter your choice\n");
	printf("1.LEFT SHIFT\n2.RIGHT SHIFT\n");
	scanf("%d",&s);
	printf("enter no of bits to shift\n");
	scanf("%d",&b);
	switch(s){
	case 1: printf("%x",n<<b);break;
	case 2: printf("%x",n>>b);break;
	}
	break;
case 4: printf("exiting...");
	exit(0);
}
return 0;
}