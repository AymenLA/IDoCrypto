/*
 * file name    : idocrypto.h
 * purpose      : various ciphers exemples
 * author       : ME
 * 
 * organiZation : NONE (NO PARTICULARE COPYRIGHTS) 2020
 */
#ifndef _IDOCRYPTO_H_
#define _IDOCRYPTO_H_

#include <openssl/sha.h>

/******************************* GLOBAL DEFINES ******************************/
/* \brief size of hashed buffer, defined to 20 by OpenSSL in order to be compiant to 
    US Federal Information Processing Standard FIPS PUB 180-4 (Secure Hash Standard), 
    ANSI X9.30 */
#define IDC_SHA_DIGEST_LENGTH   SHA_DIGEST_LENGTH

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/

/*********************** PUBLIC FUNCTION DECLARATIONS ************************/

/*
 *  \brief call to initialize a SHA256 Hash
 *  \param [in] ctx context to be given as input
 * 
 *  \return error code, see app_error_codes.h
 */
int32_t idocrypto_sha256_init (SHA256_CTX *ctx);

/*
 *  \brief call to update a SHA256 Hash, to be called repetively as long as needed 
 *  \param [in] ctx context to be given as input
 *  \param [in] data pointer to data to be hashed
 *  \param [in] len size of input data
 * 
 *  \return error code, see app_error_codes.h
 */
int32_t idocrypto_sha256_update (SHA256_CTX *ctx, const void *data, size_t len);

/*
 *  \brief call to obtain the final hash returned in pointer
 *  \param [in] md pointer to hash, must be a valid pointer sized IDC_SHA_DIGEST_LENGTH
 *  \param [in] ctx pointer to context structure
 * 
 *  \return error code, see app_error_codes.h
 */
int32_t idocrypto_SHA256_final (unsigned char *md, SHA256_CTX *ctx);

#endif /* _IDOCRYPTO_H_ */