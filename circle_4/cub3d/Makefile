# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 21:27:49 by youngmch          #+#    #+#              #
#    Updated: 2023/03/22 20:38:00 by youngmch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- NAME ---- #

NAME = cub3D

FT = ./libft/libft.a
FTCC = -L./libft -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror $(DB)
DB = -g3
FA = -fsanitize=address
AR = ar
ARFLAG = ruc
RM = rm -f

MLX_LIB = -Lmlx_mms -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore
MLX_INC = -Imlx_mms

object_dir = ./objects

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Mandatory ---- #

sources1 :=

sources1 += srcs/main.c
sources1 += srcs/parse/path_parsing.c
sources1 += srcs/parse/map_parsing.c
sources1 += srcs/parse/check_valid.c
sources1 += srcs/utils/utils1.c
sources1 += srcs/utils/utils2.c
sources1 += srcs/init/game_init.c
sources1 += srcs/init/set_camera.c
sources1 += srcs/init/sprite_init.c
sources1 += srcs/init/set_ray_draw.c
sources1 += srcs/key_hook/key_hook.c
sources1 += srcs/key_hook/move_event.c
sources1 += srcs/key_hook/engine.c
sources1 += srcs/key_hook/rotate_event.c
sources1 += srcs/key_hook/door_control.c
sources1 += srcs/key_hook/move_mouse.c
sources1 += srcs/render/draw_minimap.c
sources1 += srcs/render/raycasting.c
sources1 += srcs/render/render_map.c
sources1 += srcs/render/render_sprite.c

# ---- Bonus ---- #

sources2 :=

sources2 +=

# ---- Elements ---- #

all_sources = $(sources1) $(sources2)

objects1 = $(sources1:.c=.o)
objects2 = $(sources2:.c=.o)
all_objects = $(objects1) $(objects2)

define objects_goal
$(addprefix $(object_dir)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), all_objects, objects1)))
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

# ---- Command ---- #

.PHONY : clean fclean re all bonus

all : $(NAME)

$(NAME) : $(objects_goal) $(FT)
	@make -C mlx_mms
	@cp mlx_mms/libmlx.dylib .
	@$(CC) $(CFLAGS) $(MLX_LIB) -o $@ $(objects_goal) $(FTCC)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

bonus : $(NAME)

$(object_dir)/%.o : %.c
	@#mkdir -p $(object_dir)
	@mkdir -p $(object_dir)/$(dir $^)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

$(FT) :
	@make -C ./libft all

clean :
	@$(RM) $(all_objects)
	@rm -rf $(object_dir)
	@make -C ./libft clean
	@make -C ./mlx_mms clean
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean
	@rm -rf libmlx.dylib
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)
