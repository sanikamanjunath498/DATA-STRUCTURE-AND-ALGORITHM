#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int score;
    int index;
} Athlete;

// Comparator function to sort athletes by score in descending order
int compare(const void* a, const void* b) {
    Athlete* athleteA = (Athlete*)a;
    Athlete* athleteB = (Athlete*)b;
    return athleteB->score - athleteA->score;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    
    // Create an array of structs to keep track of original indices
    Athlete* athletes = (Athlete*)malloc(scoreSize * sizeof(Athlete));
    for (int i = 0; i < scoreSize; i++) {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }
    
    // Sort athletes from highest score to lowest score
    qsort(athletes, scoreSize, sizeof(Athlete), compare);
    
    // Allocate memory for the result string array
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    
    for (int i = 0; i < scoreSize; i++) {
        int origIdx = athletes[i].index;
        // Allocate enough space for the longest string ("Bronze Medal" is 13 chars)
        result[origIdx] = (char*)malloc(15 * sizeof(char));
        
        if (i == 0) {
            strcpy(result[origIdx], "Gold Medal");
        } else if (i == 1) {
            strcpy(result[origIdx], "Silver Medal");
        } else if (i == 2) {
            strcpy(result[origIdx], "Bronze Medal");
        } else {
            sprintf(result[origIdx], "%d", i + 1);
        }
    }
    
    // Free temporary helper array
    free(athletes);
    
    return result;
}
