# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 09:48:51 by mbouanik          #+#    #+#              #
#    Updated: 2019/10/07 11:01:37 by mbouanik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 	ft_add_subdir.c\
		ft_assign_ls_flags.c\
		ft_display_dir.c\
		ft_display_sub_dir.c\
		ft_free_subdir.c\
		ft_ls.c\
		ft_memalloc.c\
		ft_new_subdir.c\
		ft_read_mode.c\
		ft_readlink.c\
		ft_sort_by_time.c\
		ft_sort_name.c\
		ft_strcat.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strnew.c\
		ft_strsub.c\
		ft_memset.c\
		ft_sort_args.c\
		ft_one_arg.c\
		ft_init_g_var.c\



OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra
LIB_PATH = -L ft_printf/
LIB = ft_printf/libftprintf.a
INC = -I includes/
INC_LIBFT = -I ft_printf/

all : $(NAME)

$(NAME) : ft_printf $(OBJ)
	@$(CC) $(LIB_PATH) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

ft_printf :
	@make -C ft_printf/

clean :
	make clean -C ft_printf/
	rm -f $(OBJ)

fclean : clean
	make fclean -C ft_printf/
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re, ft_printf