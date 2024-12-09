#include "s21_matrix.h"

/*allocates memory for matrix based on rows and columns values
returns: 0 - OK, 1 - INCORRECT MATRIX*/
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  result->rows = rows;
  result->columns = columns;
  result->matrix = malloc(result->rows * sizeof(double *));
  if (result->matrix) {
    for (int i = 0; i < result->rows && error_code == OK; i++) {
      result->matrix[i] = malloc(result->columns * sizeof(double));
      if (!result->matrix[i]) error_code = INCORRECT_MATRIX;
    }
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}

/*frees memory allocated for matrix A*/
void s21_remove_matrix(matrix_t *A) {
  if (A) {
    if (A->matrix) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
  }
}

/*checks if matrix A equals matrix B
returns: 1 - SUCCESS, 0 - FAILURE*/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrix(A) || check_matrix(B)) {
    return FAILURE;
  }
  int error_code = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) {
    error_code = FAILURE;
  } else {
    for (int i = 0; i < A->rows && error_code == SUCCESS; i++) {
      for (int j = 0; j < A->columns && error_code == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.00000009)
          error_code = FAILURE;
      }
    }
  }
  return error_code;
}

/*sum of matrix A with matrix B
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (A->rows != B->rows || A->columns != B->columns) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows && error_code == OK; i++) {
      for (int j = 0; j < result->columns && error_code == OK; j++) {
        if (isinf(A->matrix[i][j]) || isinf(B->matrix[i][j]) ||
            isnan(A->matrix[i][j]) || isnan(B->matrix[i][j])) {
          error_code = CALCULATION_ERROR;
          s21_remove_matrix(result);
        } else {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}

/*substraction matrix B from matrix A
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (A->rows != B->rows || A->columns != B->columns) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows && error_code == OK; i++) {
      for (int j = 0; j < result->columns && error_code == OK; j++) {
        if (isinf(A->matrix[i][j]) || isinf(B->matrix[i][j]) ||
            isnan(A->matrix[i][j]) || isnan(B->matrix[i][j])) {
          error_code = CALCULATION_ERROR;
          s21_remove_matrix(result);
        } else {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}

/*multiplication of matrix A on double number
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (isinf(number) || isnan(number)) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows && error_code == OK; i++) {
      for (int j = 0; j < result->columns && error_code == OK; j++) {
        if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
          error_code = CALCULATION_ERROR;
          s21_remove_matrix(result);
        } else {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return error_code;
}

/*multiplication of matrix A on matrix B
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (A->columns != B->rows) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows && error_code == OK; i++) {
      for (int j = 0; j < result->columns && error_code == OK; j++) {
        error_code = mult_helper(A, B, result, i, j);
      }
    }
  }
  return error_code;
}

/*calculates multiplication of 2 matrix for a single value
returns: 0 - OK, 2 - CALCULATION ERROR*/
int mult_helper(matrix_t *A, matrix_t *B, matrix_t *result, int i, int j) {
  int error_code = OK;
  result->matrix[i][j] = 0;
  for (int k = 0; k < A->columns && error_code == OK; k++) {
    if (isnan(A->matrix[i][k]) || isinf(A->matrix[i][k]) ||
        isnan(B->matrix[k][j]) || isinf(B->matrix[k][j])) {
      error_code = CALCULATION_ERROR;
      s21_remove_matrix(result);
    } else {
      result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
  return error_code;
}

/*transponse matrix A, writes to result
returns: 0 - OK, 1 - INCORRECT MATRIX*/
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

/*finds determinant of square matrix A
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A)) return INCORRECT_MATRIX;

  int error_code = OK;
  if (A->rows != A->columns || result == NULL || has_nan(A)) {
    error_code = CALCULATION_ERROR;
  } else {
    *result = determinant_helper(A);
  }
  return error_code;
}

/*checks if matrix has nan or inf values
returns: 0 - OK, 1 - found nan or inf*/
int has_nan(const matrix_t *mx) {
  int error_code = 0;
  for (int i = 0; i < mx->rows && !error_code; i++) {
    for (int j = 0; j < mx->columns && !error_code; j++) {
      if (isnan(mx->matrix[i][j]) || isinf(mx->matrix[i][j])) error_code = 1;
    }
  }
  return error_code;
}

/*recursively finds determinant of matrix*/
double determinant_helper(matrix_t *matrix) {
  double result = 0;
  if (matrix->rows == 1) {
    result = matrix->matrix[0][0];
  } else if (matrix->rows == 2) {
    result = matrix->matrix[0][0] * matrix->matrix[1][1] -
             matrix->matrix[1][0] * matrix->matrix[0][1];
  } else {
    for (int k = 0; k < matrix->rows; k++) {
      matrix_t minor;
      fill_minor_matrix(matrix, &minor, 0, k);
      if (k % 2 == 0) {
        result += matrix->matrix[0][k] * determinant_helper(&minor);
      } else {
        result += matrix->matrix[0][k] * determinant_helper(&minor) * (-1);
      }
      s21_remove_matrix(&minor);
    }
  }
  return result;
}

/*allocates memory and fills minor matrix*/
void fill_minor_matrix(matrix_t *matrix, matrix_t *minor, int m_rows,
                       int m_cols) {
  s21_create_matrix(matrix->rows - 1, matrix->rows - 1, minor);
  int row = 0, column = 0;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->rows; j++) {
      if (i != m_rows && j != m_cols) {
        minor->matrix[row][column] = matrix->matrix[i][j];
        column++;
      }
    }
    if (column) row++;
    column = 0;
  }
}

