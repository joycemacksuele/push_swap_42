# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 00:38:15 by jfreitas          #+#    #+#              #
#    Updated: 2021/03/19 01:06:11 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

##### COLORS #####
BLUE = \033[1;35m
GREY = \033[3;31m
GREEN = \033[1;37m
RED = \033[1;31m
END = \033[0m

##### OSTYPE #####
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# Mac
	FLAGS += -D DARWIN
else
	#Linux
	FLAGS += -D LINUX
endif

##### FLAG #####
CC = clang
FLAGS = -Wall -Wextra -Werror -g# -fsanitize=address

##### INCLUDE #####
INC_PUSH_SWAP = ./includes
INC_LIBFT = $(LIBFTPATH)/includes

##### INCLUDES DEPENDENCIES ####
# ->  Any modify to a .h file will alert Makefile to recompile
INC_DEP = $(INC_PUSH_SWAP)/*.h

##### LIB #####
LIBFT = $(LIBFTPATH)/libft.a

##### SRC & OBJ PATH #####
LIBFTPATH = ./libft
SRCPATH = ./srcs
OBJPATH = $(SRCPATH)/objs

##### SOURCES #####
SRCS = $(addprefix $(SRCPATH)/,\
checker.c \
push_swaap.c)

##### OBJECTS #####
OBJS = $(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

#### RULES ####
all: mk_objdir mk_libft $(NAME)

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

mk_libft:
	@echo "\n$(END)$(BLUE)# Making libft #$(GREY)$(END)"
	@make -C $(LIBFTPATH)

$(NAME): $(OBJS) $(INC_DEP)
	@echo "\n$(END)$(BLUE)# Making $(NAME1) and $(NAME2) #$(GREY)$(END)"
	$(CC) -o $@ $(OBJS) $(LIBFT)
	@echo "\n$(END)$(GREEN)# $(NAME1) and $(NAME2) are built #$(END)"

$(OBJPATH)/%.o: $(SRCPATH)/%.c $(INC_DEP)
	$(CC) $(FLAGS) -I $(INC_LIBFT) -I $(INC_PUSH_SWAP) -c $< -o $@

### CLEAN ###
.PHONY: clean fclean re

clean:
	@echo "$(END)$(RED)# Removing $(NAME1) and $(NAME2) object files #$(GREY)$(END)"
	rm -rf $(OBJS)
	@echo "$(END)$(RED)# Removing libft object files #$(END)"
	@make clean -C $(LIBFTPATH)

fclean: clean
	@echo "$(END)$(RED)\n# removing $(NAME1) and $(NAME2) binaries #$(GREY)$(END)"
	@rm -f $(NAME)
	@echo "$(END)$(RED)\n# removing libft.a #$(END)"
	@make fclean -C $(LIBFTPATH)

re: fclean all
