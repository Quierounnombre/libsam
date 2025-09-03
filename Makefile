BLACK = \033[0;30m
RED =   \033[0;31m
GREEN = \033[0;32m
YELLOW =    \033[0;33m
BLUE  = \033[0;34m
MAGENTA =   \033[0;35m
CYAN =  \033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

NAME = libasm.a

NASM = nasm
NASM_FLAGS = -felf64

AR = ar
AR_FLAGS = rcs -f $(NAME)

RM = rm -f
OBJ_DIR = obj

LIB_FILES = ft__strlen.s \

OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %.s, %.o, $(LIB_FILES)))

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(OBJ_DIR)
	@$(NASM) $(NASM_FLAGS) -o $@ $<

$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $(OBJS)
	@gcc -Wall -Wextra -Werror main.c $(NAME)
	@echo -e "$(LCYAN)\n$(NAME) libreria compilada\n$(RESET)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo -e "$(YELLOW)\nArchivos .o limpiados\n$(RESET)"

fclean: clean
	@$(RM) $(NAME) 
	@echo -e "$(RED)\n$(NAME) limpiada\n$(RESET)"

re: fclean all

do_clean: all clean

.PHONY: all clean fclean re do_clean
.SILENT: