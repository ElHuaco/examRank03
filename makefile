# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 19:51:15 by alejandro         #+#    #+#              #
#    Updated: 2020/10/10 16:11:12 by alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MICRO_PAINT_SRCS = micro_paint_dir/*.c
NAME1 = micro_paint
INCLUDE1 = micro_paint_dir/*.h

GCC = gcc -Werror -Wall -Wextra

all:		$(NAME1)

$(NAME1):
			$(GCC) $(MICRO_PAINT_SRCS) -I $(INCLUDE1) -o $(NAME1)

clean:
			$(RM) ./$(NAME1)

re:			clean all

.PHONY: clean re
