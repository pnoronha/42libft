# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:58:02 by pnoronha          #+#    #+#              #
#    Updated: 2022/03/03 21:52:59 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	 	=	rm -f

SRCS	=	$(wildcard sources/*.c)

OBJS	:=	$(patsubst sources/%.c, objects/%.o, $(SRCS))

BONUS	=	$(wildcard bonus_sources/*.c)

B_OBJS	:=	$(patsubst bonus_sources/%.c, objects/%.o, $(BONUS))

$(NAME):	$(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "\033[32;1m>>	Library libft indexed\033[0m"

all:	$(NAME)

objects/%.o:	*sources/%.c
		@mkdir -p objects
		@$(CC)	$(CFLAGS)	-c	$^	-o	$@

bonus:		$(NAME) $(B_OBJS)
		@ar rcs $(NAME) $(B_OBJS)
		@echo "\033[32;1m>>	Bonus built\033[0m"

clean:
		@$(RM) $(OBJS) $(B_OBJS)
		@$(RM) -d ./objects
		@echo "\033[31;1m>>	Object files removed\033[0m"

fclean:		clean
		@$(RM) $(NAME)
		@echo "\033[31;1m>>	Library libft.a removed\033[0m"

re:		fclean all

.PHONY:		all clean fclean re bonus
