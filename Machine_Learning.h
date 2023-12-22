#ifndef MACHINE_LEARNING_H
#define MACHINE_LEARNING_H

double *LinearRegression(double *X, double *y, int size, int features,
                         int epochs, double alpha);
double *predict(double *X, double *weight, int features, int size);

double *LogisticRegression(double *X, double *y, int size, int features,
                           int epochs, double alpha);
double *classify(double *X, double *weight, int features, int size);
double sigmoid(double x);

#endif