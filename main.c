#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Treshold 100

int isempty();
int isfull();
double peek();
double pop();
void push(double data);

float stack[Treshold];
int top=-1;



int main(int argc, char *argv[])
{
    int i;
    double res=0.0f, valm=0.0f, val=0.0f;

    if (argc==1)
        printf("Error: This program inputs data via command line arguments.\nUse:\n+ to add\n- to substract\nx(latin) to muliply\n/ to devide\n");


    for(i=2; i<=argc; i++)
    {
        switch(*argv[i-1])
        {
            case '+': {val=pop()+0.0; valm=pop()+0.0; /*printf("%.2f %.2f", val, valm);*/ res=valm+val; push(res); /*printf("cc%.2fcc", peek());*/}
            break;
            case '-': {val=pop()+0.0; valm=pop()+0.0; res=valm-val; push(res);}
            break;
            case 'x': {val=pop()+0.0; valm=pop()+0.0; res=valm*val; push(res);}
            break;
            case '/': {val=pop()+0.0; valm=pop()+0.0; res=valm/val; push(res);}
            break;
            default: {push(atof(argv[i-1])); /*printf("xx%.2fxx", peek());*/}
        }
    }

    printf("Result: %.2f\n", res);
    return 0;
}

int isempty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top==Treshold)
        return 1;
    else
        return 0;
}
double peek()
{
   return stack[top];
}
double pop()
{
    int data;

    if(!isempty())
    {
        data = stack[top];
        --top;
        return data;
    } /*else
        {
            printf("Could not retrieve data, Stack is empty.\n");
        }*/
}
void push(double data)
{

   if(!isfull()) {
      top++;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
