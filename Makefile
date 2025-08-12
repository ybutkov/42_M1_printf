NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror $(LIB_INCLUDE)
C_FILES = ft_math/ft_max.c \
		ft_convertor/ft_converter.c \
		ft_convertor/ft_ultoa.c \
		ft_components/options_utils.c \
		ft_components/str_components_utils.c \
		ft_printer/print_argument.c \
		ft_printer/print_formatted_data.c \
		ft_printer/print_n_char.c \
		ft_printer/print_number.c \
		ft_printer/print_strings.c \
		ft_printer/print_pointer.c \
		ft_printer/print_ch.c \
		ft_printf.c

LIB_DIR = libft
LIBFT_FILE = libft.a
LIB_PATH = $(LIB_DIR)/$(LIBFT_FILE)
LIB_INCLUDE = -Iinclude

BI_FILES = $(C_FILES:.c=.o)

all : $(LIBFT_FILE) $(NAME) 

${NAME} : $(LIBFT_FILE) $(BI_FILES)
	ar rcs $(NAME) $(BI_FILES)

bonus : all

clean :
	rm -f $(BI_FILES)
	$(MAKE) -C $(LIB_DIR) clean

fclean :
	rm -f $(NAME) $(BI_FILES)
	$(MAKE) -C $(LIB_DIR) fclean

re	: fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE) :
	$(MAKE) -C $(LIB_DIR) bonus
	mv $(LIB_PATH) $(NAME)

.PHONY : all clean fclean re bonus
