#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	push_swap
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror	\
						-g3		#TEST ONLY

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR				=	src
SRC_FILES			=	debug_tools.c	\
						err.c			\
						main.c
SRCS				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
INCLUDE_DIR			=	include
INCLUDE_FILES		=	push_swap.h
INCLUDES			=	$(addprefix $(INCLUDE_DIR)/, $(INCLUDE_FILES))
BUILD_DIR			=	build
OBJS				=	$(SRC_FILES:.c=.o)
BUILDS				=	$(addprefix $(BUILD_DIR)/, $(OBJS))

#≻───░⋆ ✪ LIBFT EXTRA ✪ ⋆░───────────────────────────────────────────────────≺#
LIBFT_REPO			=	https://github.com/brmoretti/42_libft_extra.git
LIBFT_LIB_NAME		=	libft.a
LIBFT_DIR			=	libft_extra
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/include
LIBFT_LIB			=	$(LIBFT_DIR)/$(LIBFT_LIB_NAME)
LIBFT_LIBS			=	-lft
LIBFT_CC			=	-I./$(LIBFT_INCLUDE_DIR)	\
						-L./$(LIBFT_DIR)			\
						$(LIBFT_LIBS)

#≻───░⋆ ✪ COLORS ✪ ⋆░────────────────────────────────────────────────────────≺#
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
GREEN				=	\033[0;32m
DEFAULT 			=	\033[0:0m

#≻───░⋆ ✪ RULES ✪ ⋆░─────────────────────────────────────────────────────────≺#
.PHONY: all bonus clean fclean clear re

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT_LIB) $(BUILD_DIR) $(BUILDS) $(INCLUDES)
	@ $(CC) -o $@			\
	  $(BUILDS)				\
	  -I./$(INCLUDE_DIR)	\
	  $(LIBFT_CC)			\
	  $(CC_FLAGS)
	  @ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<				\
	  -I./$(INCLUDE_DIR)		\
	  -I./$(LIBFT_INCLUDE_DIR)	\
	  -o $@						\
	  $(CC_FLAGS)

clean: clean_libft
	@ rm -rf $(BUILD_DIR)

fclean: fclean_libft clean
	@ rm -rf $(NAME)

re: fclean all

$(LIBFT_LIB): $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@ git clone $(LIBFT_REPO) $(LIBFT_DIR)

clean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) clean

fclean_libft: $(LIBFT_DIR)
	@ make -s -C $(LIBFT_DIR) fclean

clear_libft:
	@ rm -rf $(LIBFT_DIR)

clear: fclean clear_libft