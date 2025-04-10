#include <stdio.h>
#include <string.h>

// The routine below copys one string to another.
// Parametera:
//     Source string (poineter),
//     Destination string (pointer)
//     Starting location in source (int)
//     Ending location in source (int)
//     Size of the destination folder (int). This is a safety measure to ensure the destination is not overwritten causing a memory error.

void copy_substring(const char *source, char *destination, int start, int end, int size) {
    // Basic input validation
    if(strlen(source) > size)
        destination[0] = '\0'; // Return empty string if invalid input
        return;

    if (start < 0 || end < start || end >= strlen(source)) {
        destination[0] = '\0'; // Return empty string if invalid input
        return;
    }

    int j = 0;
    for (int i = start; i <= end; i++) {
        destination[j++] = source[i];
    }
    destination[j] = '\0'; // Null-terminate the destination string
}

// This is the test for the copy subroutine
int main() {
    const char *original = "Hello, world!";
    char result[100];  // Make sure this is large enough for the substring

    int start = 7;
    int end = 11;
    int size = 100;

    copy_substring(original, result, start, end, size);

    printf("Original: %s\n", original);
    printf("Substring [%d to %d]: %s\n", start, end, result);

    return 0;
}
