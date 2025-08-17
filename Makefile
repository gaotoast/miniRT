NAME			=	miniRT
BONUS			=	miniRT_bonus

########################### COMMAND ############################
CC				=	cc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf
MLX				=	minilibx

############################ LIBFT #############################
LIBFT			=	libft
LIBFT_A			=	$(LIBFT).a
LIBFT_DIR		=	./$(LIBFT)

############################## OS ##############################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_LIBFT	=	$(LIBFT_DIR)/mac
	MLX_DIR		=	$(MLX)_macos
	MLX_A		=	$(MLX_DIR)/libmlx.dylib
	MLXFLAGS	=	-framework OpenGL -framework AppKit
else
	OS_LIBFT	=	$(LIBFT_DIR)/linux
	MLX_DIR		=	$(MLX)-linux
	MLX_A		=	$(MLX_DIR)/libmlx_Linux.a
	MLXFLAGS	=	-lXext -lX11 -lm -lz
endif

######################### Directories ##########################
SRCS_DIR		=	./srcs
BONUS_DIR		=	$(SRCS_DIR)/bonus

OBJS_DIR		=	./objs

########################### Sources ############################
SRCS			=	$(wildcard $(SRCS_DIR)/*.c)
BONUS_SRCS		=	$(wildcard $(BONUS_DIR)/*.c)

########################### Objects ############################
OBJS			=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS		=	$(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJS_DIR)/bonus/%.o)

########################### Includes ###########################
INCLUDES		=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_LIBFT)/includes
INCLUDES		+=	-I $(MLX_DIR)

############################ UI/UX #############################
RESET			=	\033[0m
BOLD			=	\033[1m
YELLOW			=	\033[93m
LIGHT_BLUE		=	\033[94m
MAKEFLAGS		+=	--no-print-directory

### Progress Bar
COMPILED	:=	0
TOTAL_FILES	:=	$(words $(OBJS))

define progress
	@$(eval COMPILED := $(shell echo $$(($(COMPILED) + 1))))
	@CURRENT_PERCENT=$$(($(COMPILED) * 100 / $(TOTAL_FILES))); \
	printf "\033[K$(YELLOW)[%3d%%] Compiling: $<$(RESET)\r" $$CURRENT_PERCENT
endef

########################### Targets ############################
all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(NAME)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)\n"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(progress)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/bonus/%.o: $(BONUS_DIR)/%.c | $(OBJS_DIR)/bonus
	@mkdir -p $(dir $@)
	@$(progress)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/bonus:
	@mkdir -p $(OBJS_DIR)/bonus

$(MLX_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Create $(MLX)...$(RESET)"
	@$(MAKE) -j1 -C $(MLX_DIR)

clean:
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Cleaning object files...$(RESET)\n"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_DIR)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)Objects cleaned!$(RESET)\n"

fclean:
	@printf "\033[K$(BOLD)$(LIGHT_BLUE)Removing $(NAME)...$(RESET)\n"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_DIR) $(NAME) $(BONUS)
	@printf "\r\033[K$(BOLD)$(LIGHT_BLUE)Full clean complete!$(RESET)\n"

bonus: $(BONUS)

$(BONUS): $(LIBFT_A) $(MLX_A) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus