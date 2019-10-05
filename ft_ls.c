/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/05 15:22:22 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_error(char **s1, char *s2, int ac, t_dir_name **folders)
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
		while (i < ac && s1[i])
		{
			dir = opendir(s1[i]);
			if (dir == NULL)
				ft_printf("ft_ls: %.*s: %s\n", ft_strlen(s1[i]),
				s1[i], strerror(errno));
			if (dir)
			{
				(void)closedir(dir);
				ft_sort_args(folders, ft_strdup(s1[i]));
			}
			i++;
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
	int			i;
	t_dir_name	*folders;

	i = 1;
	folders = NULL;
	ft_error(av, NULL, ac, &folders);
	while (i < ac && av[i][0] == '-' && av[i][1] && !(g_flags & 32))
		ft_assign_ls_flags(av[i++]);
	if (av[i] == NULL || ((ac - 1) == i))
		ft_one_arg(av, &folders, i);
	else
	{
		while (folders)
			if (ft_error(NULL, folders->name, ac, NULL))
			{
				ft_printf("%s:\n", folders->name);
				(folders->name[0] == '/' && !folders->name[1]) ?
				ft_ls(ft_strdup(folders->name)) :
				ft_ls(ft_strjoin(folders->name, "/"));
				free_subdir(&folders);
				if (folders)
					ft_printf("\n");
			}
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
