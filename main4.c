#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// RECIBE UN num COMO ARGUMENTO, IMPRIME
// algo num VECES SOLO SI ES SUPER USUARIO
// Y LUEGO APAGA EL EQUIPO

int main(int argc, char *argv[])
{

  pid_t pid, pid_2;
  uid_t uid;
  uid = geteuid();
  int num = strtol(argv[1], NULL, 10);

  if (uid != 0)
  {
    printf("No eres super\n");
    return 1;
  }
  pid = fork();
  if (pid == 0)
  {
    for (int i = 0; i < num; i++)
      printf("Apagando el equipo...\n");
    exit(0);
  }
  else if (pid < 0)
    printf("Hubo un error");
  pid_2 = fork();
  if (pid_2 == 0)
    execlp("/sbin/shutdown", "shutdown -h now", NULL);
  else if (pid_2 < 0)
    printf("Hubo un error");

  return 0;
}