/*calculates matrix algebraic complements
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (A->rows != A->columns || has_nan(A)) {
    error_code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      for (int m_rows = 0; m_rows < A->rows; m_rows++) {
        for (int m_cols = 0; m_cols < A->rows; m_cols++) {
          matrix_t minor;
          fill_minor_matrix(A, &minor, m_rows, m_cols);
          double det = 0;
          s21_determinant(&minor, &det);
          if ((m_rows + m_cols) % 2 != 0) det *= (-1);
          result->matrix[m_rows][m_cols] = det;
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return error_code;
}

/*finds inverse matrix from A and writes to result
returns: 0 - OK, 1 - INCORRECT MATRIX, 2 - CALCULATION ERROR*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || result == NULL) {
    return INCORRECT_MATRIX;
  }
  int error_code = OK;
  if (A->rows != A->columns || has_nan(A)) {
    error_code = CALCULATION_ERROR;
  } else {
    double dtrm = 0;
    s21_determinant(A, &dtrm);
    if (!dtrm || isnan(dtrm) || isinf(dtrm)) {
      error_code = CALCULATION_ERROR;
    } else {
      if (A->rows == 1) {
        s21_create_matrix(A->rows, A->rows, result);
        result->matrix[0][0] = 1.0 / dtrm;
      } else {
        matrix_t matrix_compl, matrix_transp;
        s21_calc_complements(A, &matrix_compl);
        if (has_nan(&matrix_compl)) error_code = CALCULATION_ERROR;
        if (!error_code) {
          s21_transpose(&matrix_compl, &matrix_transp);
          s21_mult_number(&matrix_transp, 1.0 / dtrm, result);
          s21_remove_matrix(&matrix_transp);
        }
        s21_remove_matrix(&matrix_compl);
      }
    }
  }
  return error_code;
}

/*checks source matrix on not NULL / columns > 0 / rows > 0
returns: 0 - OK, 1 - INCORRECT MATRIX*/
int check_matrix(const matrix_t *mx) {
  int error_code = OK;
  if (mx == NULL || !mx->matrix || mx->columns <= 0 || mx->rows <= 0)
    error_code = INCORRECT_MATRIX;
  return error_code;
}