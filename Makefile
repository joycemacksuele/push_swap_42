# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 00:38:15 by jfreitas          #+#    #+#              #
#    Updated: 2021/03/30 03:07:26 by jfreitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

##### COLORS #####

WHITE = \033[1;37m
GREY = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;36m
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

##### SRC & OBJ PATH #####
LIBFTPATH = ./libft
SRCPATH = ./srcs
OBJPATH = $(SRCPATH)/objs

##### INCLUDE #####
INC_PUSH_SWAP = ./includes
INC_LIBFT = $(LIBFTPATH)/includes

##### INCLUDES DEPENDENCIES ####
# ->  Any modify to a .h file will alert Makefile to recompile
INC_DEP = $(INC_PUSH_SWAP)/*.h

##### LIB #####
LIBFT = $(LIBFTPATH)/libft.a

##### SOURCES #####
SRCS = $(addprefix $(SRCPATH)/, error.c utils.c)

SRCS_SWAP = $(addprefix $(SRCPATH)/, push_swap.c manage_lst.c lst_functions.c \
rotate_operations.c swap_and_push_operations.c sort_max_12.c sort_max_100.c)

SRCS_CHECKER = $(addprefix $(SRCPATH)/, checker.c manage_list.c)

##### OBJECTS #####
OBJS_SWAP = $(SRCS_SWAP:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
OBJS_CHECKER = $(SRCS_CHECKER:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
OBJS_SRCS += $(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

#### RULES ####
all: mk_objdir mk_libft $(NAME1) $(NAME2)

mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi

mk_libft:
	@make -C $(LIBFTPATH)

$(NAME1): $(OBJS_SWAP) $(OBJS_SRCS) $(INC_DEP)
	@echo "\n$(END)$(LIGHT_BLUE)Making $(NAME1)$(END)"
#	@$(CC) -o $@ $(OBJS_SWAP) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME1) $(OBJS_SWAP) $(OBJS_SRCS) $(LIBFT)
	@echo "$(END)$(GREEN)$(NAME1) is built\n$(END)"

$(NAME2): $(OBJS_CHECKER) $(OBJS_SRCS) $(INC_DEP)
	@echo "\n$(END)$(LIGHT_BLUE)Making $(NAME2)$(END)"
#	@$(CC) -o $@ $(OBJS_CHECKER) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME2) $(OBJS_CHECKER) $(OBJS_SRCS) $(LIBFT)
	@echo "$(END)$(GREEN)$(NAME2) is built$(END)"

$(OBJPATH)/%.o: $(SRCPATH)/%.c $(INC_DEP)
	@$(CC) $(FLAGS) -I $(INC_LIBFT) -I $(INC_PUSH_SWAP) -c $< -o $@
# -c -> Run all of the above, + the assembler, generating a target .o object file.
# $< is for the $(SRCPATH)/%.c part and $@ for the $(OBJPATH)/%.o part

### CLEAN ###
.PHONY: clean fclean re

clean:
	@echo "$(END)$(YELLOW)Removing $(NAME1) object file$(END)"
	@echo "$(END)$(YELLOW)Removing $(NAME2) object file$(END)"
	@rm -rf $(OBJPATH)
	@rm -rf $(OBJS_CHECKER)
#	@echo "$(END)$(YELLOW)Removing libft object files$(END)"
	@make clean -C $(LIBFTPATH)

fclean: clean
	@echo "$(END)$(YELLOW)\nRemoving $(NAME1) binary$(END)"
	@echo "$(END)$(YELLOW)\nRemoving $(NAME2) binary$(END)"
	@rm -f $(NAME1)
	@rm -f $(NAME2)
#	@echo "$(END)$(YELLOW)\nRemoving libft.a$(END)"
	@make fclean -C $(LIBFTPATH)

re: fclean all
