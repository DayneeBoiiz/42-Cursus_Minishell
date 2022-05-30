# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkasmi <zkasmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 18:51:23 by sayar             #+#    #+#              #
#    Updated: 2022/04/14 00:09:19 by zkasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

RED=\033[0;31m

GREEN=\033[0;32m

GREY=\x1b[30m

RED=\x1b[31m

YELLOW=\x1b[33m

BLUE=\x1b[34m

PURPLE=\x1b[35m

CYAN=\x1b[36m

WHITE=\x1b[37m

CC = cc

CFLAGS = -Wall -Wextra -Werror

RD = -lreadline -L /Users/zkasmi/homebrew/Cellar/readline/8.1.2/lib  -I /Users/zkasmi/homebrew/Cellar/readline/8.1.2/include

SRC_mini = minishell.c

ALL_OF_SRC = ./built_in/cd.c\
			 ./built_in/cdutils.c\
			 ./built_in/cdutils2.c\
			 ./built_in/cdutils3.c\
			 change.c\
			 dollar.c\
			 error.c\
			 errutils.c\
			 exec.c\
			 exec_utils.c\
			 ./built_in/export.c\
			 ./built_in/export_utils.c\
			 ./built_in/export_utils_1.c\
			 free.c\
			 ft_check.c\
			 ./built_in/echo.c\
			 line.c\
			 ./built_in/ft_echo_utils.c\
			 ./built_in/ft_echo_utils1.c\
			 ./built_in/ft_env.c\
			 ./built_in/ft_exit.c\
			 ft_fork.c\
			 get_redirection.c\
			 getdir.c\
			 getpath.c\
			 heredoc.c\
			 init.c\
			 ./built_in/lst_env.c\
			 ./built_in/pwd.c\
			 redirections.c\
			 ./built_in/set_env.c\
			 ./built_in/tokens.c\
			 set_fun.c\
			 redirections1.c\
			 redirections2.c\
			 redirections3.c\
			 signal.c\
			 ./built_in/unset.c\
			 ./built_in/unset_utils.c\
			 ./built_in/export_utils_2.c\
			 ./built_in/utils.c\

OBJ_mini = ${SRC_mini:.c=.o}

OBJ_SRC = ${ALL_OF_SRC:.c=.o}

OBJ_Lib = ./Libft/libft.a

OBJ_perror = ./ft_perror/libftprintf.a

all: Lib perror $(NAME)
		@printf "${CYAN}\033[1mTo compile ./minishell\033\n"
		@printf "${RED}\e[1mEnjoy this simple not beautiful As a Shell (•̀ᴗ•́ )و\e\n"

%.o: %.c minishell.h
			@-${CC} $(CFLAGS) -I /Users/zkasmi/homebrew/Cellar/readline/8.1.2/include -c -o $@ $<

$(NAME) : $(OBJ_mini) $(OBJ_SRC) $(OBJ_Lib) $(OBJ_perror)
			@-$(CC) $(CFLAGS) $(RD) $(OBJ_mini) $(OBJ_SRC) $(OBJ_Lib) $(OBJ_perror) -o $(NAME)
			@printf "${GREEN}\e[1mSuccess making Minishell ....\e\n"

perror:
	@$(MAKE) -C ft_perror

perrorclean:
	@$(MAKE) -C ft_perror clean

perrorfclean:
	@$(MAKE) -C ft_perror fclean

Lib:
	@$(MAKE) -C Libft

Libclean:
	@$(MAKE) -C Libft clean

Libfclean:
	@$(MAKE) -C Libft fclean

.PHONY: all clean fclean re

clean:	perrorclean Libclean
		@rm -f $(OBJ_mini) $(OBJ_SRC)
		@printf "${YELLOW}\e[1m.o files have been removed (•̀ᴗ•́ )و\e\n"

fclean: clean Libfclean perrorfclean
		@rm -f $(NAME)
		@printf "${YELLOW}\e[1mPlus the compiling files \( ﾟヮﾟ)/\e\n"

re: fclean all