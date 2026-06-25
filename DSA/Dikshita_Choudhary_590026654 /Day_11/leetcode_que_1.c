#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {
    // Arrays to store character mappings:
    // mapST maps characters from s to t
    // mapTS maps characters from t to s
    int mapST[256];
    int mapTS[256];

    // Initialize all mappings to -1 (meaning no mapping exists yet)
    for (int i = 0; i < 256; i++) {
        mapST[i] = -1;
        mapTS[i] = -1;
    }

    // Traverse both strings simultaneously
    while (*s && *t) {
        unsigned char c1 = *s; // Current character from s
        unsigned char c2 = *t; // Current character from t

        // If neither character has been mapped before
        if (mapST[c1] == -1 && mapTS[c2] == -1) {
            // Create a new two-way mapping
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }
        // If an existing mapping does not match, strings are not isomorphic
        else if (mapST[c1] != c2 || mapTS[c2] != c1) {
            return false;
        }

        // Move to the next characters
        s++;
        t++;
    }

    // Return true only if both strings ended at the same time
    return *s == *t;
}
