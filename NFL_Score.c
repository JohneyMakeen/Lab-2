#include <stdio.h>

void NFL_score_machine(int Score) {
    int TD, FG, Saftey, TD_plus_FG, TD_plus_2pt;
    for (TD_plus_2pt = 0; TD_plus_2pt * 8 <= Score; TD_plus_2pt++) {
        for (TD_plus_FG = 0; TD_plus_FG *7 <= Score; TD_plus_FG++) {
            for (TD = 0; TD *6 <= Score; TD++) {
                for (FG = 0; FG * 3 <= Score; FG++) {
                    for (Saftey = 0; Saftey * 2 <= Score; Saftey++) {
                        if ((TD*6 + TD_plus_2pt*8 + TD_plus_FG*7 + FG*3 + Saftey*2) == Score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt, %d Saftey\n", TD_plus_2pt, TD_plus_FG, TD, FG, Saftey);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score); 

    while (score > 1) {
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        NFL_score_machine(score);

        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
    }
    printf("Thanks for playing!\n");
    return 0;
}
