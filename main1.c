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
  if (argc < 2)
  {
    fprintf(stderr, "%s", "Faltan argumentos \n");
    exit(EXIT_FAILURE);
  }

  pid_t pid;
  pid = fork();

  if (pid == 0)
  {

    char cadena[30] = "/bin/";
    strcat(cadena, argv[1]);
    execlp(cadena, argv[1], NULL);
    exit(0);
  }
  else if (pid < 0)
  {
    fprintf(stderr, "%s", "Hubo un error \n");
    exit(EXIT_FAILURE);
  }
  else
  {
    wait(NULL);
    printf("Finaliza el proceso padre \n");
  }
  exit(EXIT_SUCCESS);
}
