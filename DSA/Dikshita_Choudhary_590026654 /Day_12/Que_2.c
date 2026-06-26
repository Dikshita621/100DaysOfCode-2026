#include <stdio.h>
#include <string.h>
#include <limits.h>

int shortestSubstring(char str[]) {
    int n = strlen(str);

    // Count distinct characters in the string
    int visited[256] = {0};
    int distinct = 0;

    for (int i = 0; i < n; i++) {
        if (visited[(unsigned char)str[i]] == 0) {
            visited[(unsigned char)str[i]] = 1;
            distinct++;
        }
    }

    // Sliding window
    int freq[256] = {0};
    int start = 0, count = 0;
    int minLen = INT_MAX;

    for (int end = 0; end < n; end++) {
        freq[(unsigned char)str[end]]++;

        if (freq[(unsigned char)str[end]] == 1)
            count++;

        while (count == distinct) {
            if (end - start + 1 < minLen)
                minLen = end - start + 1;

            freq[(unsigned char)str[start]]--;

            if (freq[(unsigned char)str[start]] == 0)
                count--;

            start++;
        }
    }

    return minLen;
}

int main() {
    char str[1000];

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Length of the shortest substring: %d\n", shortestSubstring(str));

    return 0;
}
