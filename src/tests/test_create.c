#include "s21_test.h"

START_TEST(create_test_1) {
  matrix_t matrix_1;
  int rows = 1;
  int columns = 1;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_2) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 0;
  int columns = 0;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_3) {
  matrix_t matrix_1;
  int rows = 2;
  int columns = 1;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_4) {
  matrix_t matrix_1;
  int rows = 4;
  int columns = 1;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_5) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 0;
  int columns = 1;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_6) {
  matrix_t matrix_1;
  int rows = 1;
  int columns = 4;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_7) {
  matrix_t matrix_1;
  int rows = 1;
  int columns = 9;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_8) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 0;
  int columns = 0;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_9) {
  matrix_t matrix_1;
  int rows = 6;
  int columns = 9;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_10) {
  matrix_t matrix_1;
  int rows = 7;
  int columns = 10;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_11) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 0;
  int columns = 0;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_12) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = -5;
  int columns = -3;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_13) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 5;
  int columns = -5;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_14) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = -5;
  int columns = 6;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_15) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 0;
  int columns = 3;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_16) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 3;
  int columns = 0;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
  ck_assert_msg(matrix_1.matrix == NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_17) {
  matrix_t matrix_1;
  matrix_1.matrix = NULL;
  int rows = 11;
  int columns = 22;
  int error_code = s21_create_matrix(rows, columns, &matrix_1);

  ck_assert_msg(error_code == OK, "result code failed");
  ck_assert_msg(matrix_1.matrix != NULL, "matrix creation failed");

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(create_test_18) {
  int rows = 1;
  int columns = 1;
  int error_code = s21_create_matrix(rows, columns, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "result code failed");
}
END_TEST

START_TEST(remove_test_1) { s21_remove_matrix(NULL); }
END_TEST

Suite *suite_create_test() {
  Suite *suite = suite_create("suite_create_test");
  TCase *tcase = tcase_create("tcase_create_test");

  tcase_add_test(tcase, create_test_1);
  tcase_add_test(tcase, create_test_2);
  tcase_add_test(tcase, create_test_3);
  tcase_add_test(tcase, create_test_4);
  tcase_add_test(tcase, create_test_5);
  tcase_add_test(tcase, create_test_6);
  tcase_add_test(tcase, create_test_7);
  tcase_add_test(tcase, create_test_8);
  tcase_add_test(tcase, create_test_9);
  tcase_add_test(tcase, create_test_10);
  tcase_add_test(tcase, create_test_11);
  tcase_add_test(tcase, create_test_12);
  tcase_add_test(tcase, create_test_13);
  tcase_add_test(tcase, create_test_14);
  tcase_add_test(tcase, create_test_15);
  tcase_add_test(tcase, create_test_16);
  tcase_add_test(tcase, create_test_17);
  tcase_add_test(tcase, create_test_18);
  tcase_add_test(tcase, remove_test_1);

  suite_add_tcase(suite, tcase);

  return suite;
}