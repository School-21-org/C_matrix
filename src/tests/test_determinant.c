#include "s21_test.h"

START_TEST(correct_test_1) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 9;
  matrix.matrix[0][3] = 6;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 7;
  matrix.matrix[1][2] = -1;
  matrix.matrix[1][3] = 0;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 3;
  matrix.matrix[2][2] = 1;
  matrix.matrix[2][3] = 2;
  matrix.matrix[3][0] = 7;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 12;
  matrix.matrix[3][3] = -4;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == 3290.0, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_test_2) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 9;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 7;
  matrix.matrix[1][2] = -1;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 3;
  matrix.matrix[2][2] = 1;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == -240.0, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_test_3) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == 0, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_test_4) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 5;
  matrix.matrix[0][1] = 4;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == 6, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_test_5) {
  matrix_t matrix;
  s21_create_matrix(5, 5, &matrix);
  matrix.matrix[0][0] = -1;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 1;
  matrix.matrix[0][3] = 2;
  matrix.matrix[0][4] = 5;
  matrix.matrix[1][0] = 93;
  matrix.matrix[1][1] = 123;
  matrix.matrix[1][2] = 11;
  matrix.matrix[1][3] = 22;
  matrix.matrix[1][4] = -2;
  matrix.matrix[2][0] = -53;
  matrix.matrix[2][1] = 13;
  matrix.matrix[2][2] = 123;
  matrix.matrix[2][3] = -123;
  matrix.matrix[2][4] = 125;
  matrix.matrix[3][0] = 9;
  matrix.matrix[3][1] = 8;
  matrix.matrix[3][2] = 7;
  matrix.matrix[3][3] = 6;
  matrix.matrix[3][4] = 5;
  matrix.matrix[4][0] = 1;
  matrix.matrix[4][1] = 2;
  matrix.matrix[4][2] = 3;
  matrix.matrix[4][3] = 4;
  matrix.matrix[4][4] = 1;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == 3097720, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(correct_test_6) {
  matrix_t matrix;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 123.123;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result == 123.123, "determinant calcualtion failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_1) {
  matrix_t matrix;
  s21_create_matrix(2, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_2) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);
  matrix.rows = 0;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_3) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);
  matrix.columns = 0;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_4) {
  matrix_t matrix = {0};

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_5) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_determinant(&matrix, NULL);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_6) {
  double result;
  int error_code = s21_determinant(NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_7) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = NAN;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_8) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = INFINITY;

  double result;
  int error_code = s21_determinant(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_determinant_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_determinant_test");
  TCase *tcase = tcase_create("tcase_determinant_test");

  tcase_add_test(tcase, correct_test_1);
  tcase_add_test(tcase, correct_test_2);
  tcase_add_test(tcase, correct_test_3);
  tcase_add_test(tcase, correct_test_4);
  tcase_add_test(tcase, correct_test_5);
  tcase_add_test(tcase, correct_test_6);

  tcase_add_test(tcase, incorrect_test_1);
  tcase_add_test(tcase, incorrect_test_2);
  tcase_add_test(tcase, incorrect_test_3);
  tcase_add_test(tcase, incorrect_test_4);
  tcase_add_test(tcase, incorrect_test_5);
  tcase_add_test(tcase, incorrect_test_6);
  tcase_add_test(tcase, incorrect_test_7);
  tcase_add_test(tcase, incorrect_test_8);

  suite_add_tcase(suite, tcase);

  return suite;
}