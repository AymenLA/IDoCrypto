#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include "idocrypto.h"


/******************************* GLOBAL DEFINES ******************************/

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/
int32_t idocrypto_sha256_init (SHA256_CTX *ctx)
{
    enum app_error app_ret = app_error;
    int32_t sha256_ret = 0;
    
    if(ctx != NULL)
    {
        printf("IDC_SHA256> [DBG] : initializing\n");

        sha256_ret = SHA256_Init(ctx);

        // TODO : verify sha256_ret value 
        app_ret = app_ok;
    }
    else
    {
        app_ret = app_param_error;
    }
    
    return app_ok;
}
/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
