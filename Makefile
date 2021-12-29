# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 02:14:44 by hmokhtar          #+#    #+#              #
#    Updated: 2021/12/28 07:59:53 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

GREEN := $(shell tput -Txterm setaf 2)

all : $(NAME)

%.o : %.c ft_printf.h
	@$(CC) $(FLAGS) -c $<

$(NAME):$(OBJS)
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar cr $@ $(OBJS)
	@echo $(GREEN)"DONE MAKING PRINTF"

clean:
	@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
norm :
	@norminette *.c *.h
