#include "mutile.h"

void mu_die_perror (char *str)
{
      perror(str);
      exit (89);
}