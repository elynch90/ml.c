#include "linear_algebra.h"

double sigmoid(double z) {
   return 1.0 / (1.0 + exp(-z));
}

int printMatrix(double **vector2d, int m, int n){
   for(int i =0; i < m; i++){
      for(int j = 0; j < n; j++){
          printf("%f\t", vector2d[i][j]);      
      }
      printf("%s\n", "");
   }
   return 0;
}

double* dotProduct(double **vector2dA, int mA, int nA, double **vector2dB, int mB, int nB){
   double *sum = malloc(mB * sizeof(double *));
   if (nA != mB){
      perror("Dimension n of vector2D 1 mismatch with Dimension m of vector2D 2.");
      return NULL;
   }
   // parallelize over rows of A
   #pragma omp parallel for
   // for every row in matrix A
   for(int i = 0; i < mA; i++){
     sum[i] = 0;
     // for every column in matrix B
     for(int j = 0; j < nB; j++){
         double rowSum = 0;
         // for every column in matrix A
	 for(int k = 0; k < nA; k++){
            rowSum += vector2dA[i][k] * vector2dB[k][j];
         }
         sum[i] = rowSum;
      }
   }
   return sum;
}

double** createVector2d(int m, int n){
   double **vectorPtr = malloc(m * sizeof(double *));
   for (int i = 0; i < m; i++){
       vectorPtr[i] = malloc(n * sizeof(double *));
   }
   return vectorPtr;
}

void freeVector2d(double** vector2d, int m){
   for (int i = 0; i < m; i++){
      free(vector2d[i])
   }
   free(vector2d);
}

double** mockFill(double** vector2d, int m, int n, int bias) {
    for (int i = 0; i < m; i++){
       for(int j = 0; j < n; j++){
          vector2d[i][j] = (i + j + bias) * 0.9; 
       }
    }
    return vector2d;
}
 
