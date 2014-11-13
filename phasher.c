#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_phasher.h"

/* True global resources - no need for thread safety here */
static int le_phasher;

const zend_function_entry phasher_functions[] = {
	PHP_FE(phasher_image_hash,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in phasher_functions[] */
};

zend_module_entry phasher_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"phasher",
	phasher_functions,
	PHP_MINIT(phasher),
	PHP_MSHUTDOWN(phasher),
	PHP_RINIT(phasher),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(phasher),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(phasher),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_PHASHER_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHASHER
ZEND_GET_MODULE(phasher)
#endif

PHP_MINIT_FUNCTION(phasher)
{
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phasher)
{
	return SUCCESS;
}

PHP_RINIT_FUNCTION(phasher)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phasher)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(phasher)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "phasher support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}

PHP_FUNCTION(phasher_image_hash)
{
	char *file = NULL;
	int file_len, len;
	char *strg;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &file, &file_len) == FAILURE) {
		return;
	}
    
    /*
    ulong64 * return_res;
	ulong64 *hash = (ulong64 *)malloc(sizeof(ulong64));
    int ret = ph_dct_imagehash(file, *hash);
    // somehow return hash as string
    */

	len = spprintf(&strg, 0, "File %s", file);
	RETURN_STRINGL(strg, len, 0);
}

