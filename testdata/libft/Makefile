# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 01:48:01 by byron             #+#    #+#              #
#    Updated: 2021/06/03 01:28:49 by bchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
GCC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
RM = rm -f 

FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUSFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(FILES:.c=.o)
BONUSOBJECTS = $(BONUSFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
	echo "build done"

%.o: %.c $(HEADER) 
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	echo "cleaning"
	$(RM) $(OBJECTS)
	$(RM) $(BONUSOBJECTS)

fclean: clean
	echo "cleaning"
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUSOBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS) $(BONUSOBJECTS)
	echo "bonus build done"

rebonus: fclean bonus

.PHONY: clean fclean

