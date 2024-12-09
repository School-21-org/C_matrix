#include "s21_test.h"

int main() {
  Suite* cases[] = {suite_create_test(),      suite_equality_test(),
                    suite_sum_test(),         suite_sub_test(),
                    suite_mult_number_test(), suite_mult_matrix_test(),
                    suite_transponse_test(),  suite_determinant_test(),
                    suite_complements_test(), suite_inverse_test()};

  for (int i = 0; i < 10; i++) {
    printf("\n");
    SRunner* sr = srunner_create(cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
