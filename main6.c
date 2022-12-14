#include <syslog.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

// ENVIA MENSAJES DE DEPURACION CON syslog
// A UN GRUPO DE TELEGRAM

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        openlog("Logs", LOG_PID, LOG_USER);

        syslog(LOG_INFO, "Comienza el registro de logs");
        syslog(LOG_DEBUG, "Debug message");

        char pid_string[100];
        int numero = getpid();
        sprintf(pid_string, "%d", numero);

        char command[200] = "journalctl _PID=";
        strcat(command, pid_string);
	system(command);
        strcat(command, "> syslogs.txt");

        system(command);
        execl("/bin/curl", "curl", "-X", "POST", "https://api.telegram.org/bot<BOT_KEY>/sendDocument", "-F", "chat_id=<CHAT_ID>", "-F", "document=@syslogs.txt", NULL);
        printf("Logs enviados \n");

        closelog();
    }
    else if (pid < 0)
    {
        fprintf(stderr, "%s", "Hubo un error \n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
