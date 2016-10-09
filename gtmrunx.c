#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "gtmxc_types.h"
#define BUF_LEN 1024

struct termios saved_attributes;

reset_input_mode (void) 
{ 
	tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes); 
} 
 
int main(int argc, char *argv[])
{
        gtm_char_t      msgbuf[BUF_LEN];
        gtm_status_t    status;
 
	if (isatty (STDIN_FILENO)) 
	{ 
		tcgetattr (STDIN_FILENO, &saved_attributes); 
		atexit ((void(*)())reset_input_mode); 
	}

        status = gtm_init();
        if (status != 0)
        {
            gtm_zstatus(msgbuf, BUF_LEN);
            return status;
        }
	status = gtm_ci("gtm");
        if (status != 0)
        {
            gtm_zstatus(msgbuf, BUF_LEN);
            fprintf(stderr, "%s\n", msgbuf);
            return status;
        }
        return 0;
}
