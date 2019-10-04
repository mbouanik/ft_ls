/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/04 11:55:13 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_error(char **s1, char *s2, int ac)
{
	DIR			*dir;
	int			r;
	int			i;

	r = 1;
	i = 1;
	dir = NULL;
	if (s1)
	{
		while (i < ac && s1[i][0] == '-' && s1[i][1] && !(g_flags & 32))
			i++;
		while (s1[i])
		{
			dir = opendir(s1[i]);
			if (dir == NULL)
				ft_printf("ft_ls: %.*s: %s\n", ft_strlen(s1[i]),
				s1[i], strerror(errno));
			i++;
			if (dir)
				(void)closedir(dir);
		}
	}
	else
	{
		dir = opendir(s2);
		if (dir == NULL)
			r = 0;
		if (dir)
			(void)closedir(dir);
	}
	return (r);
}

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

void			ft_ac_more_than_one(char **av, int ac)
{
	int		i;
	int		title;
	t_dir_name folders;

	i = 1;
	title = 0;
	while (i < ac && av[i][0] == '-' && av[i][1] && !(g_flags & 32))
		ft_assign_ls_flags(av[i++]);
	ft_error(av, NULL, ac);
	if (av[i] == NULL)
		ft_ls(ft_strdup("./"));
	else
	{
		if (ac - i > 1)
			title = 1;
		while (i < ac && av[i])
		{
			if (ft_error(NULL, av[i], ac))
			{
				if (title)
					ft_printf("%s:\n", av[i]);
				ft_ls(ft_strjoin(av[i], "/"));
				if (title && (ac - 1) != i)
					ft_printf("\n");
			}
			i++;
		}
			ft_ls(ft_strjoin(av[i], "/"));
	}
}

int				main(int ac, char *av[])
{
	ft_init_gvar();
	if (ac == 1)
		ft_ls(ft_strdup("./"));
	else if (ac > 1)
		ft_ac_more_than_one(av, ac);
	// system("leaks ft_ls");
	return (0);
}
