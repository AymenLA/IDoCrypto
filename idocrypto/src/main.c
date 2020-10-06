#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include "idocrypto.h"

/******************************* GLOBAL DEFINES ******************************/

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/
int32_t main (void)
{
    SHA256_CTX ctx;
    int32_t sha256_ret = 0;
    printf("MAIN> [DBG] : first print\n");
    printf("MAIN> [DBG] : blah blah\n");

    sha256_ret = idocrypto_sha256_init(&ctx);
    if(sha256_ret != 0)
    {
        printf("MAIN> [DBG] : idocrypto_sha256_init ret = %d\n", sha256_ret);
    }
    return app_ok;
}
/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
