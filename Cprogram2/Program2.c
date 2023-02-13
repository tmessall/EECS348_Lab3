/*
 * Program2.c
 *
 *  Created on: Feb 12, 2023
 *      Author: travismessall
 */

#include <stdio.h>

void calcScores(score) {
	for (int tdWithTwo = 0; tdWithTwo * 8 <= score; tdWithTwo++) {
		int tempScore = score - tdWithTwo * 8;
		for (int tdWithOne = 0; tdWithOne * 7 <= tempScore; tdWithOne++) {
			int tempScore1 = tempScore - tdWithOne * 7;
			for (int td = 0; td * 6 <= tempScore1; td++) {
				int tempScore2 = tempScore1 - td * 6;
				for (int fg = 0; fg * 3 <= tempScore2; fg++) {
					int tempScore3 = tempScore2 - fg * 3;
					if (tempScore3 % 2 == 0) {
						printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdWithTwo, tdWithOne, td, fg, tempScore3 / 2);
					}
				}
			}
		}
	}
}

int main() {
	while (1) {
		int score;
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL score: \n");
		scanf("%d", &score);

		if (score == 0 || score == 1) {
			break;
		}

		calcScores(score);
	}


	return 0;
}
