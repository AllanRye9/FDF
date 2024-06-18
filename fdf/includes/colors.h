#ifndef COLOR_H
# define COLOR_H

# define SHELL_RED "\033[0;31m"
# define SHELL_YELLOW "\033[0;33m"
# define SHELL_END_COLOR "\033[m"
# define TEXT_COLOR 0x1A1A1D
# define BACKGROUND 0x1A1A1D
# define MENU_BACKGROUND 0x950740
# define BLACK 0x000000
# define WHITE 0xFFFFFF

double	ft_percent(int start, int end, int current);
int		ft_gradient(int start, int end, double percent);
int		palette_one(double percent);
int		palette_two(double percent, int z);
int		palette_three(double percent);
int		palette_four(double percent);
int		palette_five(double percent);
#endif
