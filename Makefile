# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 18:44:39 by ebennamr          #+#    #+#              #
#    Updated: 2022/12/31 17:11:12 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## Variable Block ###############
CC = cc
NAME = fractol
FLAG = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
SRC:= fractol.c complex.c error.c  key.c mouse.c string.c graphic.c

INCLIDE =  const.h lib.h
OBJ= $(SRC:.c=.o)

########### shell color ############
GREEN:=\033[0;32m
RED =\033[0;31m
RESET =\033[0m
XR = \033[0m# \033[31;7m
XG = \033[32;7m
MARK = "✅"
REMOVE = "🗑"
############## Traget Block ###############
all : $(NAME)

$(NAME) :print $(OBJ)
	@echo "$(MARK)Object File Created"
	@$(CC) $(FLAG) $(FRAMEWORK) $(OBJ) -o $(NAME)
	@echo "$(MARK)Fract-ol Created"

bouns:print $(OBJ)
	@echo "$(MARK)Object File Created"
	@$(CC) $(FLAG) $(FRAMEWORK) $(OBJ) -o $(NAME)
	@echo "$(MARK)Fract-ol bouns Created"

%.o:%.c $(INCLIDE)
	@$(CC) $(FLAG) -c $< -o $@
	@echo "$(MARK) $@"




clean:
	@echo "$(RED) $(REMOVE) Rmove Oject Files $(RESET)"
	@rm -rf $(OBJ) 


fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) $(REMOVE) Remove $(NAME) $(RESET)"
	@echo "$(GREEN) Done $(RESET)"

re: fclean all

print:
	@echo "$(XR) $(XG)      $(XR)  $(XG)     $(XR)    $(XG)    $(XR)    $(XG)     $(XR)  $(XG)      $(XR)           $(XG)    $(XR)   $(XG)  $(XR)     "
	@echo "$(XR) $(XG)  $(XR)      $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)    $(XG)  $(XR)            $(XG)  $(XG)  $(XG)  $(XR)  $(XG)  $(XR)     "
	@echo "$(XR) $(XG)    $(XR)    $(XG)     $(XR)   $(XG)      $(XR)  $(XG)  $(XR)        $(XG)  $(XR)    $(XG)      $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)     "
	@echo "$(XR) $(XG)    $(XR)    $(XG)     $(XR)   $(XG)      $(XR)  $(XG)  $(XR)        $(XG)  $(XR)    $(XG)      $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)     "
	@echo "$(XR) $(XG)  $(XR)      $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)    $(XG)  $(XR)            $(XG)    $(XG)  $(XR)  $(XG)  $(XR)     "
	@echo "$(XR) $(XG)  $(XR)      $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)  $(XG)  $(XR)   $(XG)    $(XR)     $(XG)  $(XR)             $(XG)    $(XR)   $(XG)      $(XR) "

