#include <stdio.h>
#include <stdlib.h>

typedef struct _element {
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
                CompMatrix[idx++].value = SparseMatrix[n][m];
            }
        }
    }
}

void smTranspose(Element a[], Element b[]) {
    int currentb;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    // 총 원소 수가 1 이상일 때
    if(a[0].value > 0) {
        currentb = 1;
        for(int i = 0; i < a[0].col; i++) {
            for(int j = 1; j <= a[0].value; j++) {
                if(a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb++].value = a[j].value;
                }
            }
        }
    }
}
void fast_transpose(Element a[], Element b[]) {
    int row_terms[100], starting_pos[100], numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;
    if(numTerms > 0) {
        for(int i = 0; i < numCols; i++) row_terms[i] = 0;
        for(int i = 1; i <= numTerms; i++) row_terms[a[i].col]++;
        starting_pos[0] = 1;
        for(int i = 1; i < numCols; i++) starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        for(int i = 1; i <= numTerms; i++) {
            int j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
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
        {0, 0, 28, 0, 0, 0}
    };
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(SparseMatrix[i][j] != 0) cnt++;
        }
    }
    Element* CompMatrix = (Element*)malloc(sizeof(Element)*cnt+1);
    Compress(SparseMatrix, 6, 6, cnt, CompMatrix);
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col: %d value: %d\n", CompMatrix[i].row, CompMatrix[i].col, CompMatrix[i].value);
    }
    Element* TransposeMatrix = (Element*)malloc(sizeof(Element)* cnt+1);
    smTranspose(CompMatrix, TransposeMatrix);
    printf("\n----------------------------------\n");
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col : %d value: %d\n", TransposeMatrix[i].row, TransposeMatrix[i].col, TransposeMatrix[i].value);
    }
    Element* FastTransposeMatrix = (Element*)malloc(sizeof(Element)*cnt+1);
    fast_transpose(CompMatrix, FastTransposeMatrix);
    printf("\n----------------------------------\n");
    for(int i = 0; i < cnt+1; i++) {
        printf("row: %d col : %d value: %d\n", FastTransposeMatrix[i].row, FastTransposeMatrix[i].col, FastTransposeMatrix[i].value);
    }
    free(CompMatrix);
    free(TransposeMatrix);
    free(FastTransposeMatrix);
    return 0;
}