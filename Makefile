# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:58:02 by pnoronha          #+#    #+#              #
#    Updated: 2021/03/11 18:39:13 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	SOURCES
SCRS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_istoupper.c \
			ft_istolower.c \

#	OBJECTS
OBJS	=	${SCRS:.c=.o}

#	LIBRARY
NAME	=	libft.a

#	COMPILER
CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@echo ">>${NAME} created<<\n"
			@ranlib ${NAME}
			@echo ">>${NAME} indexed<<\n"

all:		${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} ${OBJS}
			@echo ">>Objects removed<<\n"

fclean:		clean
			@${RM} ${NAME}
			@echo ">>${NAME} removed<<\n"

re:			fclean all

.PHONY:		all clean fclean re
