/*
 * tryCatch.h
 *
 *  Created on: 12 Dec. 2018.
 *      Author: user
 */

#ifndef TRYCATCH_H_
#define TRYCATCH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

typedef enum
{
	ERR_OK = 0,
	ERR_FAIL,
	ERR_INVALID_ARG,
	ERR_NO_MEM,
	ERR_TIMEOUT,
	ERR_CANT_CREATE_TASK,
	ERR_CANT_CREATE_QUEUE,
	ERR_CANT_CREATE_MUTEX,
	ERR_NO_INITED,
	ERR_INVALID_LEN,
	ERR_CRC
} err_t;

#define _type	err_t
#define _value	ERR_OK

#define _tryBegin	_type __errorVal=_value; \
			int __lineOfErr = 0;

#define _try(x)  	if((__errorVal = x) != _value) {\
			__lineOfErr = __LINE__; \
			goto ExitJmp;\
			}

#define _catch(x) ExitJmp: \
			if(__errorVal != _value)

#define _throw(n) 	__errorVal=n; \
			__lineOfErr = __LINE__;\
			goto ExitJmp;

#define _getErr()	__errorVal
#define _getLine()	__lineOfErr
#define _errorPrint()	main_errorHandler(_getErr(),_getLine(),__FILE__,__FUNCTION__)

extern void main_errorHandler(err_t ERROR,int line,const char *file,const char * func);

#ifdef __cplusplus
}
#endif

#endif /* TRYCATCH_H_ */
