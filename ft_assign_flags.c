#include "ft_ls.h"

void ft_assign_ls_flags(char *s){
	int i;

	i = 0;
	while(s[i])
		i++;
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