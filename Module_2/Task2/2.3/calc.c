#include <stdio.h>

double addition(double num_1, double num_2) {
	return num_1 + num_2;
}

double subtraction(double num_1, double num_2){
	return num_1 - num_2;
}

double multiplication(double num_1, double num_2){
	return num_1 * num_2;
}

double division(double num_1, double num_2){
	if (num_2 != 0) return num_1 / num_2;
	else {
		printf("\nError. Division by zero\n");
		return 0;
	}
}

double exponentiation(double num, double exponent){
	double result = 1.0;

	if (exponent > 0) {
		for (int i = 0; i < exponent; ++i){
			result *= num;
		}
	} else if (exponent < 0) {
		for (int i = 0; i > exponent; --i){
			result /= num;
		}
	}
	
	return result;
}
