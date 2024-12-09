#include <check.h>
#include <stdio.h>
#include <time.h>

#include "../s21_matrix.h"

void matrix_generator(int zero_f, matrix_t *mx, matrix_t *mx_2, int equal);

Suite *suite_create_test();
Suite *suite_equality_test();
Suite *suite_sum_test();
Suite *suite_sub_test();
Suite *suite_mult_number_test();
Suite *suite_mult_matrix_test();
Suite *suite_transponse_test();
Suite *suite_determinant_test();
Suite *suite_complements_test();
Suite *suite_inverse_test();