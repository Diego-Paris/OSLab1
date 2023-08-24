#include "include/ex3.h"

void printArr(char **array, int squared) {
    // Populate 2D Array
    for (int i = 0; i < squared; ++i) {
        for (int j = 0; j < squared; ++j) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

void decode(char *cmd) {

    int strLength = 0;

    while (cmd[strLength] != '\0') {
        strLength++;
    }

    int squared = sqrt(strLength);

    // Invalid if not a perfect square
    if (squared * squared != strLength) {
        memset(cmd, 0, MAX_CHARS);
        strcpy(cmd, "INVALID");
        printf("%s\n", cmd);
        return;
    }

    // Build 2D Array
    char **array;
    array = malloc(sizeof(char*)*squared);

    for (int i = 0; i < squared; ++i) {
        array[i] = malloc(sizeof(char)*squared);
    }

    // Populate 2D Array
    int itr = 0;
    for (int i = 0; i < squared; ++i) {
        for (int j = 0; j < squared; ++j) {
            array[j][i] = cmd[itr];
            itr++;
        }
    }

    // Print Array
    //printArr(array, squared);

    // Read message from 2DArray
    memset(cmd, 0, MAX_CHARS);
    itr = 0;
    for (int i = 0; i < squared; ++i) {
        for (int j = 0; j < squared; ++j) {
            cmd[itr] = array[i][j];
            itr++;
        }
    }

    printf("%s\n", cmd);
}

int main(void) {
    // Tests Variables
    char cmd[MAX_CHARS];

    //Test 0
    strcpy(cmd, "WECGEWHYAAIORTNU");
    decode(cmd); // Expected: WEAREWATCHINGYOU
    memset(cmd, 0, MAX_CHARS);

    //Test 1
    strcpy(cmd, "WE OUE OUT LNGSAO H RWDN!");
    decode(cmd); // Expected: WE ARE LOW ON DOUGHNUTS !
    memset(cmd, 0, MAX_CHARS);

    //Test 2
    strcpy(cmd, "S EFEM FNOCEDROE");
    decode(cmd); // Expected: SEND MORE COFFEE
    memset(cmd, 0, MAX_CHARS);

    //Test 3
    strcpy(cmd, "CSERULES");
    decode(cmd); // Expected: INVALID
    memset(cmd, 0, MAX_CHARS);

    return 0;
}