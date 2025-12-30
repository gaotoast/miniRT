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

######################### Directories ##########################
SRCS_DIR		=	./srcs
BONUS_DIR		=	$(SRCS_DIR)/bonus

OBJS_DIR		=	./objs

############################## OS ##############################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(SRCS_DIR)/mac
	OS_LIBFT	=	$(LIBFT_DIR)/mac
	MLX_DIR		=	$(MLX)_macos
	MLX_A		=	$(MLX_DIR)/libmlx.dylib
	MLXFLAGS	=	-framework OpenGL -framework AppKit
else
	OS_DIR		=	$(SRCS_DIR)/linux
	OS_LIBFT	=	$(LIBFT_DIR)/linux
	MLX_DIR		=	$(MLX)-linux
	MLX_A		=	$(MLX_DIR)/libmlx_Linux.a
	MLXFLAGS	=	-lXext -lX11 -lm -lz
endif

########################### Sources ############################
OS_SRCS			=	$(wildcard $(OS_DIR)/*.c)
SRCS			=	$(wildcard $(SRCS_DIR)/*.c)
SRCS			+=	$(wildcard $(SRCS_DIR)/**/*.c)
SRCS			+=	$(OS_SRCS)
BONUS_SRCS		=	$(wildcard $(BONUS_DIR)/*.c)

########################### Objects ############################
OBJS			=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS		=	$(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJS_DIR)/bonus/%.o)

########################### Includes ###########################
INCLUDES		=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_LIBFT)/includes
INCLUDES		+=	-I $(MLX_DIR)

######################### UI/UX #########################
### Progress Bar
WIDTH		:=	$(shell tput cols)
BAR_WIDTH	:=	$(shell echo $$(($(WIDTH) - 20)))

TOTAL		:=	$(words $(OBJS))
CURRENT		:=	0
define show_progress
	$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@if [ $(CURRENT) -eq 1 ]; then \
		printf "Compiling sources for $(NAME)...\n"; \
	fi
	@printf "\r["
	@for i in $$(seq 1 $(BAR_WIDTH)); do \
		if [ $$i -le $$(($(CURRENT) * $(BAR_WIDTH) / $(TOTAL))) ]; then \
			printf "="; \
		else \
			printf " "; \
		fi; \
	done
	@printf "] $(CURRENT)/$(TOTAL) ($$(($(CURRENT) * 100 / $(TOTAL)))%%)"
endef

########################### Targets ############################
all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	@echo "\033[KCompiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(NAME)
	@echo "\r\033[K$(NAME) created successfully!\n"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(show_progress)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/bonus/%.o: $(BONUS_DIR)/%.c | $(OBJS_DIR)/bonus
	@mkdir -p $(dir $@)
	$(show_progress)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/bonus:
	@mkdir -p $(OBJS_DIR)/bonus

$(MLX_A):
	@echo "Create $(MLX)..."
	@$(MAKE) -j1 -C $(MLX_DIR)

clean:
	@echo "\033[KCleaning object files...\n"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_DIR)
	@echo "\r\033[KObjects cleaned!\n"

fclean:
	@echo "\033[KRemoving $(NAME)...\n"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_DIR) $(NAME) $(BONUS)
	@echo "\r\033[KFull clean complete!\n"

bonus: $(BONUS)

$(BONUS): $(LIBFT_A) $(MLX_A) $(BONUS_OBJS)
	@echo "Compile $(BONUS)..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) -o $(BONUS)
	@echo "Compile $(BONUS) complete!"

re: fclean all

.PHONY: all clean fclean re bonus
