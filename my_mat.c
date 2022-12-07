#include <stdio.h>
#include "my_mat.h"

int distanceMatrix[MATRIX_SIZE][MATRIX_SIZE];

int findingTheShortestDistance()
{
    for (int k = 0; k < MATRIX_SIZE; k++)
    {
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            // If j==k according to algorithms there is nothing to check
            if (i != k)
            {
                for (int j = 0; j < MATRIX_SIZE; j++)
                {
                    // If i==j it is the same node and therefore there is nothing to check further
                    // If j==k according to algorithms there is nothing to check
                    /* If the matrix at position (i,k) or (k,j) is equal to 0 by definition,
                       this means that there is no way to one of the nodes and therefore there is nothing to continue to check */
                    if ((j != k) && (i != j) && (distanceMatrix[i][k] != 0) && (distanceMatrix[k][j] != 0))
                    {
                        // If the matrix at position (i,j) is equal to 0 this means that there is no way between the nodes
                        if ((distanceMatrix[i][j] == 0))
                        {
                            distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                        }

                        // The weight (distance) between node i and node j is lighter (shorter) when passing through node k
                        if ((distanceMatrix[i][k] + distanceMatrix[k][j]) < distanceMatrix[i][j])
                        {
                            distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void enteringNumbers()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            scanf("%d", &distanceMatrix[i][j]);
        }
    }
    findingTheShortestDistance(distanceMatrix);
}

void routeExistence()
{
    int i;
    int j;
    scanf("%d%d", &i, &j);

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
}

void shortestRoute()
{
    int i;
    int j;
    scanf("%d%d", &i, &j);

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
}