/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:14:45 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/21 18:43:19 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

/* WINDOW SIZE *****************************************/
# define WIDTH 1280
# define HEIGHT 760

/* MAP BLOCK SIZE **************************************/
# define BLK 64
# define MBLK 15

/* MAP BLOCK SIZE **************************************/
# define PLYCOL 0x8B0000
# define MAPCOL 0xFFFF00
# define VISCOL 0xFF6666

/* GAME & RENDER CONSTANTS *****************************/
# define FOV_ANGLE 1.0471975512//(PHI/3)
# define NUM_RAYS_MINIMAP 90
# define SPEED 4
# define ANGLE_SPEED 0.01

/* PLAYER CONTROLS *************************************/
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

/* OTHER MACROS ****************************************/
# define ESC 65307
# define PHI 3.14159265359

/* ERROR MESSAGES *************************************/
# define ERR_INVALID_ARGS "Oops! Use: ./cub3d  <name_map_file.cub>"
# define ERR_FILE_NOT_CUB "Oops! The map file must end with .cub"
# define ERR_DUP_TEXTURE_ID "Hey! Duplicate texture ID detected - texture \
déjà vu!"
# define ERR_DUP_CEILING_COLOR "Hey! Duplicate ceiling color detected -\
 color déjà vu!"
# define ERR_DUP_FLOOR_COLOR "Hey! Duplicate floor color detected -\
 color déjà vu!"
# define ERR_COLOR_FLOOR "Hey! Detected invalid floor RGB color -\
 Please, check your values!"
# define ERR_COLOR_CEILING "Hey! Detected invalid ceiling RGB color -\
 Please, check your values!"
# define ERR_INVALID_LINE "Hey! I don't recognize this line. Are you sure?"
# define ERR_MAP_NOT_FOUND "Oops! Map file missing... 	WHERE'S MY MAP?!"
# define ERR_MALLOC "Oops! Out of memory  - MALLOC FAILURE!"
# define ERR_INV_CHAR "Hey! What's this character doing here? Only \
 '0', '1', 'N', 'S', 'E', 'W' and spaces are invited to this party."
# define ERR_TOO_MANY_PLAYERS "Hey! Too many heroes on this map.\
 Only one player (N,S,E,W) allowed!"
# define ERR_NO_PLAYER "Hey! This map is a ghost town. Please add a player\
 (N, S, E, or W)!"
# define ERR_MAP_MISSING "Alert! No map data found. Please check the file\
 and try again!"
# define ERR_MAP_NO_WALLS "Alert! This map isn't Alcatraz, it has an escape\
 route! Please surround it with walls ('1')."
# define ERR_MISSING_CONFIG "Hey! A texture or color definition is missing.\
 Please check the file."

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/* STRUCTURES ******************************************/
typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_txtinf
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				tex_width;
	int				tex_height;	
}	t_txtinf;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			dist;
	double			wall_x;
	int				side;
	int				height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				texture_idx;
}					t_ray;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	char		**map;
	int			**textures;
	t_txtinf	txtinf;
}	t_cub;

/* ** MAIN ********************************************/
int				check_filename(char *filename);
void			init_game(t_cub *game, char *map_file);

/* ** DRAW_MAP ***************************************/
bool			touch(float px, float py, t_cub *game);
void			draw_map(t_cub *game);
void			draw_ceiling(t_cub *game);
void			draw_floor(t_cub *game);
void			draw_floor_and_ceiling(t_cub *game);

/* ** DRAW_RAYCAST ***********************************/
void			draw_textured_column(t_cub *game, t_ray *ray, int x);
int				draw_loop(t_cub *game);

/* ** RAYCASTING_UTILS **********************************/
void			perform_dda(t_cub *game, t_ray *ray);
void			calculate_step_and_sidedist(t_cub *game, t_ray *ray);
void			init_ray(t_cub *game, t_ray *ray, int x);
void			calculate_projection(t_cub *game, t_ray *ray);

/* ** DRAW_SHAPES ************************************/
void			draw_square(int x, int y, int size, t_cub *game);
void			draw_circle(int x, int y, int radius, t_cub *game);
void			draw_fov_on_minimap(t_cub *game);

/* ** DRAW_UTILS *************************************/
unsigned long	rgb_to_hex(int *rgb);
float			distance(float a, float b);
void			put_pixel(int x, int y, int color, t_cub *game);
void			clear_image(t_cub *game);
int				close_window(t_cub *game);

/* ** MAP ********************************************/
char			**get_map(void);
void			print_map(int x, int y, int size, t_cub *game);

/* ** PLAYER_INIT ************************************/
float			get_spawn_angle(char dir);
void			find_player_start(t_cub *game);
void			init_player(t_player *player);
int				key_press(int keycode, t_cub *game);
int				key_release(int keycode, t_player *player);

/* ** PLAYER_MOVE ************************************/
void			move_forward(t_cub *game, float cos_a, float sin_a);
void			move_backward(t_cub *game, float cos_a, float sin_a);
void			strafe_left(t_cub *game, float cos_a, float sin_a);
void			strafe_right(t_cub *game, float cos_a, float sin_a);

/* ** PLAYER_MOVE ************************************/
bool			in_map_bounds(float px, float py, t_cub *game);
void			move_player_rotate(t_cub *game);
void			move_player_direction(t_cub *game, float cos_a, float sin_a);
void			move_player(t_cub *game);

/* ** PARSER *****************************************/
void			parse_map(char *map_file, t_cub *game);
int				err_msg(char *detail, char *str, int code);

/* ** CONFIG_PARSER_UTILS **********************************/
int				process_texture_line(t_cub *game, char *line);
int				process_color_line(t_cub *game, char *line);

/* ** CONFIG_PARSER *****************************/	
int				process_config_line(t_cub *game, char *line);
int				get_file_data(t_cub *game, char **file);
int				process_line(t_cub *game, char *line, int *map_started);

/* ** MAP_BUILDER ************************************/
size_t			find_biggest_len(char **file, int i);
int				allocate_map_rows(t_cub *game, int height);
int				fill_map_row(char *dest, char *src, int width);
int				create_map(t_cub *game, char **file, int start_index);

/* ** MAP_VALIDATION **********************************/
int				check_map_validity(t_cub *game);

/* ** TEXTURES ****************************************/
void			init_textures(t_cub *game);

/* ** UTILS ****************************************/
void			free_all_resources(t_cub *game);
void			free_tab(void **tab);

#endif
