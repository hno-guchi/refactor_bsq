# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2023/08/18 17:46:53 by hnoguchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
# Variables #
#############

NAME = bsq

CC = gcc
MKDIR = mkdir -p
INCLUDES = -I./includes
CFLAGS = -Wall -Wextra -Werror
OVER_FLOW = -g -fsanitize=address
SRCS = main.c \
	   ft_isspace.c ft_isdigit.c ft_isprint.c \
	   ft_putchar_fd.c ft_putstr_fd.c \
	   error.c ft_strlen.c ft_strdup.c ft_strjoin.c \
	   ft_split.c ft_calloc.c ft_bzero.c ft_memset.c ft_substr.c ft_strlcpy.c \
	   ft_atoi.c ft_info.c ft_validate_map.c \
	   makesquare2.c helpmakesquare.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

#################
# General Rules #
#################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS_DIR):
	$(MKDIR) $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(RM) -r $(NAME)

.PHONY: re
re: fclean all

.PHONY: over_flow
over_flow: CFLAGS += $(OVER_FLOW)
over_flow: re

.PHONY: leaks
leaks: CFLAGS += -DLEAKS
leaks: re
