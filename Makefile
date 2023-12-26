#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	push_swap
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror	\
						-g3		#TEST ONLY REMEMBER TO REMOVE

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR				=	src
SRC_FILES			=	algo.c				\
						debug_tools.c		\
						depths.c			\
						err.c				\
						main.c				\
						misc.c				\
						push.c				\
						rev_rotate.c		\
						rotate.c			\
						swap.c				\
						validations.c
SRCS				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
INCLUDE_DIR			=	include
INCLUDE_FILES		=	push_swap.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
OBJS				=	$(SRC_FILES:.c=.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#≻───░⋆ ✪ LFTPRINTF ✪ ⋆░─────────────────────────────────────────────────────≺#
LFTPRINTF_REPO			=	https://github.com/brmoretti/42_ft_printf.git
LFTPRINTF_LIB_NAME		=	libftprintf.a
LFTPRINTF_DIR			=	ft_printf
LFTPRINTF_INCLUDE_DIR	=	$(LFTPRINTF_DIR)/include
LFTPRINTF_LIB			=	$(LFTPRINTF_DIR)/$(LFTPRINTF_LIB_NAME)
LFTPRINTF_LIBS			=	-lftprintf
LFTPRINTF_CC			=	-I./$(LFTPRINTF_INCLUDE_DIR)	\
							-L./$(LFTPRINTF_DIR)			\
							$(LFTPRINTF_LIBS)

#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all bonus clean fclean clear re

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LFTPRINTF_LIB) $(BUILD_DIR) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $@			\
	  $(BUILDS)				\
	  -I./$(INCLUDE_DIR)	\
	  $(LFTPRINTF_CC)			\
	  $(CC_FLAGS)
	  @ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(LFTPRINTF_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

clean: clean_lftprintf
	@ rm -rf $(BUILD_DIR)

fclean: fclean_lftprintf clean
	@ rm -rf $(NAME)

re: fclean all

$(LFTPRINTF_LIB): $(LFTPRINTF_DIR)
	@ make -s -C $(LFTPRINTF_DIR)

$(LFTPRINTF_DIR):
	@ git clone $(LFTPRINTF_REPO) $(LFTPRINTF_DIR)

clean_lftprintf: $(LFTPRINTF_DIR)
	@ make -s -C $(LFTPRINTF_DIR) clean

fclean_lftprintf: $(LFTPRINTF_DIR)
	@ make -s -C $(LFTPRINTF_DIR) fclean

clear_lftprintf:
	@ rm -rf $(LFTPRINTF_DIR)

clear: fclean clear_lftprintf