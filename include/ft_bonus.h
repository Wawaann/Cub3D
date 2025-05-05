/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:06 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/05 10:54:27 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "../lib/include/libft.h"
# include "../lib/include/miniaudio.h"
# include "../.mlx/mlx.h"
# include "key.h"

# include <sys/time.h>

# define MAX_DISTANCE 9.0
# define SIZE 384.0
# define HAND 384
# define TILE 24
# define FPS 16666.667
# define PI 3.1415926535
# define S_HEIGHT 864
# define S_WIDTH 1152
# define M_HEIGHT 482
# define M_WIDTH 626
# define SPRINT 0.03
# define MAX_STAMINA 100.0
# define STAMINA_DRAIN 1.0
# define STAMINA_REGEN 0.4
# define STAMINA_REGEN_DELAY 3

typedef struct s_node
{
	int				x;
	int				y;
	int				g;
	int				h;
	int				f;
	struct s_node	*parent;
}				t_node;

typedef struct s_list
{
	t_node	**nodes;
	int		size;
	int		capacity;
}				t_list;

typedef struct s_vector
{
	float	x;
	float	y;
}				t_vector;

typedef struct s_ivector
{
	int		x;
	int		y;
}				t_ivector;

typedef struct s_rot
{
	float	cos_a;
	float	sin_a;
	int		new_x;
	int		new_y;
}				t_rot;

typedef struct s_path
{
	int			**map;
	t_vector	start;
	t_vector	goal;
	t_list		*open;
	t_list		*closed;
	int			i;
	int			index;
}				t_path;

typedef struct s_audio
{
	ma_sound		*sound;
	ma_result		result;
	bool			use;
	bool			playing;
}				t_audio;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				offset;
	struct timeval	tv;
	struct timeval	tv2;
}				t_img;

typedef struct s_object
{
	bool		show;
	bool		lwn;
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		inv_det;
	float		transform_x;
	float		transform_y;
	int			o_screen_x;
	int			o_height;
	int			o_width;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	int			tex_x;
	int			tex_y;
	float		tex_pos;
	float		step;
	float		angle;
	float		angle_to_ply;
	t_img		texture;
}				t_object;

typedef struct s_parse
{
	char		**map;
	char		**walls;
	char		**oth;
	char		*wall;
	int			width;
	int			height;
	int			nb_walls;
	t_vector	key;
}				t_parse;

typedef struct s_map
{
	int			**map;
	int			*width;
	int			height;
}				t_map;

typedef struct s_player
{
	bool			key;
	float			angle;
	float			speed;
	float			a;
	float			th;
	float			x;
	float			y;
	t_rot			rot;
	time_t			start_sprint;
	time_t			end_sprint;
	float			stamina;
	struct timeval	tv;
}				t_player;

typedef struct s_lowan
{
	bool			active;
	bool			show;
	float			x;
	float			y;
	float			angle;
	float			speed;
	float			dist;
	t_rot			rot;
	struct timeval	tv;
	struct timeval	tv2;
}				t_lowan;

typedef struct s_fs
{
	int			fs_p;
	float		fs_row_dist;
	float		fs_left_x;
	float		fs_left_y;
	float		fs_right_x;
	float		fs_right_y;
	float		fs_step_x;
	float		fs_step_y;
	float		fs_x;
	float		fs_y;
	int			fs_tex_x;
	int			fs_tex_y;
}				t_fs;

typedef struct s_rnd
{
	float		ray_dirx;
	float		ray_diry;
	float		deltax;
	float		deltay;
	float		sidedistx;
	float		sidedisty;
	float		wall_dist;
	float		z_buffer[S_WIDTH];
	float		wall_pers;
	float		wall_hit_x;
	float		fs_dir_x;
	float		fs_dir_y;
	float		fs_plane_x;
	float		fs_plane_y;
	int			end_point;
	int			mapx;
	int			mapy;
	int			side;
	int			stepx;
	int			stepy;
	int			starting_point;
	int			wall;
	int			o;
}				t_rnd;

