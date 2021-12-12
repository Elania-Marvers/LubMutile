#include "mutile.h"


static int e89_print_base10 (int nbr)
{
  int caract_lue;
  caract_lue = 0;
  char o;
  if (nbr > 10)
    caract_lue += e89_print_base10 (nbr / 10);
  o = (nbr%10) + '0';
  caract_lue += write (1, &o, 1);
  return caract_lue;
}


static int print_base_se(int nbr, int nb)
{
  int caract_lue;
  caract_lue = 0;
  if (nbr > 0)
    {
      char HEX[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
      caract_lue +=  print_base_se((nbr/nb), nb);
      caract_lue +=  write(1, &HEX[nbr%nb], 1);
    }
  
  return caract_lue;
}




static int print_base(int nbr, int nb)
{
  return print_base_se(nbr, nb);
}

int mu_printf(const char *pattern, ...)
{
  int caract_lue;
  caract_lue = 0;
  int i;
  va_list arg;
  i = 0;
  va_start(arg, pattern);
  
  
  char *buffer;
  int bufint;
  char o;
  double bufdoub;
  
  
  while (pattern[i] != '\0')
    {
      if (pattern[i] != '%')
	caract_lue += write(1, &pattern[i], 1);
      else
	{
	  i++;
	  if (pattern[i] == 'd')
	    {
	      bufint = (int) va_arg(arg, int);
	      caract_lue +=  e89_print_base10(bufint);
	    }
	  if (pattern[i] == 's')
	    {
	      buffer = (char *) va_arg(arg, char *);
	      caract_lue +=  write(1, buffer, mu_strlen(buffer));
	    }
	  if (pattern[i] == 'c')
	    {
	      o = (char) va_arg(arg, int);
	      caract_lue +=  write(1, &o, 1);
	    }
	  if (pattern[i] == 'x')
	    {
	      bufint = (int) va_arg(arg, int);
	      caract_lue +=  print_base(bufint, 16);
	    }
	  if (pattern[i] == 'o')
	    {
	      bufint = (int) va_arg(arg, int);
	      caract_lue +=  print_base(bufint, 8);
	    }
	  if (pattern[i] == '%')
	    {
	      caract_lue +=  write(1, "%", 1);
	    }
	  if (pattern[i] == 'f')
	    {
	      bufdoub = (double) va_arg(arg, double);
	      caract_lue += print_base((int) bufdoub, 10);
	      int virgule;
	      virgule = (int) ( ( (double) (bufdoub - (double) ((int) bufdoub)) ) * 1000000);
	      caract_lue +=  write(1, ".", 1);
	      caract_lue +=  print_base(virgule, 10);
	    }
	}
      i++;
    }
  va_end(arg);
  
  return caract_lue;
}