#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>

double sigmoid(double z);

int printMatrix(double **vector2d, int m, int n);

double* dotProduct(double **vector2dA, int mA, int nA, double **vector2dB, int mB, int nB);

double** createVector2d(int m, int n);

void freeVector2d(double** vector2d, int m);

double** mockFill(double** vector2d, int m, int n, int bias);

#endif  // LINEAR_ALGEBRA_H
