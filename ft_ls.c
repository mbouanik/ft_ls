/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/07 18:21:11 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_ls.h"

int ft_ls(char * s)
{
	DIR * dir;
	struct dirent *dp;
	struct stat buf;

	dir = NULL;
	// dir = opendir(s);
	// if(dir == NULL){
	// 	perror("error");
	// return (0);
	// }
	ft_display_dir(dp, dir, &buf, s);
	// closedir(dir);
	return 0;
}

int main(int ac, char  *av[])
{
	char * root;
	int i;

	i = 0;
	
	root = NULL;
	if (!av[1] || av[1][0] != '-'){
		if (!av[1])
		root = strdup("./");
		else{
		while (av[1] && av[1][i])
			++i;
		if (av[1][i - 1] != '/')
			root = ft_strjoin(av[1], "/");
		else
			root = strdup(av[1]);
		}
}
else{
	ft_assign_ls_flags(av[1]);
	if (!av[2])
		root = strdup("./");
		else{
		while (av[2] && av[2][i])
			++i;
		if (av[2][i - 1] != '/')
			root = ft_strjoin(av[2], "/");
		else
			root = strdup(av[2]);
		}
}
	ft_ls(root);
	// free(root);

	
	// ft_printf("%lu\n", -42);
	// printf("%lu\n", -42);

	// ft_printf("%d\n", ft_compare(".AngelaB", ".AngelaA"));
	// ft_printf("%d\n", ft_compare(".Angela", "AngelaA"));
	// ft_printf("%d\n", ft_compare(".Angela", "AngelaA"));

	return 0;
}
