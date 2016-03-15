#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


bool checkPattern(char* G[],int R, int C, char* P[], int r, int c, int row, int col)
{
    int G_r, G_c, i, j;
    bool identical = true;
    for (G_r = row, i = 0; i < r; ++G_r, ++i) {
        for (G_c = col, j = 0; j < c; ++G_c, ++j) {
            // boundary check
            if (G_r > R || G_c > C) return false;

            if (G[G_r][G_c] != P[i][j]) {
                identical = false;
            }
        }
    }
    return identical;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        scanf("%d %d", &R, &C);
        char* G[R];
        for (int G_i = 0; G_i < R; G_i++){
            G[G_i] = (char *)malloc(1024 * sizeof(char));
            scanf("%s", G[G_i]);
        }
        int r;
        int c;
        scanf("%d %d", &r, &c);
        char* P[r];
        for (int P_i = 0; P_i < r; P_i++){
            P[P_i] = (char *)malloc(1024 * sizeof(char));
            scanf("%s", P[P_i]);
        }

        int found = 0;
        for (int row = 0; row < R; ++row) {
            char* subStr = G[row];
            while((subStr = strstr(subStr, P[0])) != NULL) {
                int col = C - strlen(subStr);
                if (checkPattern(G, R, C, P, r, c, row, col)) {
                    found = 1;
                    break;
                }
                //subStr += strlen(subStr);
                subStr += 1;
            }
            if (found) break;
        }

        if (found) printf("YES\n");
        else printf("NO\n");

    }


    return 0;
}
