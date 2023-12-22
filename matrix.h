#ifndef MATRIX_H
#define MATRIX_H

// Function prototypes
void print_array(double *arr, int size);
double *add(double *arr1, double *arr2, int size, double scaler);
double dot_product(double *arr1, double *arr2, int size);
double *element_product(double *arr1, double *arr2, int size);
double *matrix_multiply(double *arr1, double *arr2, int m1, int n1, int m2,
                        int n2);

#endif
