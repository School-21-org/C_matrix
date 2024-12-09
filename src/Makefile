CC = gcc
CFLAGS = -Wall -Wextra -Werror -g --std=c11
OBJ_DIR = objects/
SOURCE = $(filter-out main.c, $(wildcard *.c))
OBJECT = $(patsubst %.c, %.o, $(SOURCE))
SOURCE_TEST = $(wildcard tests/*.c)
SOURCE_LIBRARY = $(filter-out s21_test.c, $(filter-out test%, $(SOURCE)))
OBJECT_LIBRARY = $(patsubst %.c, %.o, $(SOURCE_LIBRARY))
EXECUTABLE = s21_test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -DLinux
	GFLAGS = -lcheck_pic -lm -lsubunit
	RM_COMMAND = rm -rf test*.gcda test*.gcno
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck -lm
	RM_COMMAND = rm test*.gcda test*.gcno
endif

.PHONY: all s21_matrix.a test gcov_report style clang clean rebuild valgrind_test cppcheck_test

all: clean s21_matrix.a test gcov_report

s21_matrix.a: clean $(OBJECT_LIBRARY)
	@ar rc s21_matrix.a $(OBJECT_LIBRARY)
	@ranlib s21_matrix.a
	@rm -rf *.o

test: clean s21_matrix.a
	@$(CC) $(CFLAGS) $(SOURCE_TEST) s21_matrix.a -o $(EXECUTABLE) $(GFLAGS)
	@./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(SOURCE_TEST) -o $(EXECUTABLE) $(GFLAGS) --coverage 
	@./$(EXECUTABLE)
	@lcov -t "s21_tests" -o s21_tests.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	@genhtml -o report s21_tests.info -rc lcov_branch_coverage=1
	@rm -rf *.gcno *.gcda *.gcov

style:
	@cp ../materials/linters/.clang-format ./
	@cp ../materials/linters/.clang-format ./tests/
	@clang-format -n *.c tests/*.c
	@clang-format -n *.h tests/*.h
	@rm -rf .clang-format tests/.clang-format

clang:
	@cp ../materials/linters/.clang-format ./
	@cp ../materials/linters/.clang-format ./tests/
	@clang-format -i *.c tests/*.c
	@clang-format -i *.h tests/*.h
	@rm -rf .clang-format tests/.clang-format

clean:
	@rm -f *.o *.a *.gcno *.gcda *.info $(EXECUTABLE) valgrind_out.txt
	@rm -rf report $(OBJ_DIR)

rebuild: clean s21_matrix.a

valgrind_test: rebuild test
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./$(EXECUTABLE)

cppcheck_test:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h
