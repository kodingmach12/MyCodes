#include <stdio.h>

int frogPaths(int res[], int resIndex, int curRock, int numRocks) {
    if (curRock == numRocks) {

        int i;

        for (i = 0; i < resIndex; ++i) {
            printf("%d ", res[i]);
        }
        printf("%d\n", curRock);

        return 1;

    } else {
        int count = 0;

        res[resIndex] = curRock;

        if (curRock + 1 <= numRocks)
            count += frogPaths(res, resIndex + 1, curRock + 1, numRocks);

        if (curRock + 2 <= numRocks)
            count += frogPaths(res, resIndex + 1, curRock + 2, numRocks);

        return count;
    }
}


int main(){
    int n;

    scanf("%d", &n);

    int a[n + 1];

    printf("Total num of paths = %d\n",frogPaths(a, 0, 1, n));
}