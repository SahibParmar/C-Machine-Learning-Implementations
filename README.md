# C-Machine-Learning-Implementations
Welcome to CML-Algorithms! This repository hosts a collection of machine learning algorithms implemented in C, along with essential matrix operations to support these algorithms.

**Contents**

    Machine_Learning.h: Header file containing the following functions:
        LinearRegression: Performs linear regression on input data.
        predict: Makes predictions using the trained linear regression model.
        LogisticRegression: Implements logistic regression for classification tasks.
        classify: Classifies data using the trained logistic regression model.
        sigmoid: Calculates the sigmoid function for logistic regression.

    Matrix.h: Header file providing fundamental matrix operations:
        print_array: Function to print an array of doubles.
        add: Addition of two arrays with scalar multiplication.
        dot_product: Calculates the dot product of two arrays.
        element_product: Element-wise multiplication of two arrays.
        matrix_multiply: Multiplies two matrices.

    Main.c: Contains a demonstration of how to use the functionalities provided in Machine_Learning.h. It imports the necessary functions from Matrix.h.

**Usage**
To use these functionalities, include the necessary header files in your C code and call the appropriate functions as demonstrated in Main.c.
