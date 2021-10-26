#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){
	printf("The maximum number of links to the file.: %ld\n", pathconf("/", _PC_LINK_MAX));
	printf("The maximum length of a filename in the directory path or fd that the process is allowed to create.: %ld\n", pathconf("/",  _PC_NAME_MAX));
	printf("The maximum length of a relative pathname when path or fd is the current working directory.: %ld\n", pathconf("/", _PC_PATH_MAX));

return 1;
}
