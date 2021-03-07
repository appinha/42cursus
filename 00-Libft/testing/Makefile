# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2020/02/19 14:19:23 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################
## Path to Libft directory ##
#############################
DIR		= ../


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

SRCDIR	= ./

NAME	= $(DIR)/libft.a

INCLUDE	= libft.h
SRCS	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c
OBJS	= $(addprefix $(DIR)/, $(SRCS:.c=.o))
BONUS_S	= ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_swap_bonus.c ft_islower_bonus.c ft_isupper_bonus.c \
			ft_iscntrl_bonus.c ft_isgraph_bonus.c ft_ispunct_bonus.c \
			ft_isspace_bonus.c ft_isblank_bonus.c ft_isxdigit_bonus.c \
			ft_putchar_bonus.c ft_putstr_bonus.c ft_putendl_bonus.c \
			ft_putnbr_bonus.c ft_sqrt_bonus.c ft_strcmp_bonus.c \
			ft_strcpy_bonus.c ft_strncpy_bonus.c ft_strstr_bonus.c \
			ft_strcat_bonus.c ft_strncat_bonus.c ft_strndup_bonus.c
BONUS_O	= $(addprefix $(DIR)/, $(BONUS_S:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			@$(LIB1) $(NAME) $(OBJS)
			@$(LIB2) $(NAME)

bonus:		$(NAME) $(BONUS_O)
			@$(LIB1) $(NAME) $(BONUS_O)
			@$(LIB2) $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

# LIBFTEST START

t:			$(INCLUDE) $(OBJS) $(BONUS_O)
			@$(CC) $(CFLAGS) -I$(INCLUDE) -Iheader.h $(OBJS) $(BONUS_O) \
			main.c tests.c -o a.out
			@echo ""
			@./a.out
#			@make fclean

t_fclean:	fclean
			$(RM) t_testes.out

t_re:	t_fclean tests

# LIBFTEST END

.PHONY:		all clean fclean re bonus rebonus
