#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>
int top=-1;
char stack[100];
void push(char data)
{
        stack[++top]=data;
}
char pop()
{
char temp;
temp=stack[top];
top--;
return temp;
}
int main()
{       int i,j=0;
        char infix[50],postfix[50];
        printf("enter the infix expression\n");
        fgets(infix,50,stdin);
        infix[strlen(infix)-1]='\0';
        for(i=0;infix[i];i++)
        {
                if(((infix[i]>='A')&&(infix[i]<='Z'))||((infix[i]>='a')&&(infix[i]<='z')))
                {
                        postfix[j++]=infix[i];
                }
                else if((infix[i]=='(')||(infix[i]=='{')||(infix[i]=='['))
                {
                        push(infix[i]);
                }
                else if((infix[i]==')')||(infix[i]=='}')||(infix[i]==']'))
                {
                   while((top!=-1)&&(stack[top]!='(')&&(stack[top]!='{')&&(stack[top]!='['))
                   {
                        postfix[j++]=pop();
                }
                   if(top!=-1)
                   {
                           pop();
                   }
                }
                else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/')||(infix[i]=='^'))
                {
                         while(((top!=-1)&&(stack[top]!='(')&&(stack[top]!='{')&&(stack[top]!='['))&&((precedence(stack[top]))>=precedence(infix[i])))
                         {
                                 postfix[j++]=pop();
                         }
                         push(infix[i]);
                }
        }
         while((infix[i]=='\0')&&(top!=-1))
        {   if((stack[top]=='(')&&(stack[top]=='{')&&(stack[top]=='['))
                {
                                         pop();
                }
             else
             {
                     postfix[j++]=pop();
        }
        }
        postfix[j]='\0';
        printf("postfix output is\n");
         puts(postfix);
}                                                        