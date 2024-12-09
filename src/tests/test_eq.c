#include "s21_test.h"

START_TEST(different_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST
START_TEST(different_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 6;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 9;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 6;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 8;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_7) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 7;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_8) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 6;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 0);
  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(different_test_9) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 6;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 1);
  matrix_1.matrix[0][0] += 1e-7;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 1);

  matrix_1.matrix[0][0] -= 0.00000001;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_2) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 2;
  int columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 1);
  matrix_1.matrix[0][0] -= 1e-8;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_3) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 1);
  matrix_1.matrix[0][0] -= 1e-8;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 9;
  int columns = 8;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_1, &matrix_2, 1);
  matrix_1.matrix[0][0] -= 1e-8;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(0, &matrix_1, &matrix_2, 1);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(equal_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_1.matrix[0][0] = 0.00000001;
  matrix_2.matrix[0][0] = 0.00000001;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == SUCCESS,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t matrix_1;
  matrix_t matrix_2 = {0};
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_2, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2;
  int rows = 4;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(error_test_3) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
}
END_TEST

START_TEST(error_test_4) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_2.matrix = NULL;
  int rows = 5;
  int columns = 5;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_2, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(error_test_5) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_1.matrix = NULL;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(error_test_6) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  matrix_1.matrix = NULL;
  matrix_2.matrix = NULL;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
}
END_TEST

START_TEST(error_test_7) {
  matrix_t matrix_1;
  s21_create_matrix(2, 2, &matrix_1);

  matrix_generator(1, &matrix_1, &matrix_1, 0);

  ck_assert_msg(s21_eq_matrix(&matrix_1, NULL) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(error_test_8) {
  matrix_t matrix_2;
  s21_create_matrix(3, 3, &matrix_2);

  matrix_generator(1, &matrix_2, &matrix_2, 0);

  ck_assert_msg(s21_eq_matrix(NULL, &matrix_2) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_2);
}
END_TEST
START_TEST(error_test_9) {
  ck_assert_msg(s21_eq_matrix(NULL, NULL) == FAILURE,
                "matrix comparison failed");
}
END_TEST

START_TEST(error_test_10) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &matrix_1);
  matrix_generator(1, &matrix_2, &matrix_2, 1);
  matrix_1.columns = 0;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_2);

  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(error_test_11) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_2);
  s21_create_matrix(2, 2, &matrix_1);
  matrix_generator(1, &matrix_2, &matrix_2, 1);
  matrix_1.rows = 0;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_2);
  for (int i = 0; i < 2; i++) {
    free(matrix_1.matrix[i]);
  }
  free(matrix_1.matrix);
}
END_TEST

START_TEST(error_test_12) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  matrix_generator(1, &matrix_1, &matrix_1, 1);
  matrix_2.columns = 0;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_1);

  for (int i = 0; i < 2; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(error_test_13) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(2, 2, &matrix_1);
  s21_create_matrix(2, 2, &matrix_2);
  matrix_generator(1, &matrix_1, &matrix_1, 1);
  matrix_2.rows = 0;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");
  s21_remove_matrix(&matrix_1);
  for (int i = 0; i < 2; i++) {
    free(matrix_2.matrix[i]);
  }
  free(matrix_2.matrix);
}
END_TEST

START_TEST(error_test_14) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 5, &matrix_2);

  matrix_generator(0, &matrix_1, &matrix_2, 1);

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(error_test_15) {
  matrix_t matrix_1;
  matrix_t matrix_2;
  s21_create_matrix(3, 5, &matrix_1);
  s21_create_matrix(4, 5, &matrix_2);

  matrix_generator(0, &matrix_1, &matrix_2, 1);
  matrix_1.matrix[0][0] -= 1e-8;

  ck_assert_msg(s21_eq_matrix(&matrix_1, &matrix_2) == FAILURE,
                "matrix comparison failed");

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *suite_equality_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_equality_test");
  TCase *tcase = tcase_create("tcase_equality_test");

  tcase_add_test(tcase, different_test_1);
  tcase_add_test(tcase, different_test_2);
  tcase_add_test(tcase, different_test_3);
  tcase_add_test(tcase, different_test_4);
  tcase_add_test(tcase, different_test_5);
  tcase_add_test(tcase, different_test_6);
  tcase_add_test(tcase, different_test_7);
  tcase_add_test(tcase, different_test_8);
  tcase_add_test(tcase, different_test_9);

  tcase_add_test(tcase, equal_test_1);
  tcase_add_test(tcase, equal_test_2);
  tcase_add_test(tcase, equal_test_3);
  tcase_add_test(tcase, equal_test_4);
  tcase_add_test(tcase, equal_test_5);
  tcase_add_test(tcase, equal_test_6);

  tcase_add_test(tcase, error_test_1);
  tcase_add_test(tcase, error_test_2);
  tcase_add_test(tcase, error_test_3);
  tcase_add_test(tcase, error_test_4);
  tcase_add_test(tcase, error_test_5);
  tcase_add_test(tcase, error_test_6);
  tcase_add_test(tcase, error_test_7);
  tcase_add_test(tcase, error_test_8);
  tcase_add_test(tcase, error_test_9);
  tcase_add_test(tcase, error_test_10);
  tcase_add_test(tcase, error_test_11);
  tcase_add_test(tcase, error_test_12);
  tcase_add_test(tcase, error_test_13);
  tcase_add_test(tcase, error_test_14);
  tcase_add_test(tcase, error_test_15);

  suite_add_tcase(suite, tcase);

  return suite;
}