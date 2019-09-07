void ft_assign_flags(char *s){

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