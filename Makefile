# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitor <aitor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 13:24:18 by aitormar          #+#    #+#              #
#    Updated: 2025/03/03 11:16:35 by aitor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_isalpha.c\
						ft_isdigit.c\
						ft_isalnum.c\
						ft_isascii.c\
						ft_isprint.c\
						ft_strlen.c\
						ft_memset.c\
						ft_bzero.c\
						ft_memcpy.c\
						ft_memmove.c\
						ft_strlcpy.c\
						ft_strlcat.c\
						ft_toupper.c\
						ft_tolower.c\
						ft_strchr.c\
						ft_strrchr.c\
						ft_strncmp.c\
						ft_memchr.c\
						ft_memcmp.c\
						ft_strnstr.c\
						ft_atoi.c\
						ft_calloc.c\
						ft_strdup.c\
						ft_substr.c\
						ft_strjoin.c\
						ft_strtrim.c\
						ft_itoa.c\
						ft_strmapi.c\
						ft_striteri.c\
						ft_putchar_fd.c\
						ft_putstr_fd.c\
						ft_putendl_fd.c\
						ft_putnbr_fd.c\
						ft_split.c\
						ft_strchr_gnl.c\
						get_next_line.c\
						ft_strjoin_gnl.c\
						ft_free_and_null.c\
						ft_calloc_gnl.c\

MY_BONUS_SOURCES = ft_lstnew.c\
						ft_lstadd_front.c\
						ft_lstsize.c\
						ft_lstlast.c\
						ft_lstadd_back.c\
						ft_lstdelone.c\
						ft_lstclear.c\
						ft_lstiter.c\
						ft_lstmap.c\



OBJS = $(MY_SOURCES:.c=.o)
BONUS_OBJS = $(MY_BONUS_SOURCES:.c=.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@ar crs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
