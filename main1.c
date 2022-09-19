#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

// IMPRIME PADRE, HIJO Y EJECUTA ls

int main()
{
  pid_t pid;
  pid = fork();
  if (pid > 0)
  {
    printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
  }
  else if (pid == 0)
  {
    printf("Soy el hijo (%d, de %d)\n", getpid(), getppid());
    execlp("/bin/ls", "ls", NULL);
  }
  else if (pid < 0)
    printf("Hubo un error");
  else
  {
    wait(NULL);
    printf("Finaliza el proceso padre");
  }

  return 0;
}
