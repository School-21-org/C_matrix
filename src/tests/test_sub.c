#include "s21_test.h"

START_TEST(correct_sub_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(
      result.matrix[0][0] == matrix_1.matrix[0][0] - matrix_2.matrix[0][0],
      "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST
START_TEST(correct_sub_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_sub_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_sub_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_sub_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_sub_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 6;
  int columns = 6;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(different_matrix_sub_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix_1);
  s21_create_matrix(1, 2, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(different_matrix_sub_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(3, 6, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(different_matrix_sub_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(8, 5, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix_1);
  matrix_2.matrix = NULL;

  matrix_generator(1, &matrix_1, &matrix_2, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix_2);
  matrix_1.matrix = NULL;

  matrix_generator(1, &matrix_2, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  matrix_1.matrix = NULL;
  matrix_2.matrix = NULL;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_4) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_t result;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  matrix_generator(1, &matrix_1, &matrix_2, 1);

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_6) {
  matrix_t matrix_1;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_1, &matrix_1, 0);

  int error_code = s21_sub_matrix(&matrix_1, NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_7) {
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_2);
  matrix_generator(1, &matrix_2, &matrix_2, 0);

  int error_code = s21_sub_matrix(NULL, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(null_matrix_sub_test_8) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_2);
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_2, &matrix_2, 0);
  matrix_1.rows = 0;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 4; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(null_matrix_sub_test_9) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_2);
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_generator(1, &matrix_2, &matrix_2, 0);
  matrix_1.columns = 0;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 4; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(null_matrix_sub_test_10) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  matrix_generator(1, &matrix_1, &matrix_1, 0);
  matrix_2.rows = 0;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 4; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(null_matrix_sub_test_11) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  matrix_generator(1, &matrix_1, &matrix_1, 0);
  matrix_2.columns = 0;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  if (!error_code) s21_remove_matrix(&result);

  for (int i = 0; i < 4; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(incorrect_value_sub_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  matrix_1.matrix[rows - 1][columns - 1] = NAN;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_value_sub_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  matrix_1.matrix[rows - 1][columns - 1] = INFINITY;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_value_sub_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_t result;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  matrix_1.matrix[rows - 1][columns - 1] = __DBL_MAX__;
  matrix_2.matrix[rows - 1][columns - 1] = __DBL_MAX__;

  int error_code = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[rows - 1][columns - 1] ==
                    matrix_1.matrix[rows - 1][columns - 1] -
                        matrix_2.matrix[rows - 1][columns - 1],
                "matrix calculation failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  if (!error_code) s21_remove_matrix(&result);
}
END_TEST

Suite *suite_sub_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_sub_test");
  TCase *tcase = tcase_create("tcase_sub_test");

  tcase_add_test(tcase, correct_sub_test_1);
  tcase_add_test(tcase, correct_sub_test_2);
  tcase_add_test(tcase, correct_sub_test_3);
  tcase_add_test(tcase, correct_sub_test_4);
  tcase_add_test(tcase, correct_sub_test_5);
  tcase_add_test(tcase, correct_sub_test_6);

  tcase_add_test(tcase, different_matrix_sub_test_1);
  tcase_add_test(tcase, different_matrix_sub_test_2);
  tcase_add_test(tcase, different_matrix_sub_test_3);

  tcase_add_test(tcase, null_matrix_sub_test_1);
  tcase_add_test(tcase, null_matrix_sub_test_2);
  tcase_add_test(tcase, null_matrix_sub_test_3);
  tcase_add_test(tcase, null_matrix_sub_test_4);
  tcase_add_test(tcase, null_matrix_sub_test_5);
  tcase_add_test(tcase, null_matrix_sub_test_6);
  tcase_add_test(tcase, null_matrix_sub_test_7);
  tcase_add_test(tcase, null_matrix_sub_test_8);
  tcase_add_test(tcase, null_matrix_sub_test_9);
  tcase_add_test(tcase, null_matrix_sub_test_10);
  tcase_add_test(tcase, null_matrix_sub_test_11);

  tcase_add_test(tcase, incorrect_value_sub_test_1);
  tcase_add_test(tcase, incorrect_value_sub_test_2);
  tcase_add_test(tcase, incorrect_value_sub_test_3);

  suite_add_tcase(suite, tcase);

  return suite;
}