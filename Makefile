# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 16:59:51 by ael-mejh          #+#    #+#              #
#    Updated: 2024/04/02 16:16:10 by ael-mejh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server
NAMEC = client
CC    = cc
CFLAGS = -Wall -Wextra -Werror

SRC1 = server.c ft_putstr_fd.c
SRC2 =  server.c ft_putstr_fd.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# Print header
# printheder:
# 	@echo "\033[0;35m"
# 	@echo "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
# 	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
# 	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
# 	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
# 	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
# 	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
# 	@echo "\033[0m"

all: $(NAMES) $(NAMEC) 

$(NAMES): $(OBJ1)
	$(CC) $(CFLAGS) $^ -o $(NAMES)

$(NAMEC): $(OBJ2)
	$(CC) $(CFLAGS) $^ -o $(NAMEC) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ1) $(OBJ2)
fclean: clean
	rm -rf $(NAMEC) $(NAMES)
.PHONY: all clean printheder
