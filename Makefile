# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:58:02 by pnoronha          #+#    #+#              #
#    Updated: 2021/04/06 18:10:40 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	SOURCES
SRCS	=	ft_memset.c \
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
		ft_toupper.c \
		ft_tolower.c \
		ft_isspace.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_strnlen.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_wordcnt.c \

#	OBJECTS
OBJS	=	$(SRCS:.c=.o)

#	BONUS SOURCES
BONUS	=	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \

#	BONUS OBJECTS
B_OBJS	=	$(BONUS:.c=.o)

#	LIBRARY
NAME	=	libft.a

#	COMPILER
CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	 	=	rm -f

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)
		@echo ">>$(NAME) created<<\n"
		@ranlib $(NAME)
		@echo ">>$(NAME) indexed<<\n"

all:		$(NAME)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)
		@echo ">>Objects removed<<\n"

fclean:		clean
		@$(RM) $(NAME)
		@echo ">>$(NAME) removed<<\n"

bonus:		$(OBJS) $(B_OBJS)
		@ar rc $(NAME) $(OBJS) $(B_OBJS)

so:
		$(CC) -fPIC $(CFLAGS) $(SRCS)
		gcc -shared -o libft.so $(OBJS)

re:		fclean all

.PHONY:		all clean fclean re bonus
