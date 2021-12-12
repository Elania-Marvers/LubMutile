#include "mutile.h"


int mu_strcmp(char *sA, char *sB)
{
	int i;
	i = 0;
	while (sA[i] != '\0' || sB[i] != '\0')
	{
		if(sA[i] != sB[i])
		{
			if(sA[i] < sB[i])
				return -1;
			else
				return 1;
		}

		i++;
	}
	return 0;
}