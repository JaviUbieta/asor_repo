#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
	struct passwd *pws;
	pws = getpwuid(getuid());
	printf("identificador de usuario real del proceso actual.: %d\n", getuid());
	printf("Nombre de usuario real del proceso actual.: %s\n", pws->pw_name);
	printf("Directorio home de usuario real del proceso actual.: %s\n", pws->pw_dir);
	printf("Descripción del usuario de usuario real del proceso actual.: %s\n", pws->pw_gecos);
	
	pws = getpwuid(geteuid());
	printf("identificador de usuario efectivo del proceso actual.: %d\n", geteuid());
	printf("Nombre de usuario de usuario efectivo del proceso actual.: %s\n", pws->pw_name);
	printf("Directorio home de usuario efectivo del proceso actual.: %s\n", pws->pw_dir);
	printf("Descripción de usuario efectivo del proceso actual.: %s\n", pws->pw_gecos);
return 1;
}
