#include "../libft/libft.h"
#include "../includes/fdf.h"

static int	ft_rotate_on_z(t_app *app)
{
	t_image	*img;

	img = app->mlx_img;
	if (app->rotate)
	{
		img->gamma += 0.05;
		if (img->gamma > 5.5)
			img->gamma = 0;
		ft_draw_fdf(app);
		return (1);
	}
	return (0);
}

static void	loop_app(t_app *app)
{

	t_mouse	*mouse;

	
	mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
	mouse->deg_value = (W_WIDTH * 1.4142) / 360;
	app->mouse = mouse;
	ft_draw_fdf(app);
	mlx_hook(app->window, 2, 1L << 0, key_pressed_hook, app);
	mlx_hook(app->window, 17, 0, close_window, app);
	mlx_hook(app->window, 4, 1L << 2, mouse_pressed, app);
	mlx_hook(app->window, 5, 1L << 3, mouse_release, app);
	mlx_hook(app->window, 6, 1L << 6, mouse_moved, app);
	mlx_loop_hook(app->mlx, ft_rotate_on_z, app);
	mlx_loop(app->mlx);
}

static bool	init_app(t_app *app, int fd)
{
	app->fd = fd;
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		app->error_code = 3;
		return (false);
	}
	make_title(app);
	if (!read_map_file(app))
		return (false);
	app->map = make_map(app);
	if (app->file_x < 2 && app->file_y < 2)
		return (false);
	app->window = mlx_new_window(app->mlx, W_WIDTH, W_HEIGHT, app->title);
	if (!app->window || !ft_init_image(app))
	{
		app->error_code = 7;
		return (false);
	}
	return (true);
}

static int	close_app(t_app *app, bool t, bool f)
{
	if (t)
		ft_show_error(app);
	if (f)
	{
		ft_free_file_stack(app->file_map);
		if (app->window)
			mlx_destroy_window(app->mlx, app->window);
		if (app->map)
			ft_free_map(app->map, app->file_y);
		free(app->mlx_img);
		free(app->title);
	}
	free(app);
	if (t)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_app	*app;
	int		fd;

	app = NULL;
	if (ac == 2)
	{
		app = (t_app *)ft_calloc(1, sizeof(t_app));
		fd = openfile(av[1], app);
		if (fd == -1)
			return (close_app(app, true, false));
		else
		{
			if (init_app(app, fd))
			{
				loop_app(app);
				return (close_app(app, false, true));
			}
			else
				return (close_app(app, true, true));
		}
	}
	ft_print_error("Usage: ./fdf MAP_FILE", 1);
	return (1);
}
