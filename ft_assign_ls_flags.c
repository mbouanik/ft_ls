#include "ft_ls.h"



int ft_check_flags(int c){
	char *f = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
	int i;

	i = 0;
	while (f[i])
	{
		if (c == f[i])
			return 1;
		i++;
	}
	return 0;
}
void		ft_assign_ls_flags(char *s){
	int i;

	i = 1;
	while (s[i])
	{
		if (!ft_check_flags(s[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n", s[i]);
			ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
			exit(-1);
		}
		if (s[i] == 'R')
			g_flags |= 1;
		else if (s[i] == 'a')
			g_flags |= 2;
		else if (s[i] == 'r')
			g_flags |= 4;
		else if (s[i] == 't')
			g_flags |= 8;
		else if (s[i] == 'l')
			g_flags |= 16;
		i++;
	}
}

size_t			lenname(DIR * dir, struct dirent * dp){

	size_t size;
	struct dirent * index;

	index = dp;

	size = 0;
	while ((dp = readdir(dir)) != NULL) {
		if (dp->d_namlen > size)
			size = dp->d_namlen ;
		}
	dp = index;
    rewinddir(dir);
	return size;
    
}

int			ft_hidden_dir(char *s)
{
	if (s[0] == '.' && !s[1])
		return (0);
	else if (s[0] == '.' && s[1] == '.')
		return (0);
	return (1);
}