typedef struct s_data
{
	bool			keys[KEY_COUNT];
	int				state;
	struct timeval	tv;
	struct timeval	tv2;
	struct timeval	t_door;
	struct timeval	t_door2;
	void			*mlx;
	void			*win;
	t_map			map;
	t_parse			parse;
	t_path			*path;
	t_player		ply;
	t_lowan			lwn;
	t_rnd			rnd;
	t_fs			fs;
	t_img			end;
	t_img			hand;
	t_img			*mini_key;
	t_img			*wall;
	t_img			*fc;
	t_img			floor_img;
	t_img			sky_img;
	t_img			wood;
	t_img			mini;
	t_img			frame;
	t_img			player_img;
	t_object		*objects;
	t_vector		*pos;
	t_ivector		door;
	ma_engine		*engine;
	t_audio			**sound;
	int				num_objects;
	int				door_frame;
}				t_data;

int				update_view(t_data *game);
int				**get_minimap(t_data *game);
void			set_img(void *mlx, char *asset, t_img *img);
void			load_img(t_data *game);
void			draw_hand(t_data *data);
void			draw_stamina_bar(t_data *game);
void			clear_buffer(t_img *img);
void			get_door_coord(t_data *game);
void			get_i_j(int **map, int *i, int *j);

int				close_win(t_data *game);

//		Audio
void			handle_audio(t_data *game);
t_audio			*init_sound(ma_engine *engine, char *file, float vol);
void			play_sound(t_audio *audio);

//		Event
void			handle_minimap(t_data *game);
void			move_ply(t_data *game, float *n_posx, float *n_posy);
void			handle_rotate(t_data *game);
int				can_walk(t_data *game, float new_posx, float new_posy);
void			handle_door(t_data *game);
void			handle_key(t_data *game);
int				key_pressed(int keycode, t_data *data);
int				key_released(int keycode, t_data *data);
void			handle_mouse(t_data *game);
void			check_win(t_data *game);
void			check_lowan(t_data *game, float new_posx, float new_posy);

// Minimap
int				max(int a, int b);
void			draw_square(t_data *game, int x, int y, int color);
void			compute_angle(t_rot *rot, float angle);
void			compute_new_coord(t_rot *rot, int x, int y);
void			draw_minimap(t_data *game);

// Objects
void			draw_object(t_data *game);
void			init_objects(t_data *game);
void			draw_obj(t_data *data, t_object *obj);
int				compare_and_swap(t_object *obj1, t_object *obj2, t_player ply);

//		Exit
void			free_file(char	*line, int fd);
void			exit_map(t_data *data, char *msg);
void			exit_param(t_data *data, int fd, char *line, char *error);

//		Parsing
bool			check_arg(int ac, char **av);
bool			test_texture(char *texture);
bool			test_fch(char **fch);
char			*get_param(t_data *data, int fd);
void			check_char(t_data	*data);
void			convert_map(t_data *data, char **map);
void			fill_map(char	**map);
void			fill_single_map(char **map);
void			get_map(t_data *data, int fd, char *i_line);
void			get_data(t_data *data, char *path);
void			set_key(t_data *data, int i, int j);
void			test_map(t_data *data);

//		Pathfinding
bool			dontneed(t_map map, t_path *path, t_node *tmp);
bool			in_list(t_list *list, int x, int y);
float			heuristic(float x1, float y1, float x2, float y2);
int				find_lowest_f(t_list *open);
int				get_index(t_list *list, int x, int y);
int				**cpy_map_path(t_map map);
t_list			*lst_new(void);
t_node			*create_node(int x, int y);
void			display_list(t_list *list);
void			display_node(t_node *node, int **map);
void			lst_add(t_list *list, t_node *node);
void			lst_remove(t_list *list, int index);
void			lst_free(t_list *list);
void			pathfinding(t_data *game);
void			set_node(t_node *node, int g, int h, t_node *parent);
void			update_node(t_list *list, t_node *tmp);

//		Key Handler
int				update_view(t_data *game);
void			handle_rotate(t_data *game);
void			handle_move(t_data *game);

//		Raycasting
int				apply_fog(int color, float distance);
int				close_win(t_data *game);
int				key_handler(int keycode, t_data *game, bool is_pressed);
int				get_color_from_texture(t_img const *texture, int x, int y);
void			cast_rays(t_data *game);
void			draw_column_line(t_data *game, int column, int ray_index);
void			draw_texture(t_data *game, int line_height, int ray_i);
void			init_ray_vars(t_data *game, float ray_angle);
void			put_pixel_to_buffer(t_img *dest, int x, int y, uint32_t pixel);
void			init_sky_floor(t_data *game);
void			compute_sky_floor(t_data *game, t_fs *fs, int ray_index);

#endif
