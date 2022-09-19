#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

// RECIBE DOS ARGUMENTOS, file_name y
// directory. COPIA file_name EN directory
// Y ENVIA EL ARCHIVO A TELEGRAM

int main(int argc, char *argv[])
{
    pid_t pid, pid_2;
    pid = fork();
    if (pid > 0)
        printf("Soy el padre (%d, hijo de nadie %d)\n", getpid(), getppid());
    else if (pid == 0)
    {
        if (access("/home/tolteca/Escritorio/", F_OK) != -1)
        {
            printf("IF");
            execl("/bin/cp", "cp", argv[1], argv[2], NULL);
            exit(0);
        }
        else
            printf("No se encontró el directorio");
        exit(0);
    }
    else if (pid < 0)
        printf("Hubo un error");

    pid_2 = fork();
    if (pid_2 == 0)
    {
        char url[200] = "document=@";
        strcat(url, argv[2]);
        strcat(url, argv[1]);

        execl("/bin/curl", "curl", "-X", "POST", "https://api.telegram.org/bot5737142449:AAFfblY1GmUIW_ZT3-F9YXhOJNVm1acYD0A/sendDocument", "-F", "chat_id=-732764355", "-F", url, NULL);
        printf("Archivo enviado");
        exit(0);
    }
    else if (pid_2 < 0)
        printf("Hubo un error");

    return 0;
}
