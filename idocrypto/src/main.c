#include <stdio.h>
#include <inttypes.h>

#include "app_error_codes.h"

#include "idocrypto.h"
#include "dump.h"

/******************************* GLOBAL DEFINES ******************************/

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/
uint8_t exemple_tab[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/
int32_t main (void)
{
    SHA256_CTX ctx;
    int32_t sha256_ret = 0;

    uint8_t sha_test[16] = { 0x22, 0x12, 0xa3, 0x65, \
                             0x0b, 0x23, 0xac, 0xff, \
                             0xff, 0xa2, 0x00, 0x36, \
                             0xde, 0xad, 0xbe, 0xef};

    uint8_t sha256_md[IDC_SHA256_DIGEST_LENGTH] = {0};

    printf("MAIN> [DBG] : first print\n");
    printf("MAIN> [DBG] : blah blah\n");

    sha256_ret = idocrypto_sha256_init(&ctx);
    if(sha256_ret == 0)
    {
        printf("MAIN> [DBG] : idocrypto_sha256_init ret = %d\n", sha256_ret);
    }

    sha256_ret = idocrypto_sha256_update(&ctx, sha_test, 16);
    if(sha256_ret == 0)
    {
        printf("MAIN> [DBG] : idocrypto_sha256_update ret = %d\n", sha256_ret);
    }

    sha256_ret = idocrypto_sha256_final((unsigned char *)sha256_md, &ctx);
    if(sha256_ret == 0)
    {
        printf("MAIN> [DBG] : idocrypto_sha256_final ret = %d\n", sha256_ret);

        printf("input data = ");
        for (uint8_t i = 0; i< 16; i++)
        {
            printf("%x", sha_test[i]);
        }
        printf("\n");

        printf("output data = ");
        for (uint8_t i = 0; i< IDC_SHA256_DIGEST_LENGTH; i++)
        {
            printf("%x", sha256_md[i]);
        }
        printf("\n");
    }

    dump_tab(sha_test, 16, 0);

    dump_tab(sha256_md, IDC_SHA256_DIGEST_LENGTH, 0);
    return app_ok;
}
/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/
