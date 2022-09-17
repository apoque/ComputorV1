# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:56:29 by apoque            #+#    #+#              #
#    Updated: 2019/01/12 11:56:06 by apoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

# FLAGS
CFLAGS = -Wall -Wextra -Werror
ADDFLAGS =

# BINARY
NAME = libft.a
DST =

VPATH = srcs srcs/src_printf

# SOURCES
SRC_NAME=ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strndup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_uitoabase.c\
		ft_litoabase.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_is_neg.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_strrev.c\
		ft_itoabase_u.c\
		ft_strjoinfree.c\
		ft_strndupfree.c\
		ft_power.c\
		ft_printf.c\
		 ft_printf2.c\
		ft_printf3.c\
		ft_i.c\
		ft_li.c\
		ft_o.c\
		ft_u.c\
		ft_x.c\
		ft_p.c\
		ft_str.c\
		ft_char.c\
		ft_conv_wchar.c\
		ft_percent.c\
		ft_get_pgcd.c\



# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR= \033[2K
LOG_UP= \033[A
LOG_NOCOLOR= \033[0m
LOG_BOLD= \033[1m
LOG_UNDERLINE= \033[4m
LOG_BLINKING= \033[5m
LOG_BLACK= \033[1;30m
LOG_RED= \033[1;31m
LOG_GREEN= \033[1;32m
LOG_YELLOW= \033[1;33m
LOG_BLUE= \033[1;34m
LOG_MAGENTA= \033[1;35m
LOG_CYAN= \033[1;36m
LOG_WHITE= \033[1;37m
LOG_ORANGE= \033[1;38;5;208m

# **************************************************************************** #


OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)


CPPFLAGS = -I./includes

SRC = $(addprefix $(VPATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR).......................$(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
		@ar rc $@ $^
		@ranlib $@
		@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
		@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
		@gcc $(FLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
		@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
		@mkdir $@

clean:
		@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
		@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
		@rm -rf $(OBJ_PATH)

fclean: clean
		@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
		@rm -rf $(NAME)
		@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/*.h
