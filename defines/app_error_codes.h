/*
 * file name    : app_error_codes.h
 * purpose      : all error codes and return values are defines here
 * author       : ME
 * 
 * organiZation : NONE (NO PARTICULARE COPYRIGHTS) 2020
 */
#ifndef _APP_ERROR_CODES_H_
#define _APP_ERROR_CODES_H_
/******************************* GLOBAL DEFINES ******************************/

/*********************** PRIVATE FUNCTION PROTOTYPES *************************/

/******************************* GLOBAL VARIABLES ****************************/
typedef enum app_error
{
    app_init_error = -5,
    app_ressource_error = -4,
    app_execution_error = -3,
    app_param_error = -2,
    app_error   = -1,
    app_ok      = 0,
    app_warning = 1
} e_app_error;
/*********************** PUBLIC FUNCTION DECLARATIONS ************************/

/*********************** PRIVATE FUNCTION DECLARATIONS ***********************/

#endif /* _APP_ERROR_CODES_H_ */