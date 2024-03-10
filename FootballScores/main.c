#include <stdio.h>

void scoringCombinations(int score);

int main(){

    while(1){

        printf("Enter 0 or 1 to STOP\n");

        printf("Enter the NFL Score: ");

        fflush(stdout);

        int score;

        scanf("%d", &score);

        if (score <= 1){
            break;
        }

        scoringCombinations(score);
    }

    return 0;
}

void scoringCombinations(int score){
    if (score <= 2){
        printf("Invalid score");
    } else {
        for (int numTouchDownPlusTwo = 0; numTouchDownPlusTwo < score / 8; numTouchDownPlusTwo++){

            for (int numTouchDownPlusField = 0; numTouchDownPlusField < score / 7; numTouchDownPlusField++){

                for (int numTouchDown = 0; numTouchDown < score / 6; numTouchDown++){
                    for (int numFieldGoal = 0; numFieldGoal < score / 3; numFieldGoal++){
                        for (int numSafety = 0; numSafety < score / 2; numSafety++){
                            
                            if ((numTouchDown * 6) + (numTouchDownPlusField * 7) + (numTouchDownPlusTwo * 8) + 
                                (numFieldGoal * 3) + (numSafety * 2) == score){
                                    printf("%d TD + 2pt,%d TD + FG,%d TD,%d 3pt FG,%d Safety\n", 
                                    numTouchDownPlusTwo, numTouchDownPlusField, numTouchDown, numFieldGoal, numSafety);
                            }

                        }
                    }
                }
                
            }

        }
    }

}
