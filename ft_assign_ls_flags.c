#include "ft_ls.h"

int ft_assign_ls_flags(char *s){
	int i;
	int flags;

	i = 1;
	while(s[i]){
		if (s[i] == 'R')
			flags |= 1;
		else if (s[i] == 'a')
			flags |= 2;
		i++;
	}
	return flags;
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

int			ft_hidden_dir(char *s){

	if (s[0] == '.'&&  !s[1])
		return 0;
	else if (s[0] == '.' && s[1] == '.')
		return 0;
	return 1;
}