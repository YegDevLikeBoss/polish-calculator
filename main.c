#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Treshold 100

int isempty();
int isfull();
double peek();
double pop();
void push(double data);

double stack[Treshold];
int top=-1;

int main(int argc, char *argv[])
{
    int i;
    double res=0.0f, valm=0.0f, val=0.0f;

    if (argc==1)
        printf("Error: This program inputs data via command line arguments.\nUse:\n+ to add\n- to substract\n'*' to muliply\n/ to devide\n");


    for(i=2; i<=argc; i++) /*Main calc loop*/
    {
        switch(*argv[i-1]) /*Arithmetic operations*/
        {
            case '+': {val=pop(); valm=pop(); res=valm+val; push(res);}/*Addiction*/
            break;
            case '-': {val=pop(); valm=pop(); res=valm-val; push(res);}/*Subtraction*/
            break;
            case 'x': {val=pop(); valm=pop(); res=valm*val; push(res);}/*Multiplication*/
            break;
            case '/': {
                        val=pop(); valm=pop();
                        if (val!=0)
                        {
                            res=valm/val;
                            push(res); /*Division*/
                        } else
                            {
                            printf("Indeterminate form");/*Division error checking*/
                            exit(1);
                            }
                        }
            break;
            default: {push(atof(argv[i-1]));}
        }
    } /*End*/

    printf("Result: %.2f\n", res); /*Result printing*/
    return 0;
}

int isempty() /*Checking stack status*/
{
    if (top==-1)
        return 1;
    else
        return 0;
}
int isfull() /*Checking stack status*/
{
    if (top==Treshold)
        return 1;
    else
        return 0;
}
double peek() /*Stack top element value*/
{
   return stack[top];
}
double pop() /*Stack output*/
{
    double data;

    if(!isempty())
    {
        data = stack[top];
        --top;

    }
    return data;
}
void push(double data) /*Stack input*/
{
    if(!isfull())
    {
        top++;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}
