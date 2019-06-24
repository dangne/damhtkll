/*
 * matrix.h
 *
 *  Created on: Jun 16, 2019
 *      Author: dangn
 */

#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <stdlib.h>

int** new_matrix(int row, int col);
void del_matrix(int** a, int a_row);
int** add(int** a, int** b, int a_row, int a_col, int b_row, int b_col);
int** mul(int** a, int** b, int a_row, int a_col, int b_row, int b_col);

#endif /* SRC_MATRIX_H_ */