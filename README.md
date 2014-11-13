README

```console
ralphschindler at Ralph's MacBook Pro in ~/Projects/phasher on master* at 13:42:07
$ php -n -dextension_dir=/Users/ralphschindler/Projects/phasher/.libs -dextension=phasher.so -a
Interactive shell

php > echo phasher_image_hash('./file');
File ./file
php > exit
```