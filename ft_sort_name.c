/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:59:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/07 17:59:56 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	ft_sort_name(char *s1, char *s2){
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		++i;
	// ft_printf("%c ---- %c\n", s1[i], s2[i]);
	if(!s1[i] && s2[i])
		return 0;
	if(s1[i] < s2[i])
		return 0;
	else if (!s2[i] && s1[i])
		return 1;
	else if (s2[i] < s1[i])
		return 1;
	else
		return -1;
}