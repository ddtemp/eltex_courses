#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

#define MAX_INPUT_LENGTH 256

int main() {
  void *calc_lib = dlopen(
      "./libcalc.so",
      RTLD_LAZY);  // RTLD_LAZY или RTLD_NOW, в зависимости от вашего выбора
  if (!calc_lib) {
    printf("Error loading the library: %s\n", dlerror());
    return 1;
  }

  double (*addition)(double, double) = dlsym(calc_lib, "addition");
  double (*subtraction)(double, double) = dlsym(calc_lib, "subtraction");
  double (*multiplication)(double, double) = dlsym(calc_lib, "multiplication");
  double (*division)(double, double) = dlsym(calc_lib, "division");
  double (*exponentiation)(double, double) =
      dlsym(calc_lib,
            "exponentiation");  // Добавляем указатель на функцию exponentiation

  if (!addition || !subtraction || !multiplication || !division ||
      !exponentiation) {  // Добавляем проверку на указатель exponentiation
    printf("Error loading functions from the library: %s\n", dlerror());
    dlclose(calc_lib);
    return 1;
  }

  char input[MAX_INPUT_LENGTH];
  int choice;
  double num_1, num_2, result = 0;

  while (1) {
    printf(
        "Choose operation:\n"
        "1. Addition\n"
        "2. Subtraction\n"
        "3. Multiplication\n"
        "4. Division\n"
        "5. Exponentiation\n"
        "6. Exit\n"
        "Enter argument (1-6):");

    if (fgets(input, sizeof(input), stdin) != NULL) {
      choice = atoi(input);

      if (choice == 6) {
        printf("Exiting the program.\n");
        break;
      }

      if (choice < 1 || choice > 5) {
        printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        continue;
      }

      printf("Enter first number: ");
      if (fgets(input, sizeof(input), stdin) != NULL) {
        num_1 = atof(input);
      } else {
        printf("\nError reading the first number.\n");
        continue;
      }

      printf("Enter second number: ");
      if (fgets(input, sizeof(input), stdin) != NULL) {
        num_2 = atof(input);
      } else {
        printf("\nError reading the second number.\n");
        continue;
      }

      switch (choice) {
        case 1:
          result = addition(num_1, num_2);
          break;

        case 2:
          result = subtraction(num_1, num_2);
          break;

        case 3:
          result = multiplication(num_1, num_2);
          break;

        case 4:
          result = division(num_1, num_2);
          break;

        case 5:
          result = exponentiation(num_1,
                                  num_2);  // Используем функцию exponentiation
          break;

        default:
          printf("Wrong parameters\n");
      }

      printf("\nResult: %lf\n", result);
    } else {
      printf("\nError reading input.\n");
      break;
    }
  }

  dlclose(calc_lib);
  return 0;
}
