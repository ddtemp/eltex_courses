#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

double addition(double num_1, double num_2);
double subtraction(double num_1, double num_2);
double multiplication(double num_1, double num_2);
double division(double num_1, double num_2);

int main() {
  while (1) {
    char input[MAX_INPUT_LENGTH];
    int choice;
    double num_1, num_2, result = 0;

    printf(
        "Choose operation:\n"
        "1. Addition\n"
        "2. Subtraction\n"
        "3. Multiplication\n"
        "4. Division\n"
        "5. Exit\n"
        "Enter argument (1-5):");

    if (fgets(input, sizeof(input), stdin) != NULL) {
      choice = atoi(input);

      if (choice == 5) {
        printf("Exiting the program.\n");
        break;
      }

      if (choice < 1 || choice > 4) {
        printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
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
          return 0;
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

  return 0;
}

double addition(double num_1, double num_2) { return num_1 + num_2; }
double subtraction(double num_1, double num_2) { return num_1 - num_2; }
double multiplication(double num_1, double num_2) { return num_1 * num_2; }
double division(double num_1, double num_2) {
  if (num_2 != 0)
    return num_1 / num_2;
  else {
    printf("\nError. Division by zero\n");
    return 0;
  }
}
