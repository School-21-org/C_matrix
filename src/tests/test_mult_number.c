#include "s21_test.h"

START_TEST(mul_test_1) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 1;
  int columns = 1;
  double number = 1;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[0][0] == matrix_1.matrix[0][0] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_2) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 3;
  double number = 0.005;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_3) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 2;
  double number = 5e-18;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_4) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 3;
  int columns = 4;
  double number = 3.465e-15;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_5) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4;
  int columns = 5;
  double number = 3.02148e-12;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_6) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 7;
  int columns = 9;
  double number = 1.7826732000000002e-09;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_7) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 4;
  double number = 0;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_8) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 4;
  double number = -123.1234;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_9) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 4;
  double number = 0.005;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(0, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] * number,
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_1) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  double number = 2;

  matrix_1.rows = 0;

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_2) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  double number = 2;
  matrix_1.columns = 0;

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_mul_test_3) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4;
  int columns = 4;
  double number = NAN;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(0, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_4) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4;
  int columns = 4;
  double number = INFINITY;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(0, &matrix_1, &matrix_1, 0);

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_5) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4;
  int columns = 4;
  double number = 50.1;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(0, &matrix_1, &matrix_1, 0);
  matrix_1.matrix[2][2] = NAN;

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_6) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4;
  int columns = 4;
  double number = 50.1;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(0, &matrix_1, &matrix_1, 0);
  matrix_1.matrix[2][2] = INFINITY;

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_7) {
  matrix_t matrix_1 = {0};
  matrix_t result;

  double number = 123;

  int error_code = s21_mult_number(&matrix_1, number, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_mul_test_8) {
  matrix_t matrix_1;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_generator(0, &matrix_1, &matrix_1, 0);
  double number = 123;

  int error_code = s21_mult_number(&matrix_1, number, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(incorrect_mul_test_9) {
  matrix_t result;
  double number = 123;

  int error_code = s21_mult_number(NULL, number, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

Suite *suite_mult_number_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_mult_number_test");
  TCase *tcase = tcase_create("tcase_mult_number_test");

  tcase_add_test(tcase, mul_test_1);
  tcase_add_test(tcase, mul_test_2);
  tcase_add_test(tcase, mul_test_3);
  tcase_add_test(tcase, mul_test_4);
  tcase_add_test(tcase, mul_test_5);
  tcase_add_test(tcase, mul_test_6);
  tcase_add_test(tcase, mul_test_7);
  tcase_add_test(tcase, mul_test_8);
  tcase_add_test(tcase, mul_test_9);

  tcase_add_test(tcase, incorrect_mul_test_1);
  tcase_add_test(tcase, incorrect_mul_test_2);
  tcase_add_test(tcase, incorrect_mul_test_3);
  tcase_add_test(tcase, incorrect_mul_test_4);
  tcase_add_test(tcase, incorrect_mul_test_5);
  tcase_add_test(tcase, incorrect_mul_test_6);
  tcase_add_test(tcase, incorrect_mul_test_7);
  tcase_add_test(tcase, incorrect_mul_test_8);
  tcase_add_test(tcase, incorrect_mul_test_9);

  suite_add_tcase(suite, tcase);

  return suite;
}