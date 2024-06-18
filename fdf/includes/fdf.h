#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "colors.h"
# include "hooks_key.h"
# include <math.h>
# include <stddef.h>

# define W_HEIGHT 768
# define W_WIDTH 1366
# define MENU_WIDTH 250

typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	bool	special;
	bool	end;
	int		color;
}	t_coord;

typedef struct s_mouse
{
	int		previous_x;
	int		previous_y;
	bool	b_pressed;
	double	deg_value;
}	t_mouse;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		palette;
	int		min;
	int		max;
	int		zoom;
	double	z_zoom;
	double	alpha;
	double	beta;
	double	gamma;
	int		map_start_x;
	int		map_start_y;
	int		move_x;
	int		move_y;
	int		projection;
}	t_image;

typedef struct s_app
{
	void	*mlx;
	void	*window;
	char	*title;
	char	*file_name;
	t_stack	*file_map;
	t_image	*mlx_img;
	int		file_x;
	int		file_y;
	char	*error_message;
	int		error_code;
	int		fd;
	bool	rotate;
	t_coord	***map;
	t_mouse	*mouse;
}	t_app;

void	ft_show_error(t_app *app);
void	ft_print_error(char *error_message, int code);
int		openfile(char *filename, t_app *app);
int		key_pressed_hook(int key, t_app *app);
int		mouse_pressed(int button, int x, int y, t_app *app);
int		mouse_release(int button, int x, int y, t_app *app);
int		mouse_moved(int x, int y, t_app *app);
void	ft_move_map(int key, t_app *app);
void	ft_change_palete(t_app *app);
void	ft_change_projection(int key, t_app *app);
void	ft_zoom_hook(int key, t_app *app);
void	ft_rotate_hook(int key, t_app *app);
void	ft_flat_hook(int key, t_app *app);
int		terminate_hook(t_app *app);
int		close_window(t_app *app);
bool	ft_init_image(t_app *app);
void	free_stack(t_stack *stack);
void	free_array(void **array, size_t size);
void	ft_free_splitted(char **arr);
void	draw_menu(t_app *app);
void	projection_menu_selector(t_app *app, void *mlx, void *win, int y);
void	draw_background(t_image *img);
void	ft_draw_fdf(t_app *app);
void	ft_rotation_matrix(t_coord *point, t_image *img);
int		ft_get_palette_color(int palete, double percent, int z);
void	project_choice(t_coord *point, t_image *img);
t_coord	prepare_point(t_coord *orignal, t_app *app);
void	isometric_projection(t_coord *point);
bool	read_map_file(t_app *app);
void	print_map_file(t_app *app);
void	draw_segment(t_coord begin, t_coord end, t_image *img);
void	trace_pixel(t_coord *curr, t_coord *end, double percent, t_image *img);
void	make_title(t_app *app);
t_coord	***make_map(t_app *app);
void	ft_free_map(t_coord ***map, size_t nb_lines);
void	ft_free_file_stack(t_stack *file_map);
#endif
