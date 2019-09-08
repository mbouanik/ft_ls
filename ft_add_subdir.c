/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:54:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/07 18:02:58 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_add_subdir(t_dir_name** nsub_dir ,char * str){
	
	t_dir_name *index;
	t_dir_name * new_dir;
	t_dir_name * tmp;


	new_dir = ft_new_subdir(str);
	if(*nsub_dir == NULL){
		*nsub_dir = new_dir;
	}
	else if (ft_sort_name((*nsub_dir)->name, new_dir->name)){
		new_dir->next = (*nsub_dir);
		 (*nsub_dir) = new_dir;
	}
	else {
		index = *nsub_dir;
		while((*nsub_dir)->next != NULL){
			 if (ft_sort_name((*nsub_dir)->next->name, new_dir->name)) {
				 tmp = (*nsub_dir)->next;
					(*nsub_dir)->next = new_dir;
					new_dir->next = tmp;
					tmp = NULL;
					break ;
			 }
			*nsub_dir = (*nsub_dir)->next;
		}
		if ((*nsub_dir)->next == NULL)
				(*nsub_dir)->next = new_dir;
		*nsub_dir = index;
	}

}