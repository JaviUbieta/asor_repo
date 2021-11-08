#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    const char *path = "/home/usuario_vms/holasalvi2.txt";

    umask(0750);

    int f = open(path,O_CREAT,0645);
    if(f == - 1){
        printf("Error al crear el fichero.");
    }

    return 0;
}
