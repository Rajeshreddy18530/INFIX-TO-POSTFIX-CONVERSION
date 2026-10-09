#include<stdio.h>
int precedence(char op)
{
        if((op=='+')||(op=='-'))
        {
                return 1;
        }
        else if((op=='*')||(op=='/'))
        {
                return 2;
        }
        else if(op=='^')
        {
                return 3;
        }
        else
        {
                return 0;
        }
}