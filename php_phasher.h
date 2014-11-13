
#ifndef PHP_PHASHER_H
#define PHP_PHASHER_H

extern zend_module_entry phasher_module_entry;
#define phpext_phasher_ptr &phasher_module_entry

#define PHP_PHASHER_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_PHASHER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PHASHER_API __attribute__ ((visibility("default")))
#else
#	define PHP_PHASHER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

// #ifdef __cplusplus
// extern "C" {
// #endif
// #include <pHash.h>
// #ifdef __cplusplus
// }
// #endif

PHP_MINIT_FUNCTION(phasher);
PHP_MSHUTDOWN_FUNCTION(phasher);
PHP_RINIT_FUNCTION(phasher);
PHP_RSHUTDOWN_FUNCTION(phasher);
PHP_MINFO_FUNCTION(phasher);

PHP_FUNCTION(phasher_image_hash);	/* For testing, remove later. */

#ifdef ZTS
#define PHASHER_G(v) TSRMG(phasher_globals_id, zend_phasher_globals *, v)
#else
#define PHASHER_G(v) (phasher_globals.v)
#endif

#endif	/* PHP_PHASHER_H */

