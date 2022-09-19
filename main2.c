#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

// RECIBE UN COMANDO DE LA CLI COMO ARGUMENTO
// Y LO EJECUTA

int main(int argc, char *argv[])
{
  pid_t pid;
  pid = fork();

  if (pid == 0)
  {

    char cadena[30] = "/bin/";
    strcat(cadena, argv[1]);
    execlp(cadena, argv[1], NULL);
    sleep(20000);
    exit(0);
  }
  else if (pid < 0)
  {
    printf("Hubo un error");
    return 1;
  }
  else
    wait(NULL);
  return 0;
}
