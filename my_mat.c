#include <stdio.h>
#include "my_mat.h"

#define MATRIX_SIZE 4

int findingTheShortestDistance(int distanceMatrix[][MATRIX_SIZE])
{
    for (int k = 0; k<MATRIX_SIZE; k++)
    {        
        for (int i = 0; i<MATRIX_SIZE; i++)
        {
            // If j==k according to algorithms there is nothing to check
            if (i == k)
            {
                continue;
            }
            for (int j = 0; j<MATRIX_SIZE; j++)
            {
                // If i==j it is the same node and therefore there is nothing to check further
                // If j==k according to algorithms there is nothing to check
                /* If the matrix at position (i,k) or (k,j) is equal to 0 by definition,
                   this means that there is no way to one of the nodes and therefore there is nothing to continue to check */
                if ((j == k) || (i == j)  || (distanceMatrix[i][k] == 0) || (distanceMatrix[k][j] == 0))
                {
                    continue;
                }

                // If the matrix at position (i,j) is equal to 0 this means that there is no way between the nodes
                if ((distanceMatrix[i][j] == 0))
                {
                    distanceMatrix[i][j] = distanceMatrix[i][k]+distanceMatrix[k][j];
                }

                // The weight (distance) between node i and node j is lighter (shorter) when passing through node k
                if ((distanceMatrix[i][k]+distanceMatrix[k][j]) < distanceMatrix[i][j])
                {
                    distanceMatrix[i][j] = distanceMatrix[i][k]+distanceMatrix[k][j];
                }
            }
        }
    }
    return 0;
}