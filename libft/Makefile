NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
C_FILES = ft_isalpha.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
C_BONUS_FILES = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

BI_FILES = $(C_FILES:.c=.o)
BI_BONUS_FILES = $(C_BONUS_FILES:.c=.o)

all : $(NAME)

${NAME} : $(BI_FILES)
	ar rcs $(NAME) $(BI_FILES)

clean :
	rm -f $(BI_FILES) $(BI_BONUS_FILES)

fclean :
	rm -f $(NAME) $(BI_FILES) $(BI_BONUS_FILES)

re	: fclean all

bonus : $(BI_FILES) $(BI_BONUS_FILES)
	ar rcs $(NAME) $(BI_FILES) $(BI_BONUS_FILES)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re bonus