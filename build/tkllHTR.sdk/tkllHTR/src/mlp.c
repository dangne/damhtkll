#include <stdio.h>
#include <math.h>
#include "matrix.h"
#include "mlp.h"
#include "layers.h"

// Number of units in each layer
#define UNIT_LAYER_INPUT	784
#define UNIT_LAYER_1		64
#define UNIT_LAYER_OUTPUT	10

Matrix ReLU(Matrix input){
    Matrix result = new_matrix(input.row, input.col);
    for(int i = 0 ; i < result.row ; i++)
    	for (int j = 0 ; j < result.col ; j++)
    		result.at[i][j] = input.at[i][j] >= 0 ? input.at[i][j] : 0;
    return result;
}

Matrix SoftMax(Matrix input){
    double sum = 0;
	Matrix exponential = new_matrix(input.row, input.col);
	for(int i = 0 ; i < input.row ; i++) {
    	for (int j = 0 ; j < input.col ; j++) {
    		exponential.at[i][j] = exp(input.at[i][j]);
    		sum += exponential.at[i][j];
    	}
    }

    for(int i = 0 ; i < input.row ; i++)
    	for (int j = 0 ; j < input.col ; j++)
    		exponential.at[i][j] /= sum;
    return exponential;
}

int MLP(Matrix input){
	Matrix w1 = weight(UNIT_LAYER_INPUT, UNIT_LAYER_1, 0);		// 784x64
	Matrix b1 = bias(1, UNIT_LAYER_1, 0);						// 1x64
	Matrix w2 = weight(UNIT_LAYER_1, UNIT_LAYER_OUTPUT, 1);		// 64x10
	Matrix b2 = bias(1, UNIT_LAYER_OUTPUT, 1);					// 1x10

	Matrix hidden_1 = ReLU(add(mul(input, w1), b1));
	Matrix output = SoftMax(ReLU(add(mul(hidden_1, w2), b2)));

    int result = 0;
    for (int i = 0 ; i < output.row ; i++)
    	if (output.at[0][i] > output.at[0][result])
    		result = i;

    return result;
}