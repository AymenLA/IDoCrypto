#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include "dump.h"


/******************************* GLOBAL DEFINES ******************************/
#define RET_DIV(a,b) (a/b)
#define RET_MOD(a,b) (a%b)

#define ADDR_FORMAT         "0x%06X    "
#define BYTE_FORMAT         "%02X "
#define EMPTY_BYTE_FORMAT   "   "
#define MIDLINE_FORMAT      "    "

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/
int32_t dump_tab(uint8_t *tab, uint32_t tab_size, uint32_t start_addr)
{
    uint32_t ligne_c = 0, column_c = 0;
    uint32_t param1 = 756, param2 = 16, div_val = 0, mod_val = 0;
    int32_t error = app_error;
    if(NULL != tab &&
       0xFFFFFF >= tab_size &&
       0x0 < tab_size)
    {
        printf("PSEUDO_DUMP> [DBG] tab @0x%08X size %d start address @0x%08X\n", tab, tab_size, start_addr);
        /* output exemple :                                                                               */
        /* 1- printing a table of size 32, starting from adress 0x00                                      */
        /* 0x000000    0x00 0x11 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000010    0x00 0x11 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /*                                                                                                */
        /* 2- printing a table of size 48, starting from adress 0x08                                      */
        /* 0x000000                                               0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000010    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000020    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000030    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF                                            */
        /*                                                                                                */
        /* 3- printing a table of size 83, starting from adress 0x17                                      */
        /* 0x000010                                       0x11    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000020    0x00 0x11 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000030    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
        /* 0x000040    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF    0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF */
        /* 0x000050    0xFF 0xFF 0xFF 0xFF                                                                */
        /*                                                                                                */

        for (ligne_c = RET_DIV(start_addr, param2); ligne_c < RET_DIV(tab_size, param2); ligne_c++)
        {
            printf(ADDR_FORMAT MIDLINE_FORMAT, ligne_c * param2);
            for(column_c = 0; column_c < param2; column_c++)
            {
                if(ligne_c * param2 + column_c >= start_addr)
                {
                    printf(BYTE_FORMAT,tab[ligne_c * param2 + column_c]);
                }
                else
                {
                    printf(EMPTY_BYTE_FORMAT);
                }

                if(column_c == ((param2/2) -1))
                {
                    printf(MIDLINE_FORMAT);
                }
            }
        
            printf("\n");
        }

        if(RET_MOD(tab_size, param2) != 0)
        {
            printf(ADDR_FORMAT MIDLINE_FORMAT, ligne_c * param2);
            for(column_c = 0; column_c < RET_MOD(tab_size, param2); column_c++)
            {
                if(ligne_c * param2 + column_c >= start_addr)
                {
                    printf(BYTE_FORMAT,tab[ligne_c * param2 + column_c]);
                }
                else
                {
                    printf(EMPTY_BYTE_FORMAT);
                }

                if(column_c == ((param2/2) -1))
                {
                    printf(MIDLINE_FORMAT);
                }
            }
            
            printf("\n");
        }

        error = app_ok;
    }
    else
    {
        error = app_param_error;
    }
    
    return error;
}
/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
