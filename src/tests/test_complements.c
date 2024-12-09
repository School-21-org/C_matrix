#include "s21_test.h"

START_TEST(correct_test_1) {
  matrix_t matrix;
  matrix_t result;
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

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[3][3] == -240, "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_2) {
  matrix_t matrix;
  matrix_t result;
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

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[2][2] == 1, "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_3) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 1;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[2][2] == 4, "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_4) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 5;
  matrix.matrix[0][1] = 4;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[1][1] == 5, "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_5) {
  matrix_t matrix;
  matrix_t result;
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

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[4][4] == -898680,
                "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_6) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 123.123;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[0][0] == 123.123,
                "complements calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_test_1) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_2) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.rows = 0;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_3) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.columns = -2;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_4) {
  matrix_t matrix = {0};
  matrix_t result;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_5) {
  matrix_t matrix;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_calc_complements(&matrix, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_6) {
  matrix_t result;

  int error_code = s21_calc_complements(NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_7) {
  int error_code = s21_calc_complements(NULL, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_8) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = INFINITY;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_9) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = NAN;

  int error_code = s21_calc_complements(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_complements_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_complements_test");
  TCase *tcase = tcase_create("tcase_complements_test");

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
  tcase_add_test(tcase, incorrect_test_9);

  suite_add_tcase(suite, tcase);

  return suite;
}