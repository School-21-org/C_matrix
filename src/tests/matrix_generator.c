#include "s21_test.h"

void matrix_generator(int zero_f, matrix_t *mx, matrix_t *mx_2, int equal) {
  double a = 999.123456789;
  for (int i = 0; i < mx->rows; i++) {
    for (int j = 0; j < mx->columns; j++) {
      if (zero_f) {
        double x = (double)rand() / (double)(RAND_MAX / a);
        if (i % 2 == 0) {
          mx->matrix[i][j] = x;
        } else {
          mx->matrix[i][j] = x * (-1);
        }
        if (equal) mx_2->matrix[i][j] = mx->matrix[i][j];
      } else {
        mx->matrix[i][j] = 0;
        if (equal) mx_2->matrix[i][j] = 0;
      }
    }
  }
}