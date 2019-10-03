/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/03 15:41:22 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_init_gvar(void)
{
	g_block = 0;
	g_flags = 0;
	g_pw_s = 0;
	g_n_size = 0;
	g_grp_s = 0;
	g_path = NULL;
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

void			ft_ac_two(char **av, char **root)
{
	if (av[1][0] == '-' && av[1][1])
	{
		ft_assign_ls_flags(av[1]);
		*root = ft_strdup("./");
	}
	else
	{
		if (av[1][ft_strlen(av[1]) - 1] != '/')
			*root = ft_strjoin(av[1], "/");
		else
			*root = ft_strdup(av[1]);
	}
}

int				main(int ac, char *av[])
{
	int		i;
	int		title;

	i = 1;
	title = 0;
	ft_init_gvar();
	if (ac == 1)
		ft_ls(ft_strdup("./"));
	else if (ac > 1)
	{
		while (i < ac && av[i][0] == '-' && av[i][1])
		{
			ft_assign_ls_flags(av[i]);
			++i;
		}
		if (av[i] == NULL)
			ft_ls(ft_strdup("./"));
		else
		{
			if (ac - i > 1)
				title = 1;
			while (i < ac && av[i])
			{
				if (title)
					ft_printf("%s:\n", av[i]);
				ft_ls(ft_strjoin(av[i], "/"));
				if (title && ac - i > 1)
					ft_printf("\n");
				i++;
			}
		}
	}
	system("leaks ft_ls");
	return (0);
}
