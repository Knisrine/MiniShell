#include "minishell.h"
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int i;
	int k;
	len = ft_strlen(to_find);
	
	i = 0;
	k = 0;
	while (str[i])
	{
		while(str[i + k] == to_find[k])
		{		
			k++;
			if (k == len)
				return (&str[i]);
		}
		i++;
	}
	return NULL;
}