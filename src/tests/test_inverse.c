#include "s21_test.h"

START_TEST(correct_test_1) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 7;
  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 4;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[2][2] == 24, "inverse calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_2) {
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

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[3][3] ==
                    -0.0729483282674772137710306196822784841060638427734375,
                "inverse calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_3) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 55.13;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(result.matrix[0][0] == 1 / 55.13, "inverse calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_4) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = -5;
  matrix.matrix[0][1] = 123;
  matrix.matrix[1][0] = 13;
  matrix.matrix[1][1] = 15;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(
      result.matrix[1][1] ==
          0.0029868578255675026951465600433266445179469883441925048828125,
      "inverse calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(correct_test_5) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(5, 5, &matrix);
  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 0;
  matrix.matrix[0][2] = 1;
  matrix.matrix[0][3] = 23;
  matrix.matrix[0][4] = 1;
  matrix.matrix[1][0] = 7;
  matrix.matrix[1][1] = 8;
  matrix.matrix[1][2] = -123;
  matrix.matrix[1][3] = 13;
  matrix.matrix[1][4] = 99;
  matrix.matrix[2][0] = 2;
  matrix.matrix[2][1] = 13;
  matrix.matrix[2][2] = 4;
  matrix.matrix[2][3] = 1;
  matrix.matrix[2][4] = 2;
  matrix.matrix[3][0] = -7;
  matrix.matrix[3][1] = 9;
  matrix.matrix[3][2] = 1;
  matrix.matrix[3][3] = 2;
  matrix.matrix[3][4] = 4;
  matrix.matrix[4][0] = 48;
  matrix.matrix[4][1] = 95;
  matrix.matrix[4][2] = 45;
  matrix.matrix[4][3] = 32;
  matrix.matrix[4][4] = 21;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == OK, "func returned value failed");
  ck_assert_msg(
      result.matrix[3][4] ==
          -0.006466275655394961019428734516623080708086490631103515625,
      "inverse calcualtion failed");

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_test_1) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 0;
  matrix.matrix[0][1] = 0;
  matrix.matrix[0][2] = 0;
  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 0;
  matrix.matrix[1][2] = 0;
  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = 0;
  matrix.matrix[2][2] = 0;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_2) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 0;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_3) {
  matrix_t matrix;
  matrix_t result;
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

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_4) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.rows = 0;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_5) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix);
  matrix.columns = -1;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  for (int i = 0; i < 2; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(incorrect_test_6) {
  matrix_t matrix = {0};
  matrix_t result;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_7) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(2, 3, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_8) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(5, 4, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_9) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);

  int error_code = s21_inverse_matrix(&matrix, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_10) {
  matrix_t result;

  int error_code = s21_inverse_matrix(NULL, &result);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_11) {
  int error_code = s21_inverse_matrix(NULL, NULL);

  ck_assert_msg(error_code == INCORRECT_MATRIX, "func returned value failed");
}
END_TEST

START_TEST(incorrect_test_12) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = INFINITY;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_13) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = NAN;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_14) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix_generator(1, &matrix, &matrix, 0);
  matrix.matrix[0][0] = 1.7976931348623157e+308;
  matrix.matrix[0][1] = 0;
  matrix.matrix[1][0] = 0;
  matrix.matrix[1][1] = 1.7976931348623157e+308;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(incorrect_test_15) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 5;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 5;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 1.7976931348623157e+308;
  matrix.matrix[1][2] = 0;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 0;
  matrix.matrix[2][2] = 1.7976931348623157e+308;

  int error_code = s21_inverse_matrix(&matrix, &result);

  ck_assert_msg(error_code == CALCULATION_ERROR, "func returned value failed");

  s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_inverse_test() {
  srand(time(0));
  Suite *suite = suite_create("suite_inverse_test");
  TCase *tcase = tcase_create("tcase_inverse_test");

  tcase_add_test(tcase, correct_test_1);
  tcase_add_test(tcase, correct_test_2);
  tcase_add_test(tcase, correct_test_3);
  tcase_add_test(tcase, correct_test_4);
  tcase_add_test(tcase, correct_test_5);

  tcase_add_test(tcase, incorrect_test_1);
  tcase_add_test(tcase, incorrect_test_2);
  tcase_add_test(tcase, incorrect_test_3);
  tcase_add_test(tcase, incorrect_test_4);
  tcase_add_test(tcase, incorrect_test_5);
  tcase_add_test(tcase, incorrect_test_6);
  tcase_add_test(tcase, incorrect_test_7);
  tcase_add_test(tcase, incorrect_test_8);
  tcase_add_test(tcase, incorrect_test_9);
  tcase_add_test(tcase, incorrect_test_10);
  tcase_add_test(tcase, incorrect_test_11);
  tcase_add_test(tcase, incorrect_test_12);
  tcase_add_test(tcase, incorrect_test_13);
  tcase_add_test(tcase, incorrect_test_14);
  tcase_add_test(tcase, incorrect_test_15);

  suite_add_tcase(suite, tcase);

  return suite;
}