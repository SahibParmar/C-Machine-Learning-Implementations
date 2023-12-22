#include "matrix.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


//Linear Regression
// Linear regression training (Using Mean-square error)
double *LinearRegression(double *X, double *y, int size, int features, int epochs,double alpha) {
  srand((unsigned int)time(NULL));
  double *thetas = calloc(sizeof(double), size);
  for (int i = 0; i < features; i++)
    thetas[i] = (double)(rand() % 10);

  double pred[size], *error;
  for (int _ = 0; _ < epochs; _++) {
    for (int s = 0; s < size; s++) {
      double *data_point;
      data_point = X + features * s;
      pred[s] = dot_product(data_point, thetas, features);
    }

    error = add(pred, y, size, -1);

    for (int f = 0; f < features; f++) {
      float sum = 0;
      for (int s = 0; s < size; s++) {
        sum += *(X + features * s + f) * error[s];
      }
      thetas[f] = thetas[f] - alpha * sum;
    }
  }
  return thetas;
}

//Linear regression prediction
double *predict(double *X, double *weight, int features, int size) {
  double *pred = calloc(sizeof(double), size);
  for (int s = 0; s < size; s++) {
    double sum = 0;
    double *data_point;
    data_point = X + features * s;
    for (int f = 0; f < features; f++) {
      sum += (data_point[f] * weight[f]);
    }
    pred[s] = sum;
  }
  return pred;
}


//Logistic Regression
double sigmoid(double x){
  return 1/(1+exp(-1*x));
}
//Logistic Regression training using log-loss(Binary crossentropy)
double *LogisticRegression(double *X, double *y, int size, int features, int epochs,double alpha) {
  srand((unsigned int)time(NULL));
  double *thetas = calloc(sizeof(double), size);
  for (int i = 0; i < features; i++)
    thetas[i] = (double)(rand() % 10);

  double pred[size], *error;
  for (int _ = 0; _ < epochs; _++) {
    for (int s = 0; s < size; s++) {
      double *data_point;
      data_point = X + features * s;
      pred[s] = sigmoid(dot_product(data_point, thetas, features));
    }
    error = add(pred, y, size, -1);
    for (int f = 0; f < features; f++) {
      float sum = 0;
      for (int s = 0; s < size; s++) {
        sum += *(X + features * s + f) * error[s];
      }
      thetas[f] = thetas[f] - alpha * sum;
    }
  }
  return thetas;
}
// Classify using Logistic regression
double *classify(double *X, double *weight, int features, int size) {
  double *pred = calloc(sizeof(double), size);
  for (int s = 0; s < size; s++) {
    double sum = 0;
    double *data_point;
    data_point = X + features * s;
    for (int f = 0; f < features; f++) {
      sum += (data_point[f] * weight[f]);
    }
    pred[s] = sigmoid(sum);
  }
  return pred;
}
