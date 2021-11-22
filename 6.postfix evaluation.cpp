#include<stdio.h>
#include<string.h>
#include<ctype.h>
int top=-1,n1,n2,n3, stack[50],ch=2;
void push(int a){
stack[++top]=a;
}
int pop()
{
if(top==-1){
printf("\n\aInvalid Expression");
ch=3;
}
else
{
return stack[top--];
}
}
evaluate(char x){
if(isdigit(x))
push((int)(x) - 48);
else{
n1=pop();
n2=pop();
if(x=='+')
n3=n1+n2;
else if(x=='-')
n3=n2-n1;
else if(x=='*')
n3=n1*n2;
else
n3=n2/n1;
push(n3);
}
}
int main(){
char s[100];
printf("\nEnter the postfix Expression : ");
scanf("%[^\n]",s);
short i;
for(i=0;i<strlen(s);i++){
if(s[i]==' ')
continue;
else
evaluate(s[i]);
}
if(ch!=3)
printf("\nResult : %d",n3);
return 0;
}
/*output
Enter the postfix Expression : 34*2+

Result : 14


