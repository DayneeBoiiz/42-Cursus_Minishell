# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:42:44 by zkasmi            #+#    #+#              #
#    Updated: 2022/04/02 15:49:36 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_perror.c\
ft_putnbr.c\
ft_putnbr_u.c\
hex.c\
ft_putchar.c\
ft_putstr.c\

OBJS = ${SRC:.c=.o}

all: $(NAME)
	@printf "${PURPLE}\e[1mMaking ft_perror please wait....\e\n"

%.o: %.c ft_perror.h
			@-${CC} -c ${CFLAGS} -o $@ $<

$(NAME): ${OBJS}
		@ar -rc ${NAME} ${OBJS}

.PHONY: all clean fclean bonus

clean:
	@rm -f ${OBJS} ${OBJS2}

fclean: clean
	@rm -f ${NAME}

re: fclean all