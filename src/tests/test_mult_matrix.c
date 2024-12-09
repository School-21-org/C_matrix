#include "s21_test.h"

START_TEST(correct_mul_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 1;
  int columns = 1;
  int common = 1;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(
      result.matrix[0][0] == matrix_1.matrix[0][0] * matrix_2.matrix[0][0],
      "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_mul_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  double check_value = 0;
  int i = rows - 1;
  int j = columns - 1;
  for (int k = 0; k < matrix_1.columns; k++) {
    check_value += matrix_1.matrix[i][k] * matrix_2.matrix[k][j];
  }
  ck_assert_msg(result.matrix[i][j] == check_value,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_mul_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 2;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  double check_value = 0;
  int i = rows - 1;
  int j = columns - 1;
  for (int k = 0; k < matrix_1.columns; k++) {
    check_value += matrix_1.matrix[i][k] * matrix_2.matrix[k][j];
  }
  ck_assert_msg(result.matrix[i][j] == check_value,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_mul_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 8;
  int columns = 7;
  int common = 3;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  double check_value = 0;
  int i = rows - 1;
  int j = columns - 1;
  for (int k = 0; k < matrix_1.columns; k++) {
    check_value += matrix_1.matrix[i][k] * matrix_2.matrix[k][j];
  }
  ck_assert_msg(result.matrix[i][j] == check_value,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_mul_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 4;
  int common = 4;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  double check_value = 0;
  int i = rows - 1;
  int j = columns - 1;
  for (int k = 0; k < matrix_1.columns; k++) {
    check_value += matrix_1.matrix[i][k] * matrix_2.matrix[k][j];
  }
  ck_assert_msg(result.matrix[i][j] == check_value,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_mul_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 3;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(0, &matrix_1, &matrix_2, 0);
  matrix_generator(0, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  double check_value = 0;
  int i = rows - 1;
  int j = columns - 1;
  for (int k = 0; k < matrix_1.columns; k++) {
    check_value += matrix_1.matrix[i][k] * matrix_2.matrix[k][j];
  }
  ck_assert_msg(result.matrix[i][j] == check_value,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;

  s21_create_matrix(2, 3, &matrix_1);
  s21_create_matrix(4, 5, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;

  s21_create_matrix(2, 1, &matrix_1);
  s21_create_matrix(2, 3, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_3) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2;
  matrix_t result;

  s21_create_matrix(2, 3, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2 = {0};
  matrix_t result;

  s21_create_matrix(2, 1, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_2, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 3, &matrix_2);
  matrix_generator(1, &matrix_2, &matrix_2, 0);
  matrix_1.rows = 0;

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.columns = 0;

  s21_create_matrix(2, 3, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_2, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_7) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_2);
  matrix_2.rows = 0;
  s21_create_matrix(2, 2, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
  for (int i = 0; i < 2; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_8) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_2);
  matrix_2.columns = 0;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
  for (int i = 0; i < 2; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_9) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);
  matrix_1.matrix[0][0] = INFINITY;

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_10) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);
  matrix_1.matrix[0][0] = NAN;

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_11) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);
  matrix_2.matrix[0][0] = INFINITY;

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_12) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);
  matrix_2.matrix[0][0] = NAN;

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_13) {
  matrix_t matrix_1;
  matrix_t matrix_2;

  int rows = 2;
  int columns = 3;
  int common = 2;
  s21_create_matrix(rows, common, &matrix_1);
  s21_create_matrix(common, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, &matrix_2, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(incorrect_mul_test_14) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(2, 3, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_matrix(&matrix_1, NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(incorrect_mul_test_15) {
  matrix_t matrix_2;
  matrix_t result;

  s21_create_matrix(2, 3, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_2, 0);

  int error_code = s21_mult_matrix(NULL, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *suite_mult_matrix_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_mult_matrix_test");
  TCase *tcase = tcase_create("tcase_mult_matrix_test");

  tcase_add_test(tcase, correct_mul_test_1);
  tcase_add_test(tcase, correct_mul_test_2);
  tcase_add_test(tcase, correct_mul_test_3);
  tcase_add_test(tcase, correct_mul_test_4);
  tcase_add_test(tcase, correct_mul_test_5);
  tcase_add_test(tcase, correct_mul_test_6);

  tcase_add_test(tcase, incorrect_mul_test_1);
  tcase_add_test(tcase, incorrect_mul_test_2);
  tcase_add_test(tcase, incorrect_mul_test_3);
  tcase_add_test(tcase, incorrect_mul_test_4);
  tcase_add_test(tcase, incorrect_mul_test_5);
  tcase_add_test(tcase, incorrect_mul_test_6);
  tcase_add_test(tcase, incorrect_mul_test_7);
  tcase_add_test(tcase, incorrect_mul_test_8);
  tcase_add_test(tcase, incorrect_mul_test_9);
  tcase_add_test(tcase, incorrect_mul_test_10);
  tcase_add_test(tcase, incorrect_mul_test_11);
  tcase_add_test(tcase, incorrect_mul_test_12);
  tcase_add_test(tcase, incorrect_mul_test_13);
  tcase_add_test(tcase, incorrect_mul_test_14);
  tcase_add_test(tcase, incorrect_mul_test_15);

  suite_add_tcase(suite, tcase);

  return suite;
}