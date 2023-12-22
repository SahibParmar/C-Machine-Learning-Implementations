#include "Machine_Learning.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  printf("Logistic Regression\n\n");
  double X[4][2] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}}, y[4] = {1, 1, 0, 0};
  double *thetas = LogisticRegression(X, y, 4, 2, 10000, 0.01);
  printf("Weights:\n");
  print_array(thetas, 2);
  double *pred = classify(X, thetas, 2, 4);
  printf("\nOriginal\tPredictes\n");
  for (int i = 0; i < 4; i++)
    printf("%f\t%f\n", y[i], pred[i]);

  printf("\n\n\n");

  // Linear Regression demo
  printf("Linear Regression\n\n");
  int n = 100, m = 2, c = 3;
  double X2[n][2], y2[n];

  for (int i = 0; i < n; i++) {
    srand((unsigned int)time(NULL));
    X2[i][0] = (double)1;
    X2[i][1] = (double)i;
    y2[i] = (double)(m * i + c) + (double)rand() / 100000000;
  }

  double *weights = LinearRegression(X2, y2, n, 2, 1000, 0.0000001);
  printf("Weights:\n");
  print_array(weights, 2);

  double *pred2 = predict(X2, weights, 2, n);
  printf("\noriginal\tpredicted\n");
  for (int i = 0; i < 10; i++)
    printf("%f\t%f\n", y2[i], pred2[i]);

  return 0;
}
