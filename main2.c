#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// RECIBE num COMO ARGUMENTO E IMPRIME
// LA FECHA num VECES

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "%s", "Faltan argumentos \n");
    exit(EXIT_FAILURE);
  }

  pid_t pid;
  int num = strtol(argv[1], NULL, 10);
  for (int i = 0; i < num; i++)
  {
    pid = fork();
    if (pid == 0)
    {

      printf("========================\n");
      printf("id: %d \n", getpid());
      time_t tiempo = time(0);
      struct tm *tlocal = localtime(&tiempo);
      char output[128];
      strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
      printf("%s\n", output);
      printf("=======================\n");

      exit(0);
    }
    else if (pid < 0)
    {
      fprintf(stderr, "%s", "Hubo un error \n");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
