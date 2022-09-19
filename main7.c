#include <syslog.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

// ENVIA MENSAJES DE DEPURACION CON syslog
// A UN GRUPO DE TELEGRAM
// ( SIN TERMINAR )

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        openlog("Logs", LOG_PID, LOG_USER);

        syslog(LOG_INFO, "Start logging");
        syslog(LOG_DEBUG, "Depuracion");
        printf("ID: %d \n", getpid());

        int num = getpid();
        char full_pid[200] = "_PID=" /* ACA IRÍA num CONCATENADO */;
        execl("/bin/journalctl", "journalctl", full_pid, NULL);

        /*
            HAY QUE CONVERTIR num A CHAR, PARA PODER EJECUTAR
            journalctl. LUEGO HAY QUE OBTENER EL VALOR QUE
            DEVUELVE ESTE ÚLTIMO
        */

        closelog();
        exit(EXIT_SUCCESS);
    }
}