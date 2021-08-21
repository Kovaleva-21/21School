/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:27:52 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:45:23 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx_mms_20200219/mlx.h"
# include "../libft/libft.h"

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_text {
	void			*img;
	char			*addr;
	char			*addr_n;
	char			*addr_e;
	char			*addr_w;
	char			*addr_s;
	char			*addr_spr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				widht;
	int				heith;
	char			*reletiv_path;
}					t_text;

typedef struct		s_vars {
	void			*mlx;
	void			*win;
	double			x;
	double			y;
	double			bx;
	double			len_sprite;
	char			**mas;
	double			alfa;
	double			start;
	t_data			img;
	int				flag_wall;
	int				count_plan;
	t_text			text;
	double			len_ray;
	int				count_sprite;
	int				*mas_sprite;
	double			mas_ray[9000];
	int				size_x;
	int				size_y;
	int				color_f;
	int				color_c;
}					t_vars;

typedef struct		s_stolb {
	double			len;
	int				len_stolb;
	double			start;
	double			yyy;
	double			end;
	double			coef;
	double			count;
	int				color;
	int				count_y_pixel;
	int				count_x_pixel;
}					t_stolb;

typedef struct		s_rastoinie {
	double			xa;
	double			ya;
	double			px;
	double			py;
	double			ay;
	double			ax;
	double			bx;
	double			by;
	double			len_gor;
	double			len_ver;
	int				i;
	int				j;
	int				i1;
	int				j1;
	int				end_mas_y;
}					t_rastoinie;

typedef struct		s_sprite {
	int				count;
	int				count2;
	int				count3;
	double			len_sprite1;
	double			len_sprite2;
	double			spr_x;
	double			spr_y;
}					t_sprite;

typedef struct		s_events {
	int				i;
	int				j;
	int				ii;
	int				jj;
	int				iii;
	int				jjj;
	int				flag_wall;
	int				count_wall;
}					t_events;

typedef struct		s_events2 {
	int				count;
	int				count2;
	int				count3;
	double			len_sprite1;
	double			len_sprite2;
	double			spr_x;
	double			spr_y;
}					t_events2;

typedef struct		s_player {
	int				x;
	int				y;
	int				i;
	int				j;
}					t_player;

typedef struct		s_skrin {
	int				count_mas;
	int				count_str;
	int				flag;
	char			*ptr;
	unsigned int	x;
	unsigned int	y;
}					t_skrin;

typedef struct		s_flor {
	int				count_mas;
	int				count_str;
	int				flag;
	char			*ptr;
}					t_flor;

typedef struct		s_valid {
	int				count_str;
	int				count_mas;
	int				i;
	int				flag_start;
	int				flag_mas[10];
}					t_valid;

typedef struct		s_color {
	int				count_mas;
	int				count_str;
	int				flag;
	char			*ptr;
}					t_color;

typedef struct		s_pr_sp{
	int				i;
	int				j;
	double			sprite_dir;
	double			sprite_dist;
	int				sprite_screen_size;
	int				h_offset;
	int				v_offset;
	int				count;
	double			step;
	int				color;
}					t_pr_sp;

void				pars_texture(t_vars *vars, char *str,
char **adr, char *str2);
void				skrinshot(t_vars *vars);
void				my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int					get_color(t_vars *data, int x, int y);
int					sp_get_color(t_vars *data, int x, int y);
void				print_poz(t_vars *vars);
void				print_stolb(t_vars *vars, double angle_ray);
int					count_rastoinie(char **mas,
double pow, t_vars *vars);
void				print_player(t_vars *vars);
void				print_sprite(double spr_x, double spr_y, t_vars *vars);
char				**save_map(int size, t_list **tmp);
int					events(int keycode, t_vars *vars);
void				pars_player(t_vars *vars);
int					pars_cub(char **argv, t_vars *vars);
int					pars_skrin_size(t_vars *vars, char *mas);
int					pars_flor_color(t_vars *vars, char *str);
int					pars_ceilling_color(t_vars *vars, char *str);
void				init_window(t_vars *vars);
void				sort_sprite(t_vars *vars);
int					valid_mup(t_vars *vars, int count_mas, int count_str);
int					ft_close();
void				valid_mup_cub(t_vars *vars);
void				null_funk(t_vars *vars);
int					main(int argc, char **argv);

void				init_events(t_events *events);
void				init_events2(t_events2 *events2);
void				events2(t_events *events, t_vars *vars);
void				events3(t_events *events, t_vars *vars);
void				events4(t_events *events, t_vars *vars);
void				events5(t_events *events, t_vars *vars);
void				events6(t_events2 *events2, t_vars *vars);
void				init_flor(t_flor *flor);
void				init_color(t_color *color);

int					valid_res_text(t_valid *valid, t_vars *vars);
int					valid_textures_res(t_valid *valid, t_vars *vars);
int					valid_textures(t_valid *valid, t_vars *vars);
int					valid_flor_res(t_valid *valid, t_vars *vars);
int					valid_flor(t_valid *valid, t_vars *vars);

void				events7(t_events *events, t_vars *vars);
void				events8(t_events *events, t_vars *vars);
void				events9(t_events *events, t_vars *vars);
void				events10(t_events *events, t_vars *vars);
void				count_rastoinie_res_3(t_rastoinie *rastoinie, char **mas);
void				count_rastoinie_res_4(t_rastoinie *rastoinie, double pow);
void				count_rastoinie_res_5(t_rastoinie *rastoinie, char **mas);
void				count_rastoinie_res_6(t_rastoinie *rastoinie, t_vars *vars,
double pow);
void				count_rastoinie_res_7(t_rastoinie *rastoinie, t_vars *vars,
double pow);

#endif
