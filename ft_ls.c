/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 13:49:32 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_init_gvar(void)
{
	g_flags = 0;
	g_pw_s = 0;
	g_n_size = 0;
	g_grp_s = 0;
}

int				ft_ls(char *s)
{
	DIR				*dir;
	struct dirent	*dp;
	struct stat		buf;

	dir = NULL;
	dp = NULL;
	bzero(&buf, sizeof(struct stat));
	ft_display_dir(dp, dir, buf, s);
	return (0);
}

int				main(int ac, char *av[])
{
	char	*root;
	int		i;

	i = 0;
	root = NULL;
	ft_init_gvar();
	if (ac == 1)
	{
		if (!av[1])
			root = ft_strdup("./");
		else
		{
			while (av[1] && av[1][i])
				++i;
			if (av[1][i - 1] != '/')
				root = ft_strjoin(av[1], "/");
			else
				root = ft_strdup(av[1]);
		}
	}
	else if (av[1] && !av[2])
	{
		if (av[1][0] == '-' && av[1][1])
		{
			ft_assign_ls_flags(av[1]);
			root = ft_strdup("./");
		}
		else
			root = ft_strjoin(av[1], "/");
	}
	else
	{
		ft_assign_ls_flags(av[1]);
		if (!av[2])
			root = ft_strdup("./");
		else
		{
			while (av[2] && av[2][i])
				++i;
			if (av[2][i - 1] != '/')
				root = ft_strjoin(av[2], "/");
			else
				root = ft_strdup(av[2]);
		}
	}
	ft_ls(root);
	// system("leaks ft_ls");
	return (0);
}
