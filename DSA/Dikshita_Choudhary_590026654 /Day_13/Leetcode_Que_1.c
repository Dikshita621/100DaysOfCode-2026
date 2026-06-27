#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 11

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char words[MAX_WORDS][MAX_LEN];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    char word[MAX_LEN];
    int idx = 0;
    int n = strlen(paragraph);

    for (int i = 0; i <= n; i++) {
        if (i < n && isalpha(paragraph[i])) {
            if (idx < MAX_LEN - 1)
                word[idx++] = tolower(paragraph[i]);
        } else {
            if (idx > 0) {
                word[idx] = '\0';
                idx = 0;

                int isBanned = 0;
                for (int j = 0; j < bannedSize; j++) {
                    if (strcmp(word, banned[j]) == 0) {
                        isBanned = 1;
                        break;
                    }
                }
                if (isBanned) continue;

                int found = -1;
                for (int j = 0; j < wordCount; j++) {
                    if (strcmp(words[j], word) == 0) {
                        found = j;
                        break;
                    }
                }

                if (found == -1) {
                    strcpy(words[wordCount], word);
                    freq[wordCount] = 1;
                    wordCount++;
                } else {
                    freq[found]++;
                }
            }
        }
    }

    int maxIdx = 0;
    for (int i = 1; i < wordCount; i++) {
        if (freq[i] > freq[maxIdx])
            maxIdx = i;
    }

    char *ans = (char *)malloc(strlen(words[maxIdx]) + 1);
    strcpy(ans, words[maxIdx]);
    return ans;
}
