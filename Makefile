# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 16:05:35 by pviegas           #+#    #+#              #
#    Updated: 2023/07/27 13:46:48 by pviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
RM				= rm -f
FLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

INC	= include
LIBFTDIR = libft/
OBJ_DIR	= obj/
SRC_DIR = src/

SRC_1 = srcs/pipex.c 

SRC_2 =	funcs.c 

OBJ_1 = $(addprefix $(OBJ_DIR), $(notdir $(SRC_1:.c=.o)))
OBJ_2 = $(addprefix $(OBJ_DIR), $(notdir $(SRC_2:.c=.o)))

INCLUDE = -L ./libft -lft		

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ_1} ${OBJ_2}
	@make -C $(LIBFTDIR)
	${CC} ${CFLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	
all: $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJ_DIR}*.o ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re 
