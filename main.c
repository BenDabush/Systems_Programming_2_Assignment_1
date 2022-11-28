#include <stdio.h>
#include "my_mat.h"

int main()
{
    int distanceMatrix[MATRIX_SIZE][MATRIX_SIZE];
    char command;
    int i;
    int j;
    do
    {
        scanf("%c", &command);
       

        switch (command)
        {
        case 'A':
            // taking input and storing it in a two-dimensional array
            for (int i = 0; i < MATRIX_SIZE; i++)
            {
                for (int j = 0; j < MATRIX_SIZE; j++)
                {
                    scanf("%d", &distanceMatrix[i][j]);
                }
            }
            findingTheShortestDistance(distanceMatrix);

           

            break;

        case 'B':
            scanf("%d %d\n", &i, &j);

            if ((i < 0) || (MATRIX_SIZE <= i) || (j < 0) || (MATRIX_SIZE <= j))
            {
                printf("False\n");
            }
            else if (0 < distanceMatrix[i][j])
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }

            break;

        case 'C':
            scanf("%d %d\n", &i, &j);

            if ((i < 0) || (MATRIX_SIZE <= i) || (j < 0) || (MATRIX_SIZE <= j))
            {
                printf("-1\n");
            }
            else if (0 < distanceMatrix[i][j])
            {
                printf("%d\n", distanceMatrix[i][j]);
            }
            else
            {
                printf("-1\n");
            }
            break;

        default:
            break;
        }

    } while (command != 'D');

    return 0;
}
