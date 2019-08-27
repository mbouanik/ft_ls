# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 22:55:01 by mbouanik          #+#    #+#              #
#    Updated: 2019/08/25 21:57:11 by mbouanik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c\
		ft_display_str.c\
		ft_assign_flags.c\
		 ft_display_arg_d.c\
		 ft_display_arg_b.c\
		 ft_display_arg_o.c \
		 ft_display_arg_octal.c\
		 ft_display_arg_u.c\
		 ft_display_arg_x.c\
		 ft_display_arg_xx.c\
		 ft_display_p.c\
		ft_display_arg_uu.c\
		ft_display_arg_dd.c\
		ft_atoi_s.c\
		ft_longtoa.c\
		ft_putstr_octal.c\
		ft_putstr_lo.c\
		ft_putstr_hexa.c\
		ft_putstr_x.c\
		ft_putstr_b.c\
		ft_itostr.c\
		ft_itoustr.c\
		ft_flags_sign.c\
		ft_cp_until.c\
		ft_isdigit.c\
		ft_putstr_g.c\
		ft_strlen_t.c\
		ft_strlen_b.c\
		ft_strlen_hexa.c\
		ft_strlen_num.c\
		ft_isalpha.c\
		ft_isupper.c\
		ft_islower.c\
		ft_memset_g.c\
		ft_display_arg_d_short.c\
		ft_display_arg_d_schar.c\
		ft_display_arg_d_intm.c\
		ft_display_arg_u_us.c\
		ft_display_arg_u_uintm.c\
		ft_display_arg_u_uchar.c\
		ft_display_arg_o_us.c\
		ft_display_arg_o_uchar.c\
		ft_display_arg_o_uintm.c\
		ft_display_arg_x_us.c\
		ft_display_arg_x_uchar.c\
		ft_display_arg_x_uintm.c\
		ft_display_arg_xx_us.c\
		ft_display_arg_xx_uchar.c\
		ft_display_arg_xx_uintm.c\
		ft_display_arg_d_mod.c\
		ft_display_arg_o_mod.c\
		ft_display_arg_x_mod.c\
		ft_display_arg_xx_mod.c\
		ft_display_arg_u_mod.c\
		ft_memset.c\
		ft_isprint.c\
		ft_size.c\
		ft_zero.c\
		ft_hash.c\
		ft_blank.c\
		ft_plus.c\
		ft_minus.c\
		ft_display_arg_c_uni.c\
		ft_display_arg_str_uni.c\
		ft_display_arg_c_uni7.c\
		ft_display_arg_c_uni11.c\
		ft_display_arg_c_uni16.c\
		ft_display_arg_c_uni21.c\
		ft_putstr_float.c\
		ft_display_arg_f.c\
		ft_str_null.c\
		ft_check_size.c\
		ft_display_arg_e.c\
		ft_putstr_float_e.c\
		ft_display_arg_g.c\
		ft_putstr_float_g.c\
		ft_retrieve.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra -O3

all : $(NAME)

$(NAME) :
	gcc -c $(FLAG) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
