#include <stdio.h>
#include <stdlib.h>
#include "linear_algebra.h"

int main(int argc, char** argv) {
    int mA = 1024*10;
    int nA = 1024*10;
    int mB = 1024*10;
    int nB = 1024*30;
    // create a pointer to a 2d vector of doubles
    double **vectorPtrA = createVector2d(mA, nA);
    double **vectorPtrB = createVector2d(mB, nB);
    // fill the tensor with values
    vectorPtrA = mockFill(vectorPtrA, mA, nA, 0);
    vectorPtrB = mockFill(vectorPtrB, mB, nB, 10);
    printf("2-D vector A:\n");
    printMatrix(vectorPtrA, mA, nA);
    printf("2-D vector B:\n");
    printMatrix(vectorPtrB, mB, nB);
    double *innerProduct = dotProduct(vectorPtrA, mA, nA, vectorPtrB, mB, nB);
    for(int i = 0; i < mB; i++){
       printf("dot product index: %d %f\n", i, innerProduct[i]);
    }
    // free the memory from the heap
    freeVector2d(vectorPtrA, mA);
    freeVector2d(vectorPtrB, mB);
    free(innerProduct);
    return 0;
}
