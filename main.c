#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void celTo(float tmp); /*Celsius converter*/
void farTo(float tmp); /*Fahrenheit converter*/
void kelTo(float tmp); /*Kelvin converter*/
void universal(float tmp); /*Undefined converter*/
void error(char type, char tp2); /*Error handling*/

int main(int argc, char *argv[])
{
    int capScale, status;
    float val, temp;

    status = 1;
    val = atof(argv[1]); /*converting pointer to float*/

    if(argc==2)
    {
        universal(val);
    }
    else if (argc==3)
    {
        temp = *argv[2];
        capScale = toupper(temp); /*letter capitalization*/
        switch(capScale) /*Scale scenario switching*/
        {
            case 'C': /*In case of Celsius*/
                {
                    if (val > -273.16)
                        celTo(val);
                    else
                    {
                        error('b', '\0');
                        status=0;
                    }
                }
            break;
            case 'F': /*In case of Fahrenheit*/
                {
                    if (val > -459.67)
                        farTo(val);
                    else
                    {
                        error('b', '\0');
                        status=0;
                    }
                }
            break;
            case 'K': /*In case of Kelvin*/
                {
                    if (val > -0.01)
                        kelTo(val);
                    else
                    {
                        error('b', '\0');
                        status=0;
                    }
                }
            break;
            default:
                {
                     error('a', capScale);
                     status=0;
                }
        }
    }
    return status; /*Main output*/
}
void celTo(float tmp) /*Celsius conversion*/
    {
        float celsius, fahrenheit, kelvin;

        celsius = tmp;
        fahrenheit = 9*celsius/5+32;
        kelvin = celsius + 273.15;
        printf("%.2f F\n%.2f K ;-)\n", fahrenheit, kelvin);
    }
void farTo(float tmp) /*Fahrenheit conversion*/
    {
        float celsius, fahrenheit, kelvin;

        fahrenheit = tmp;
        celsius = (fahrenheit - 32)*5/9;
        kelvin = celsius + 273.15;
        printf("%.2f C\n%.2f K ;-)\n", celsius, kelvin);
    }
void kelTo(float tmp) /*Kelvin conversion*/
    {
        float celsius, fahrenheit, kelvin;

        kelvin = tmp;
        celsius = kelvin - 273.15;
        fahrenheit = 9*celsius/5+32;
        printf("%.2f C\n%.2f F ;-)\n", celsius, fahrenheit);
    }
void universal(float tmp) /*undefined conversion*/
    {
        float celsius, fahrenheit, kelvin;

        printf("For Celsius:\n");
        if (tmp > -273.16)
        {
            celsius = tmp;
            fahrenheit = 9*celsius/5+32;
            kelvin = celsius + 273.15;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
        printf("For Fahrenheit:\n");
        if (tmp > -459.67)
        {
            fahrenheit = tmp;
            celsius = (fahrenheit - 32)*5/9;
            kelvin = celsius + 273.15;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
        printf("For Kelvin:\n");
        if (tmp > -0.01)
        {
            kelvin = tmp;
            celsius = kelvin - 273.15;
            fahrenheit = 9*celsius/5+32;
            printf("%.2f C\n%.2f F\n%.2f K ;-)\n", celsius, fahrenheit, kelvin);
        }
        else printf("Invalid value of temperature :-(\n");
    }
void error(char type, char tp2) /*Error handling*/
    {
        switch(type)
        {
            case 'a':printf("Incompatible argument: '%c'. Try 'c', 'f' or 'k' instead :-(\n", tp2);
            break;
            case 'b':printf("Invalid value of temperature :-(\n");
            break;
        }
    }
