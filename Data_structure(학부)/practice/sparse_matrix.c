#include <stdio.h>
#include <stdlib.h>

typedef struct _ELEMENT {
    int row;
    int col;
    int value;
} Element;

void Compress(int SparseMatrix[][6], int row, int col, int cnt, Element CompMatrix[]) {
    CompMatrix[0].row = row;
    CompMatrix[0].col = col;
    CompMatrix[0].value = cnt;
    int idx = 1;

    for(int n = 0; n < row; n++) {
        for(int m = 0; m < col; m++) {
            if(SparseMatrix[n][m] != 0) {
                CompMatrix[idx].row = n;
                CompMatrix[idx].col = m;
                CompMatrix[idx].value = SparseMatrix[n][m];
                idx++;
            }
        }
    }
}

int main() {
    int SparseMatrix[6][6] = {
        {15, 0, 0, 22, 0, -15},
        {0, 11, 3, 0, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {91, 0, 0, 0, 0, 0},
        {0, 0, 28, 0, 0, 0},
    };
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(SparseMatrix[i][j] != 0) cnt++;
        }
    }
    Element* CompMatrix = (Element*)malloc(sizeof(Element) * (cnt+1));

    Compress(SparseMatrix, 6, 6, cnt, CompMatrix);
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col : %d value: %d\n", CompMatrix[i].row, CompMatrix[i].col, CompMatrix[i].value);
    }
}