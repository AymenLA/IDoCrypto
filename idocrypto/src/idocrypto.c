#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include <openssl/sha.h>
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
        /* OpenSSL SHA interfaces return 1 if OK, 0 if error */
        if(sha256_ret != 1) 
        {
            app_ret = app_ok;
        }
        else
        {
            app_ret = app_ressource_error;
        }
    }
    else
    {
        app_ret = app_param_error;
    }
    
    return app_ok;
}

int32_t idocrypto_sha256_update (SHA256_CTX *ctx, const void *data, size_t len)
{
    enum app_error app_ret = app_error;
    int32_t sha256_ret = 0;

    if(ctx != NULL && data != NULL && len > (size_t)0)
    {
        sha256_ret = SHA256_Update (ctx, data, len);
        /* OpenSSL SHA interfaces return 1 if OK, 0 if error */
        if(sha256_ret != 1) 
        {
            app_ret = app_ok;
        }
        else
        {
            app_ret = app_ressource_error;
        }
    }
    else
    {
        app_ret = app_param_error;
    }

    return app_ok;
}

int32_t idocrypto_sha256_final (unsigned char *md, SHA256_CTX *ctx)
{
    enum app_error app_ret = app_error;
    int32_t sha256_ret = 0;

    if(md != NULL && ctx != NULL)
    {
        sha256_ret = SHA256_Final (md, ctx);
        /* OpenSSL SHA interfaces return 1 if OK, 0 if error */
        if(sha256_ret != 1) 
        {
            app_ret = app_ok;
        }
        else
        {
            app_ret = app_ressource_error;
        }
    }
    else
    {
        app_ret = app_param_error;
    }

    return app_ok;
}

/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
