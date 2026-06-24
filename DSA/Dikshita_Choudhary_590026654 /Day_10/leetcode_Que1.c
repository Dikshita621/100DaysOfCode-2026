#include <string.h>

int strStr(char* haystack, char* needle) {
    char *pos = strstr(haystack, needle);

    if (pos == NULL)
        return -1;

    return pos - haystack;
}
