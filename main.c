#include <stdio.h>
#include "my_mat.h"

int main()
{
    char command;
    do
    {
        scanf("%c", &command);

        switch (command)
        {
        case 'A':
            // taking input and storing it in a two-dimensional array
            enteringNumbers();
            break;

        case 'B':
            routeExistence();
            break;

        case 'C':

            shortestRoute();
            break;

        default:
            break;
        }

    } while (command != 'D');

    return 0;
}
