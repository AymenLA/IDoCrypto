#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include "dump.h"

/******************************* GLOBAL DEFINES ******************************/

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/
uint8_t exemple_tab[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/
int32_t main (void)
{
    printf("MAIN> [DBG] : first print\n");
    printf("MAIN> [DBG] : blah blah\n");

    dump_tab(exemple_tab, 16, 0);
    return app_ok;
}
/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
