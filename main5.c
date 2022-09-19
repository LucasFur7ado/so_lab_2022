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
    if (argc < 2)
    {
        fprintf(stderr, "%s", "Faltan argumentos \n");
        exit(EXIT_FAILURE);
    }
    pid_t pid, pid_2;
    pid = fork();
    if (pid == 0)
    {
        if (access(argv[2], F_OK) != -1)
        {
            execl("/bin/cp", "cp", argv[1], argv[2], NULL);
            exit(0);
        }
        else
        {
            fprintf(stderr, "%s", "No se encontro el directorio \n");
            exit(EXIT_FAILURE);
        }
        exit(0);
    }
    else if (pid < 0)
    {
        fprintf(stderr, "%s", "Hubo un error \n");
        exit(EXIT_FAILURE);
    }

    pid_2 = fork();
    if (pid_2 == 0)
    {
        char url[200] = "document=@";
        strcat(url, argv[1]);

        execl("/bin/curl", "curl", "-X", "POST", "https://api.telegram.org/bot5737142449:AAFfblY1GmUIW_ZT3-F9YXhOJNVm1acYD0A/sendDocument", "-F", "chat_id=-732764355", "-F", url, NULL);
        printf("Archivo enviado \n");
        exit(0);
    }
    else if (pid_2 < 0)
    {
        fprintf(stderr, "%s", "Hubo un error \n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
