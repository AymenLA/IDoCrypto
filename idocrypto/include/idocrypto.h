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

/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/

#endif /* _IDOCRYPTO_H_ */