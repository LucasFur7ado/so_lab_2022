#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// RECIBE UN num COMO ARGUMENTO, IMPRIME
// algo num VECES SOLO SI ES SUPER USUARIO
// Y LUEGO APAGA EL EQUIPO

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "%s", "Faltan argumentos \n");
    exit(EXIT_FAILURE);
  }

  pid_t pid, pid_2;
  uid_t uid;
  uid = geteuid();
  int num = strtol(argv[1], NULL, 10);

  if (uid != 0)
  {
    fprintf(stderr, "%s", "No eres super \n");
    exit(EXIT_FAILURE);
  }
  pid = fork();
  if (pid == 0)
  {
    for (int i = 0; i < num; i++)
      printf("Apagando el equipo...\n");
    exit(0);
  }
  else if (pid < 0)
  {
    fprintf(stderr, "%s", "Hubo un error \n");
    exit(EXIT_FAILURE);
  }
  pid_2 = fork();
  if (pid_2 == 0)
    execlp("/sbin/shutdown", "shutdown -h now", NULL);
  else if (pid_2 < 0)
  {
    fprintf(stderr, "%s", "Hubo un error \n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
