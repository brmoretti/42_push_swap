#≻───░⋆ ✪ DEFAULTS ✪ ⋆░──────────────────────────────────────────────────────≺#
NAME				=	push_swap
BONUS				=	checker
CC					=	cc
CC_FLAGS			=	-Wall	\
						-Wextra	\
						-Werror	\
						-g3

#≻───░⋆ ✪ PROJECT DIRECTORIES & FILES ✪ ⋆░───────────────────────────────────≺#
SRC_DIR				=	src
INCLUDE_DIR			=	include
BUILD_DIR			=	build

#≻─✪ NAME
NAME_SRC_DIR		=	$(SRC_DIR)/$(NAME)
NAME_SRC_FILES		=	algo.c				\
						conditional_push.c	\
						debug_tools.c		\
						err.c				\
						main.c				\
						misc.c				\
						push.c				\
						rev_rotate.c		\
						rotate.c			\
						stack_rule_by_size.c\
						stacking_a.c		\
						stacking_b.c		\
						stacks_utils.c		\
						swap.c				\
						validations.c
NAME_SRCS			=	$(addprefix $(NAME_SRC_DIR)/, $(NAME_SRC_FILES))
NAME_INCLUDE_DIR	=	$(INCLUDE_DIR)/$(NAME)
NAME_INCLUDE_FILES	=	push_swap.h
NAME_INCLUDES		=	$(addprefix $(NAME_INCLUDE_DIR)/, $(NAME_INCLUDE_FILES))
NAME_BUILD_DIR		=	$(BUILD_DIR)/$(NAME)
NAME_OBJS			=	$(NAME_SRC_FILES:.c=.o)
NAME_BUILDS			=	$(addprefix $(NAME_BUILD_DIR)/, $(NAME_OBJS))

#≻─✪ BONUS
BONUS_SRC_DIR		=	$(SRC_DIR)/$(BONUS)
BONUS_SRC_FILES		=	err_bonus.c			\
						instructions_bonus.c\
						main_bonus.c		\
						misc_bonus.c		\
						push_bonus.c		\
						rev_rotate_bonus.c	\
						rotate_bonus.c		\
						swap_bonus.c		\
						validations_bonus.c
BONUS_SRCS			=	$(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))
BONUS_INCLUDE_DIR	=	$(INCLUDE_DIR)/$(BONUS)
BONUS_INCLUDE_FILES	=	checker_bonus.h
BONUS_INCLUDES		=	$(addprefix $(BONUS_INCLUDE_DIR)/, $(BONUS_INCLUDE_FILES))
BONUS_BUILD_DIR		=	$(BUILD_DIR)/$(BONUS)
BONUS_OBJS			=	$(BONUS_SRC_FILES:.c=.o)
BONUS_BUILDS		=	$(addprefix $(BONUS_BUILD_DIR)/, $(BONUS_OBJS))

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

bonus: $(BONUS)

$(NAME): $(LFTPRINTF_LIB) $(BUILD_DIR) $(NAME_BUILDS) $(NAME_INCLUDES)
	@ $(CC) -o $@					\
	  $(NAME_BUILDS)				\
	  -I./$(NAME_INCLUDE_DIR)		\
	  $(LFTPRINTF_CC)				\
	  $(CC_FLAGS)
	@ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BONUS): $(LFTPRINTF_LIB) $(BUILD_DIR) $(BONUS_BUILDS) $(BONUS_INCLUDES)
	@ $(CC) -o $@					\
	  $(BONUS_BUILDS)				\
	  -I./$(BONUS_INCLUDE_DIR)		\
	  $(LFTPRINTF_CC)				\
	  $(CC_FLAGS)
	@ printf "$(GREEN)$@$(DEFAULT) successfully generated\n"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR) &&	\
	  cd $(BUILD_DIR) &&	\
	  mkdir $(NAME) &&		\
	  mkdir $(BONUS)

$(NAME_BUILD_DIR)/%.o: $(NAME_SRC_DIR)/%.c $(NAME_INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<					\
	  -I./$(NAME_INCLUDE_DIR)		\
	  -I./$(LFTPRINTF_INCLUDE_DIR)	\
	  -o $@							\
	  $(CC_FLAGS)

$(BONUS_BUILD_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_INCLUDES)
	@ printf "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)\n"
	@ $(CC) -c $<					\
	  -I./$(BONUS_INCLUDE_DIR)		\
	  -I./$(LFTPRINTF_INCLUDE_DIR)	\
	  -o $@							\
	  $(CC_FLAGS)

clean: clean_lftprintf
	@ rm -rf $(BUILD_DIR)

fclean: fclean_lftprintf clean
	@ rm -rf $(NAME)
	@ rm -rf $(BONUS)

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