# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 02:31:11 by alfgarci          #+#    #+#              #
#    Updated: 2022/09/25 18:10:46 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/ft_printf.c \
		src/ft_printf_utils.c \
		src/ft_puthex.c \
		src/ft_putmem.c \
		src/ft_putunsig.c

OBJS 	=	${SRCS:.c=.o}

INC 	=	includes/

CC	=	cc -Wall -Wextra -Werror

NAME 	=	libftprintf.a

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I ${INC}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
