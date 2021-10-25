#include <stdlib.h>
#include <sys/utsname.h>
#include <string.h>
#include <stdio.h>

int main(){
	struct utsname x;
	uname(&x);
	printf("Sysname: %s\n", x.sysname);
	printf("Nodename: %s\n", x.nodename);
	printf("Release: %s\n", x.release);
	printf("Version: %s\n", x.version);
	printf("Machine: %s\n", x.machine);
	printf("DomainName: %s\n", x.domainname);

return 1;
}
