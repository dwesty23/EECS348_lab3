/*
 * program2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: d643w879
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combos(int score){
    int td2, td1, fg, saf, n;
    /*
    score -> user input to take score
    td2 -> TOUCHDOWN with 2-PT CONVERSION (8 points)
    td1 -> TOUCHDOWN with EXTRA POINT (7 points)
    fg -> FIELD GOAL (3 points)
    saf -> SAFETY (2 points)
    n -> leftover score
    */

    printf("Possible combinations of scoring plays for %d:\n", score);
    for (td2 = 0; td2 <= score/8; td2++) {
        for (td1 = 0; td1 <= (score-8*td2)/7; td1++) {
            for (fg = 0; fg <= (score-6*td2-7*td1)/3; fg++) {
                for (saf = 0; saf <= (score-8*td2-7*td1-3*fg)/2; saf++) {
                        n = score - 8*td2 - 7*td1 - 3*fg - 2*saf;
                        if (n == 0) {
                            printf("%d touchdowns(with 2-point conversion), %d touchdowns(with extra point), %d field goals, %d safeties\n", td2, td1, fg, saf);
                        }
                    }
                }
            }
        }
}

int main() {
    int check = 1, score;

    do{
        printf("ENTER 0 or 1 to STOP\n");
        printf("Enter the score: ");
        scanf("%d", &score);
        if(score <= 1){
            printf("exiting...\n");
            check = 0;
        }
        else{
            combos(score);
            printf("\n");
        }
    
    }
    while(check == 1);

}