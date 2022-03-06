# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:58:02 by pnoronha          #+#    #+#              #
#    Updated: 2022/03/06 17:04:04 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	sources/ft_isalnum.c		\
			sources/ft_isalpha.c		\
			sources/ft_isascii.c		\
			sources/ft_isdigit.c		\
			sources/ft_isprint.c		\
			sources/ft_isspace.c		\
			sources/ft_atoi.c			\
			sources/ft_atol.c			\
			sources/ft_itoa.c			\
			sources/ft_tolower.c		\
			sources/ft_toupper.c		\
			sources/ft_utoa.c			\
			sources/ft_intlen.c			\
			sources/ft_strlen.c			\
			sources/ft_strnlen.c		\
			sources/ft_unsignedlen.c	\
			sources/ft_wordcnt.c		\
			sources/ft_bzero.c			\
			sources/ft_calloc.c			\
			sources/ft_memccpy.c		\
			sources/ft_memchr.c			\
			sources/ft_memcmp.c			\
			sources/ft_memcpy.c			\
			sources/ft_memmove.c		\
			sources/ft_memset.c			\
			sources/ft_putchar_fd.c		\
			sources/ft_putchar.c		\
			sources/ft_putendl_fd.c		\
			sources/ft_putendl.c		\
			sources/ft_putnbr_fd.c		\
			sources/ft_putnbr.c			\
			sources/ft_putnbrBase.c		\
			sources/ft_putstr_fd.c		\
			sources/ft_putstr.c			\
			sources/ft_split.c			\
			sources/ft_strchr.c			\
			sources/ft_strcpy.c			\
			sources/ft_strdup.c			\
			sources/ft_strjoin.c		\
			sources/ft_strlcat.c		\
			sources/ft_strlcpy.c		\
			sources/ft_strmapi.c		\
			sources/ft_strncmp.c		\
			sources/ft_strnstr.c		\
			sources/ft_strrchr.c		\
			sources/ft_strtrim.c		\
			sources/ft_substr.c

B_SRCS	=	bonus_sources/ft_lstadd_back.c	\
			bonus_sources/ft_lstadd_front.c	\
			bonus_sources/ft_lstclear.c		\
			bonus_sources/ft_lstdelone.c	\
			bonus_sources/ft_lstiter.c		\
			bonus_sources/ft_lstlast.c		\
			bonus_sources/ft_lstmap.c		\
			bonus_sources/ft_lstnew.c		\
			bonus_sources/ft_lstsize.c		\

OBJS	:=	$(patsubst sources/%.c, objects/%.o, $(SRCS))
B_OBJS	:=	$(patsubst bonus_sources/%.c, bonus_objects/%.o, $(B_SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM	 	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		@ar rcs	$(NAME)	$(OBJS)
		@echo "\033[32;1m>>	Library libft indexed\033[0m"

bonus:	$(NAME)	$(B_OBJS)
		@ar rcs	$(NAME)	$(OBJS)	$(B_OBJS)
		@echo "\033[32;1m>>	Bonus built\033[0m"

objects/%.o:	sources/%.c
		@mkdir -p objects
		@$(CC)	-c	$(CFLAGS)	$(^)	-o	$(@)

bonus_objects/%.o:	bonus_sources/%.c
		@mkdir -p bonus_objects
		@$(CC)	-c	$(CFLAGS)	$(^)	-o	$(@)

clean:
		@$(RM) $(OBJS) $(B_OBJS)
		@$(RM) -d ./objects
		@echo "\033[31;1m>>	Object files removed\033[0m"

fclean:	clean
		@$(RM) $(NAME)
		@echo "\033[31;1m>>	LIBFT removed\033[0m"

re:		fclean all

.PHONY:		all clean fclean re bonus
