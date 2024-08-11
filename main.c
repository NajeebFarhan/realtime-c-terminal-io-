#include <stdio.h>
#include <unistd.h>
#include "terminal_io.h"

int main()
{
    // Hide cursor
    printf("\e[?25l");

    char key;

    initTermios(0);                           // Initialize with no echo
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Make stdin non-blocking

    while (key != 'q')
    {
        for (int i = 0; i < 20; i++)
        {
            usleep(100000); // Sleep for 100ms to control the loop speed

            if (kbhit())
            { // Check if a key is pressed
                key = getchar();
                printf("%c   \n", key);
            }
            else
                printf("loop\n");
        }
        // Move cursor back to top
        printf("\e[%iA", 20);
    }

    // Show cursor
    printf("\e[?25h");
    resetTermios(); // Restore terminal settings
    // Clear screen
    printf("\e[2J\e[H");

    return 0;
}
