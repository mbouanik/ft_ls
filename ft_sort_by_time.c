/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:10:45 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 11:49:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_sort_by_time(int time1, int time2){

	if (time1 > time2){
		if (g_flags & 4)
			return 1;
		return 0;
	}
	else if (time2 >  time1){
		if (g_flags & 4)
			return 0;
		return 1;
	}
	if (g_flags & 4)
		return 0;
	return 1;
}