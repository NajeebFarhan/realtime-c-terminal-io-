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
        //! Your own code here, inside the while loop
        for (int i = 0; i < 20; i++)
        {

            printf("LooP\n");
            usleep(100000); // Sleep for 100ms to control the loop speed

            if (key_pressed())
            { // Check if a key is pressed
                key = getchar();
                printf("Key pressed: %c\n", key);
            }
        }

        // Move cursor back to top
        printf("\e[%iA", 20); // Enter the height in argument to move to top
    }

    // Show cursor
    printf("\e[?25h");
    resetTermios(); // Restore terminal settings
    // Clear screen
    printf("\e[2J\e[H");

    return 0;
}
