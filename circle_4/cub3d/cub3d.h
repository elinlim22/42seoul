/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:28:18 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:16 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define MAP 100
# define TEXTURE 101

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_EXIT 17
# define KEY_DOOR 49
# define KEY_ONE 18

# define NORTH 3
# define SOUTH 4
# define WEST 5
# define EAST 6

# define SPRITE 2
# define DOOR_C 7
# define DOOR_O 8

# define MOVE_DOWN 320

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		img_w;
	int		img_h;
}				t_data;

typedef struct s_map
{
	int	x;
	int	y;
	int	val;
}				t_map;

typedef struct s_files
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s1;
	char	*s2;
	char	*door;
}				t_files;

typedef struct s_arg
{
	t_map	**map;
	t_list	*map_str;
	int		x_size;
	int		y_size;
	t_files	root;
	int		floor_rgb;
	int		ceiling_rgb;
}				t_arg;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}				t_draw;

typedef struct s_ray
{
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	double	fdist_x;
	double	fdist_y;
	double	ndist_x;
	double	ndist_y;
	double	perpdist;

	int		map_x;
	int		map_y;
	int		hit_side;
	int		step_x;
	int		step_y;
}				t_ray;

typedef struct s_cam
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	move_speed;
	double	rot_speed;
}				t_cam;

typedef struct s_tex
{
	int		*texture;
	double	width;
	double	height;
}				t_tex;

typedef struct s_pixel
{
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		color;
	double	step_tex;
	double	tex_pos;
}				t_pixel;

typedef struct s_draw_sprite
{
	double	sp_x;
	double	sp_y;
	double	trans_x;
	double	trans_y;
	int		sp_screen;
	int		sp_height;
	int		sp_width;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		s_move;
}				t_draw_sprite;

typedef struct s_sprite
{
	double	pos_x;
	double	pos_y;
	double	dist;
}				t_sprite;

enum e_mask
{
	MASK_W = 1<<0,
	MASK_S = 1<<1,
	MASK_A = 1<<2,
	MASK_D = 1<<3,
	MASK_L = 1<<4,
	MASK_R = 1<<5
};

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_arg		*arg;
	t_tex		*tex;
	t_cam		cam;
	t_ray		ray;
	double		zbuffer[WIDTH];
	t_sprite	*sprite;
	int			mini_ret;
	int			sprite_num;
	int			mouse;
	int			mouse_x;
	int			mouse_y;
	bool		door;
	int			engine;
}				t_mlx;

/* main.c */

int			game_loop(t_mlx *cub3d);
bool		check_filename(char *filename);

/* path_parsing1.c */

void		path_parsing(t_arg *arg, int fd);
bool		get_path(char *tmp, t_arg **arg);
bool		check_arg(t_arg *arg);
t_arg		*init_arg(t_arg *arg);

/* path_parsing2.c */

bool		get_res(char *w, char *h, t_arg **arg);
int			get_rgb(char *tmp);

/* map_parsing.c */

void		map_parsing(t_arg *arg, int fd);
t_arg		*malloc_map(t_list *map_list, t_arg *arg);
t_arg		*get_map(t_list *map_list, t_arg *arg);
bool		map_atoi(char c, int *value);

/* check_valid.c */

void		check_player_num(t_arg *arg);
void		check_valid(t_arg *arg);
void		check_texture(t_arg *arg);

/* utils1.c */

int			rgb_atoi(char **nptr);
bool		free_split(char **split, int flag);
void		free_arg(t_arg *arg);
void		free_list(t_list *list);
void		free_all(t_arg *arg);

/* utils2.c */

void		exit_map(t_arg *arg, t_list *map_list);
void		ft_exit(t_arg *arg, int flag);
void		my_pixel_put(t_data *img, int x, int y, int color);
void		free_tex(t_mlx *cub3d);
t_tex		*bzero_texture(t_mlx *cub3d);

/* game_init.c */

t_mlx		*game_init(t_mlx *cub3d, t_arg *arg, char *name);
void		game_exit(t_mlx *cub3d, int flag, char *string);
void		load_texture(t_mlx **cub3d);
int			*get_texture(t_mlx *cub3d, char *path, t_data *img, int index);

/* set_camera.c */

void		set_cam(t_mlx **cub3d);
void		set_dir(t_cam *cam, int val);

/* sprite_init.c */

void		sprite_init(t_mlx **cub3d);
t_sprite	*malloc_sprite(t_mlx *cub3d);

/* key_hook.c */

void		key_hook_event(t_mlx *cub3d);
int			key_hook(int keycode, t_mlx *cub3d);
int			click_exit(t_mlx *cub3d);
void		mouse_hook(t_mlx **cub3d);

/* draw_minimap.c */

void		draw_minimap(t_mlx *cub3d);
void		draw_square(t_mlx *cub3d, int x, int y, int color);
void		draw_player(t_mlx *cub3d, int x, int y, int color);
// void	draw_lines(t_mlx *cub3d);

/* raycasting.c */

int			where_hit(t_mlx *cub3d, t_ray *ray);

/* set_ray_draw.c */

void		init_ray(t_mlx *cub3d, t_ray *ray, int x);
t_ray		*init_step(t_mlx *cub3d, t_ray *ray);
void		init_draw(t_mlx *cub3d, t_draw *draw);

/* render_wall.c */

void		render_map(t_mlx *cub3d);
void		draw_background(t_mlx *cub3d);
void		draw_map(t_mlx *cub3d, t_ray *ray, int x, int flag);
void		init_pixel(t_mlx *cub3d, t_draw draw, t_tex tex, t_pixel *pixel);
void		draw_texture(t_mlx *cub3d, t_draw draw, t_tex tex, int x);

/* move_event.c */

void		move_forward(t_mlx **cub3d, double dx, double dy);
void		move_back(t_mlx **cub3d, double dx, double dy);
void		move_left(t_mlx **cub3d, double dx, double dy);
void		move_right(t_mlx **cub3d, double dx, double dy);

/* engine.c */
void		get_engine(t_mlx *cub3d);
int			is_set(int engine, enum e_mask mask);
int			get_moveway(int r1, int r2);

/* rotate_event.c */

void		rotate_right(t_mlx **cub3d);
void		rotate_left(t_mlx **cub3d);

/* render_sprite.c */

void		draw_sprites(t_mlx *cub3d, t_tex tex);
void		sort_sprite(t_mlx **cub3d);
void		init_draw_sprite(t_cam cam, t_sprite sprite, t_draw_sprite *draw);
void		draw_sprite(t_mlx *cub3d, t_tex tex, t_draw_sprite draw);
t_tex		change_sprite(t_tex *tex);

/* door_control.c */

void		door_control(t_mlx *cub3d);
void		no_door(t_mlx **cub3d);
void		so_door(t_mlx **cub3d);
void		ea_door(t_mlx **cub3d);
void		we_door(t_mlx **cub3d);

/* move_mouse.c */

void		move_mouse(t_mlx *cub3d);

#endif
