#* miniRT Makefile v1.0

MAKEFILE_VERSION := 1.0
BANNER  = \n \033[38;5;208m███\033[38;5;240m╗   \033[38;5;208m███\033[38;5;240m╗\033[38;5;208m██\033[38;5;240m╗\033[38;5;208m███\033[38;5;240m╗   \033[38;5;208m██\033[38;5;240m╗\033[38;5;208m██\033[38;5;240m╗\033[38;5;208m██████\033[38;5;240m╗ \033[38;5;208m████████\033[38;5;240m╗\n \033[38;5;214m████\033[38;5;239m╗ \033[38;5;214m████\033[38;5;239m║\033[38;5;214m██\033[38;5;239m║\033[38;5;214m████\033[38;5;239m╗  \033[38;5;214m██\033[38;5;239m║\033[38;5;214m██\033[38;5;239m║\033[38;5;214m██\033[38;5;239m╔══\033[38;5;214m██\033[38;5;239m╗╚══\033[38;5;214m██\033[38;5;239m╔══╝\n \033[38;5;220m██\033[38;5;238m╔\033[38;5;220m████\033[38;5;238m╔\033[38;5;220m██\033[38;5;238m║\033[38;5;220m██\033[38;5;238m║\033[38;5;220m██\033[38;5;238m╔\033[38;5;220m██\033[38;5;238m╗ \033[38;5;220m██\033[38;5;238m║\033[38;5;220m██\033[38;5;238m║\033[38;5;220m██████\033[38;5;238m╔╝   \033[38;5;220m██\033[38;5;238m║   \n \033[38;5;226m██\033[38;5;237m║╚\033[38;5;226m██\033[38;5;237m╔╝\033[38;5;226m██\033[38;5;237m║\033[38;5;226m██\033[38;5;237m║\033[38;5;226m██\033[38;5;237m║╚\033[38;5;226m██\033[38;5;237m╗\033[38;5;226m██\033[38;5;237m║\033[38;5;226m██\033[38;5;237m║\033[38;5;226m██\033[38;5;237m╔══\033[38;5;226m██\033[38;5;237m╗   \033[38;5;226m██\033[38;5;237m║   \n \033[38;5;228m██\033[38;5;236m║ ╚═╝ \033[38;5;228m██\033[38;5;236m║\033[38;5;228m██\033[38;5;236m║\033[38;5;228m██\033[38;5;236m║ ╚\033[38;5;228m████\033[38;5;236m║\033[38;5;228m██\033[38;5;236m║\033[38;5;228m██\033[38;5;236m║  \033[38;5;228m██\033[38;5;236m║   \033[38;5;228m██\033[38;5;236m║   \n \033[38;5;235m╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝ \033[1;3;38;5;240mMakefile v$(MAKEFILE_VERSION)\033[0m\n

override TIMESTAMP := $(shell date +%s 2>/dev/null || echo "0")

ifneq ($(QUIET),true)
	override QUIET := false
endif

#? Compiler and Linker
BINDIR		:= bin
NAME		:= $(BINDIR)/miniRT
BONUS_NAME	:= $(BINDIR)/miniRT_bonus
CC			:= cc
RM			:= rm -rf
MLX			:= minilibx

#? Compiler Flags
REQFLAGS	:= -g
WARNFLAGS	:= -Wall -Wextra -Werror
OPTFLAGS	:=
LDFLAGS		:=
CFLAGS		:= $(REQFLAGS) $(WARNFLAGS) $(OPTFLAGS)

#? Detect PLATFORM and ARCH
ARCH		?= $(shell uname -m || echo unknown)

ifeq ($(shell uname -s),Darwin)
	PLATFORM		:= macOS
	PLATFORM_DIR	:= mac
	THREADS			:= $(shell sysctl -n hw.ncpu || echo 1)
	OS_LIBFT		:= libft/mac
	MLX_DIR			:= $(MLX)_macos
	MLX_A			:= $(MLX_DIR)/libmlx.a
	MLXFLAGS		:= -framework OpenGL -framework AppKit
else
	PLATFORM		:= $(shell uname -s || echo unknown)
	PLATFORM_DIR	:= linux
	THREADS			:= $(shell getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1)
	OS_LIBFT		:= libft/linux
	MLX_DIR			:= $(MLX)-linux
	MLX_A			:= $(MLX_DIR)/libmlx_Linux.a
	MLXFLAGS		:= -lXext -lX11 -lm -lz
endif

ifeq ($(shell command -v gdate >/dev/null; echo $$?),0)
	DATE_CMD := gdate
else
	DATE_CMD := date
endif

#? Use all CPU cores
MAKEFLAGS	+= --jobs=$(THREADS) --no-print-directory

ifeq ($(VERBOSE),true)
	override VERBOSE := false
else
	override VERBOSE := true
endif

#? The Directories, Source, Objects
SRCDIR		:= srcs
BUILDDIR	:= objs
LIBFT_DIR	:= libft

#? Sources and Objects
SOURCES		:= \
	$(SRCDIR)/check.c \
	$(SRCDIR)/error.c \
	$(SRCDIR)/free.c \
	$(SRCDIR)/init.c \
	$(SRCDIR)/key_handler.c \
	$(SRCDIR)/main.c \
	$(SRCDIR)/mlx.c \
	$(SRCDIR)/put_info.c \
	$(SRCDIR)/debug/print_context.c \
	$(SRCDIR)/debug/print_objects.c \
	$(SRCDIR)/debug/print_scene.c \
	$(SRCDIR)/debug/print_utils.c \
	$(SRCDIR)/parsing/object_list.c \
	$(SRCDIR)/parsing/parse.c \
	$(SRCDIR)/parsing/parse_ambient.c \
	$(SRCDIR)/parsing/parse_camera.c \
	$(SRCDIR)/parsing/parse_cylinder.c \
	$(SRCDIR)/parsing/parse_light.c \
	$(SRCDIR)/parsing/parse_plane.c \
	$(SRCDIR)/parsing/parse_sphere.c \
	$(SRCDIR)/parsing/parse_utils.c \
	$(SRCDIR)/parsing/validate_format.c \
	$(SRCDIR)/parsing/validate_scene.c \
	$(SRCDIR)/parsing/validate_values.c \
	$(SRCDIR)/render/ray.c \
	$(SRCDIR)/render/ray_cylinder.c \
	$(SRCDIR)/render/ray_hit.c \
	$(SRCDIR)/render/ray_plane.c \
	$(SRCDIR)/render/ray_sphere.c \
	$(SRCDIR)/render/render.c \
	$(SRCDIR)/render/render_shading.c \
	$(SRCDIR)/transform/resize.c \
	$(SRCDIR)/transform/rotate.c \
	$(SRCDIR)/transform/translate.c \
	$(SRCDIR)/utils/clamp.c \
	$(SRCDIR)/utils/count.c \
	$(SRCDIR)/utils/ft_strtod.c \
	$(SRCDIR)/utils/quad.c \
	$(SRCDIR)/utils/vec3_utils.c

BONUS_SOURCES	:=

OBJECTS		:= $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
BONUS_OBJECTS	:= $(patsubst $(SRCDIR)/bonus/%.c,$(BUILDDIR)/bonus/%.o,$(BONUS_SOURCES))

#? Includes
INC			:= -I ./includes -I $(LIBFT_DIR)/includes -I $(OS_LIBFT)/includes -I $(MLX_DIR)

#? Setup percentage progress
SOURCE_COUNT := $(words $(SOURCES))
BONUS_SOURCE_COUNT := $(words $(BONUS_SOURCES))
P := %%

ifeq ($(VERBOSE),true)
	override SUPPRESS := > /dev/null 2> /dev/null
else
	override SUPPRESS :=
endif

#? Default Make
.ONESHELL:
all: | info directories $(NAME)
	@printf "\n\033[1;92mBuild complete in \033[92m(\033[97m$$($(DATE_CMD) -d @$$(expr $$(date +%s 2>/dev/null || echo "0") - $(TIMESTAMP) 2>/dev/null) -u +%Mm:%Ss 2>/dev/null | sed 's/^00m://' || echo "unknown")\033[92m)\033[0m\n"

ifneq ($(QUIET),true)
info:
	@printf " $(BANNER)\n"
	@printf "\033[1;92mPLATFORM     \033[1;93m?| \033[0m$(PLATFORM)\n"
	@printf "\033[1;96mARCH         \033[1;93m?| \033[0m$(ARCH)\n"
	@printf "\033[1;93mCC           \033[1;93m?| \033[0m$(CC)\n"
	@printf "\033[1;94mTHREADS      \033[1;94m:| \033[0m$(THREADS)\n"
	@printf "\033[1;91mREQFLAGS     \033[1;91m!| \033[0m$(REQFLAGS)\n"
	@printf "\033[1;93mWARNFLAGS    \033[1;94m:| \033[0m$(WARNFLAGS)\n"
	@printf "\033[1;95mOPTFLAGS     \033[1;94m:| \033[0m$(if $(OPTFLAGS),$(OPTFLAGS),(none))\n"
	@printf "\033[1;96mLDFLAGS      \033[1;94m:| \033[0m$(if $(LDFLAGS),$(LDFLAGS),(none))\n"
	@printf '\033[1;97mCFLAGS       \033[1;92m+| \033[0m$$(REQFLAGS) $$(WARNFLAGS) $$(OPTFLAGS)\n'
	@printf "\033[1;95mINCLUDES     \033[1;92m+| \033[0m$(INC)\n"
	@printf "\n\033[1;92mBuilding $(NAME) \033[93m$(PLATFORM) \033[96m$(ARCH)\033[0m\n\n"
else
info:
	@true
endif

help:
	@printf " $(BANNER)\n"
	@printf "\033[1;97mminiRT makefile\033[0m\n"
	@printf "usage: make [target]\n\n"
	@printf "\033[1;4mTargets:\033[0m\n"
	@printf "  \033[1mall\033[0m          Compile $(NAME) (default)\n"
	@printf "  \033[1mbonus\033[0m        Compile $(BONUS_NAME)\n"
	@printf "  \033[1mclean\033[0m        Remove built objects\n"
	@printf "  \033[1mfclean\033[0m       Remove built objects and binary\n"
	@printf "  \033[1mre\033[0m           Rebuild from scratch\n"
	@printf "  \033[1minfo\033[0m         Display build information\n"
	@printf "  \033[1mhelp\033[0m         Show this help message\n"

#? Make the Directories
directories:
	@$(VERBOSE) || printf "mkdir -p $(BUILDDIR) $(BINDIR)\n"
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/$(PLATFORM_DIR)
	@mkdir -p $(BUILDDIR)/bonus
	@mkdir -p $(BINDIR)
	@echo 0 > $(BUILDDIR)/.progress_count

#? Link
.ONESHELL:
$(NAME): $(LIBFT_DIR)/libft.a $(MLX_A) $(OBJECTS) | directories
	@TSTAMP=$$(date +%s 2>/dev/null || echo "0")
	@printf "\n\033[1;92mLinking and creating binary\033[37m...\033[0m\n"
	@$(VERBOSE) || printf "$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS)\n"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) || exit 1
	@printf "\033[1;92m100$(P) -> \033[1;37m$@ \033[1;93m(\033[1;97m$$(du -h $@ | cut -f1)\033[1;93m)\033[0m\n"

#? Bonus Link
.ONESHELL:
$(BONUS_NAME): $(LIBFT_DIR)/libft.a $(MLX_A) $(BONUS_OBJECTS) | directories
	@TSTAMP=$$(date +%s 2>/dev/null || echo "0")
	@$(QUIET) || printf "\033[1;92mLinking and creating bonus binary\033[37m...\033[0m\n"
	@$(VERBOSE) || printf "$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(BONUS_OBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS)\n"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(BONUS_OBJECTS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLXFLAGS) || exit 1
	@printf "\033[1;92m100$(P) -> \033[1;37m$@ \033[1;93m(\033[1;97m$$(du -h $@ | cut -f1)\033[1;93m)\033[0m\n"

#? Build libft (after info display, sequential for clean progress bar)
$(LIBFT_DIR)/libft.a: | info directories
	@printf "\n\033[1;94m[1/3] Building libft\033[37m...\033[0m\n"
	@MAKEFLAGS= $(MAKE) -C $(LIBFT_DIR)

#? Build MLX (after libft)
$(MLX_A): $(LIBFT_DIR)/libft.a
	@printf "\n\033[1;94m[2/3] Building $(MLX)\033[37m...\033[0m\n"
	@MAKEFLAGS= $(MAKE) -C $(MLX_DIR) $(SUPPRESS)
	@printf "\033[1;92m$(MLX) build complete.\033[0m\n"

#? Compile (depends on libft and mlx to ensure sequential build)
.ONESHELL:
$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(LIBFT_DIR)/libft.a $(MLX_A) | directories
	@mkdir -p $(dir $@)
	@$(QUIET) || printf "\033[1;97mCompiling $<\033[0m\n"
	@$(VERBOSE) || printf "$(CC) $(CFLAGS) $(INC) -c -o $@ $<\n"
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< || exit 1
	@while ! mkdir $(BUILDDIR)/.progress_lock 2>/dev/null; do sleep 0.01; done; \
	PROGRESS=$$(( $$(cat $(BUILDDIR)/.progress_count) + 1 )); \
	echo $$PROGRESS > $(BUILDDIR)/.progress_count; \
	rmdir $(BUILDDIR)/.progress_lock; \
	PERCENT=$$((PROGRESS * 100 / $(SOURCE_COUNT))); \
	printf "\033[1;92m%3d$(P) -> \033[1;37m$@\033[0m\n" $$PERCENT

#? Bonus target
bonus: | info directories $(BONUS_NAME)
	@printf "\n\033[1;92mBonus build complete!\033[0m\n"

#? Clean only Objects
clean:
	@printf "\033[1;91mRemoving: \033[1;97mbuilt objects...\033[0m\n"
	@$(MAKE) clean -C $(LIBFT_DIR) $(SUPPRESS)
	@$(RM) $(BUILDDIR)
	@printf "\033[1;92mClean complete.\033[0m\n"

#? Clean Objects and Binary
fclean: clean
	@printf "\033[1;91mRemoving: \033[1;97mbinaries...\033[0m\n"
	@$(MAKE) fclean -C $(LIBFT_DIR) $(SUPPRESS)
	@$(MAKE) clean -C $(MLX_DIR) $(SUPPRESS)
	@$(RM) $(NAME) $(BONUS_NAME) $(BINDIR)
	@printf "\033[1;92mFull clean complete.\033[0m\n"

#? Rebuild (sequential: fclean then all)
re:
	@$(MAKE) fclean
	@$(MAKE) all

#? Non-File Targets
.PHONY: all clean fclean re bonus info help directories
