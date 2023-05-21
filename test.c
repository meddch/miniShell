#include <stdio.h>

// Define the flags as constants using bitwise left shift
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_C (1 << 2)
#define FLAG_D (1 << 3)

// Define the enum with the combined flags
enum {
    FLAG_SET_AB = FLAG_A | FLAG_B,
    FLAG_SET_CD = FLAG_C | FLAG_D,
    FLAG_SET_ALL = FLAG_A | FLAG_B | FLAG_C | FLAG_D
};

int main() {
    int flags = FLAG_D; // Set the flags to FLAG_SET_AB

    // Check if individual flags are set
    // if (flags & FLAG_A)
    //     printf("Flag A is set\n");
    // if (flags & FLAG_B)
    //     printf("Flag B is set\n");
    // if (flags & FLAG_C)
    //     printf("Flag C is set\n");
    // if (flags & FLAG_D)
    //     printf("Flag D is set\n");

    // Check if the combined flag sets are set
    if (FLAG_SET_AB)
        printf("Flags A and B are set\n");
    // if (flags & FLAG_SET_CD)
    //     printf("Flags C and D are set\n");
    // if (flags & FLAG_SET_ALL)
    //     printf("All flags are set\n");

    return 0;
}
