#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int chapters, probs; scanf("%i %i", &chapters, &probs);
    int *ar = malloc(sizeof(int)*chapters);
    for (int i=0; i<chapters; i++) scanf("%i", &ar[i]);
    int curChapter = 1, curPage = 1, count = 0;
    while (curChapter <= chapters) {
        for (int i=1; i<=ar[curChapter-1]; i++) {
            if (i == curPage)
                count++;
            if (i+1 <= ar[curChapter-1] && i % probs == 0)
                curPage++;
        }
        curPage++;
        curChapter++;
    }
    printf("%i", count);
    return 0;
}
