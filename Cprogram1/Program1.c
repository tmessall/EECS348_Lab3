/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: travismessall
 */


#include <stdio.h>

void firstSalesReport(char *months[], double sales[]) {
	printf("Monthly Sales Report for 2022:\n\n");

	printf("%-10s%s\n\n", "Month", "Sales");
	for (int i = 0; i < 12; i++) {
		printf("%-10s%s%.2f\n", months[i], "$", sales[i]);
	}
}

void salesSummary(char *months[], double sales[]) {
	int maxIndex, minIndex = 0;
	double totalSales = sales[0];

	for (int i = 1; i < 12; i++) {
		if (sales[i] > sales[maxIndex]) {
			maxIndex = i;
		}
		if (sales[i] < sales[minIndex]) {
			minIndex = i;
		}
		totalSales += sales[i];
	}

	printf("\nSales summary:\n\n");
	printf("%-20s%s%.2f\t%s%s%s\n", "Minimum sales:", "$", sales[minIndex], "(", months[minIndex], ")");
	printf("%-20s%s%.2f\t%s%s%s\n", "Maximum sales:", "$", sales[maxIndex], "(", months[maxIndex], ")");
	printf("%-20s%s%.2f\n", "Average sales:", "$", totalSales / 12);
}

void movingAverages(char *months[], double sales[]) {
	printf("\nSix-Month Moving Average Report:\n\n");

	for (int i = 0; i <= 6; i++) {
		double movingTotal = 0;
		for (int j = i; j < i + 6; j++) {
			movingTotal += sales[j];
		}
		printf("%-10s%-3s%-10s%s%.2f\n", months[i], "-", months[i+5], "$", movingTotal / 6);
	}
}

void descSalesReport(char *months[], double sales[]) {
	printf("\nSales Report (Highest to Lowest):\n\n");
	printf("%-10s%s\n\n", "Month", "Sales");

	double orderedSales[12] = {0.0};

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 11; j++) {
			if (sales[i] > orderedSales[j]) {
				for (int k = 11; k > j; k--) {
					orderedSales[k] = orderedSales[k - 1];
				}
				orderedSales[j] = sales[i];
				break;
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (orderedSales[i] == sales[j]) {
				printf("%-10s%s%.2f\n", months[j], "$", orderedSales[i]);
				break;
			}
		}
	}
}

int main() {
	double sales[12];
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    FILE *in_file = fopen("sales.txt", "r"); // @suppress("Type cannot be resolved")


    if (in_file == NULL) {
    	printf("no file");
    	return 0;
    }

	for (int i = 0; i < 12; i++) {
		fscanf(in_file, "%lf", &sales[i]);
	}

	firstSalesReport(months, sales);
	salesSummary(months, sales);
	movingAverages(months, sales);
	descSalesReport(months, sales);

	return 0;
}
