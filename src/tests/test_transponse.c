#include "s21_test.h"

START_TEST(correct_test_1) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[0][0] == matrix_1.matrix[0][0],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_2) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_3) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 1;
  int columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(
      result.matrix[columns - 1][0] == matrix_1.matrix[0][columns - 1],
      "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_4) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 5;
  int columns = 7;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_5) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 7;
  int columns = 8;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_6) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 6;
  int columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_7) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 13;
  int columns = 16;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_8) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 16;
  int columns = 17;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[columns - 1][rows - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_test_1) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.rows = 0;

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_test_2) {
  matrix_t matrix_1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  matrix_1.columns = 0;

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(incorrect_test_3) {
  matrix_t matrix_1 = {0};
  matrix_t result;

  int error_code = s21_transpose(&matrix_1, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_test_4) {
  matrix_t matrix_1;
  s21_create_matrix(2, 3, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);
  int error_code = s21_transpose(&matrix_1, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(incorrect_test_5) {
  matrix_t result;

  int error_code = s21_transpose(NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

Suite *suite_transponse_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_transponse_test");
  TCase *tcase = tcase_create("tcase_transponse_test");

  tcase_add_test(tcase, correct_test_1);
  tcase_add_test(tcase, correct_test_2);
  tcase_add_test(tcase, correct_test_3);
  tcase_add_test(tcase, correct_test_4);
  tcase_add_test(tcase, correct_test_5);
  tcase_add_test(tcase, correct_test_6);
  tcase_add_test(tcase, correct_test_7);
  tcase_add_test(tcase, correct_test_8);

  tcase_add_test(tcase, incorrect_test_1);
  tcase_add_test(tcase, incorrect_test_2);
  tcase_add_test(tcase, incorrect_test_3);
  tcase_add_test(tcase, incorrect_test_4);
  tcase_add_test(tcase, incorrect_test_5);

  suite_add_tcase(suite, tcase);

  return suite;
}