#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// Will return a+scaler*b
double *add(double *arr1, double *arr2, int size, double scaler) {
  double *c = calloc(sizeof(double), size);
  for (int i = 0; i < size; i++)
    c[i] = arr1[i] + scaler * arr2[i];
  return c;
}

// Doing dot product of two row vectors
double dot_product(double *arr1, double *arr2, int size) {
  double ans = 0;
  for (int _ = 0; _ < size; _++)
    ans += arr1[_] * arr2[_];
  return ans;
}

// Element wise product
double *element_product(double *arr1, double *arr2, int size) {
  double *c = calloc(sizeof(double), size);
  for (int _ = 0; _ < size; _++)
    c[_] = arr1[_] * arr2[_];
  return c;
}

// For matrix multiplication
double *matrix_multiply(double *arr1, double *arr2, int m1, int n1, int m2,
                        int n2) {
  if (n1 != m2) {
    printf("Error: Matrix dimensions do not match");
    return NULL;
  }
  double c[m1][n2];
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++) {
      c[i][j] = 0;
    }
  }
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++) {
      for (int k = 0; k < n1; k++) {
        c[i][j] += arr1[i * n1 + k] * arr2[k * n2 + j];
      }
    }
  }

  return c;
}

// Print an row vector
void print_array(double *arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%f ", arr[i]);
  printf("\n");
}