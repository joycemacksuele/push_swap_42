# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 10:43:20 by jfreitas          #+#    #+#              #

#    Updated: 2021/02/22 19:25:59 by jle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
INCPATH = includes/
DEPS = $(INCPATH)/libft.h

OBJDIR = srcs/objs

SRCS =	srcs/ft_atoi.c \
		srcs/ft_long_long_atoi.c \
		srcs/ft_bzero.c \
		srcs/ft_calloc.c \
		srcs/ft_intlen_base.c \
		srcs/ft_intlen.c \
		srcs/ft_isalnum.c \
		srcs/ft_isalpha.c \
		srcs/ft_isascii.c \
		srcs/ft_isdigit.c \
		srcs/ft_isprint.c \
		srcs/ft_itoa.c \
		srcs/ft_memalloc.c \
		srcs/ft_memccpy.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_memcpy.c \
		srcs/ft_memdel.c \
		srcs/ft_memmove.c \
		srcs/ft_memset.c \
		srcs/ft_putchar.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putendl.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_putstr.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_realloc.c \
		srcs/ft_strcat.c \
		srcs/ft_strchr.c \
		srcs/ft_strclen.c \
		srcs/ft_strclr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strcpy.c \
		srcs/ft_strdel.c \
		srcs/ft_strdup.c \
		srcs/ft_strequ.c \
		srcs/ft_striter.c \
		srcs/ft_striteri.c \
		srcs/ft_strjoin.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlen.c \
		srcs/ft_strmap.c \
		srcs/ft_strmapi.c \
		srcs/ft_strncat.c \
		srcs/ft_strncmp.c \
		srcs/ft_strncpy.c \
		srcs/ft_strnequ.c \
		srcs/ft_strnew.c \
		srcs/ft_strnstr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strstr.c \
		srcs/ft_substr.c \
		srcs/ft_strtrim.c \
		srcs/ft_tolower.c \
		srcs/ft_toupper.c \
		srcs/ft_intlen.c \
		srcs/ft_islower.c \
		srcs/ft_isupper.c \
		srcs/ft_split.c \
		srcs/ft_freetab.c \
		srcs/get_next_line.c \
		srcs/join_newstr.c \
		srcs/ft_lstnew_bonus.c \
		srcs/ft_lstadd_back_bonus.c \
		srcs/ft_lstadd_front_bonus.c \
		srcs/ft_lstlast_bonus.c \
		srcs/ft_lstsize_bonus.c \
		srcs/ft_lstmap_bonus.c \
		srcs/ft_lstiter_bonus.c \
		srcs/ft_lstdelone_bonus.c \
		srcs/ft_lstclear_bonus.c

OBJ = $(SRCS:srcs/%.c=$(OBJDIR)/%.o)

all: mk_objdir $(NAME)

mk_objdir :
	@if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi

$(OBJDIR)/%.o : srcs/%.c $(DEPS)
	@$(CC) $(CFLAGS) -I $(INCPATH) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[1;36mBuilding Libft...\033[0m"
	@ar rcs $@ $(OBJ)
	@echo "\033[1;32m$@ is built!\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "\033[1;33mLibft object files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;33m$(NAME) removed!\033[0m"

re: fclean all
