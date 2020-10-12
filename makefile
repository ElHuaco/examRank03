# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 19:51:15 by alejandro         #+#    #+#              #
#    Updated: 2020/10/12 15:55:21 by aleon-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MICRO_PAINT_SRCS = micro_paint_dir/*.c
NAME1 = micro_paint
INCLUDE1 = micro_paint_dir/*.h

MINI_PAINT_SRCS = mini_paint_dir/*.c
NAME2 = mini_paint
INCLUDE2 = mini_paint_dir/*.h

GCC = gcc -Werror -Wall -Wextra

all:		$(NAME1) $(NAME2)

$(NAME1):
			$(GCC) $(MICRO_PAINT_SRCS) -I $(INCLUDE1) -o $(NAME1)

$(NAME2):
			$(GCC) $(MINI_PAINT_SRCS) -I $(INCLUDE2) -o $(NAME2)

clean:
			$(RM) ./$(NAME1) ./$(NAME2)

re:			clean all

.PHONY: clean re
