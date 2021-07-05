# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 15:58:02 by pnoronha          #+#    #+#              #
#    Updated: 2021/07/05 02:08:05 by pnoronha         ###   ########.fr        #
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
		@echo "\033[32;1m\n>>	Library libft indexed\033[0m"

all:	$(NAME)

objects/%.o:	*sources/%.c
		@mkdir -p objects
		$(CC)	$(CFLAGS)	-c	$^	-o	$@

bonus:		$(NAME) $(B_OBJS)
		@ar rcs $(NAME) $(B_OBJS)
		@echo "\033[32;1m\n>>	Bonus built\033[0m"

clean:
		@echo "\033[31;1m"
		@$(RM) -v $(OBJS) $(B_OBJS)
		@$(RM) -dv ./objects

fclean:		clean
		@$(RM) -v $(NAME)
		@echo "\033[0m"

re:		fclean all

.PHONY:		all clean fclean re bonus
