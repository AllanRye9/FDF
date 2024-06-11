# FDF
This an introductory project to 3D graphical representation of maps . Maps are files containing cordinates that represents an object. Pre-requisites are knowledge in get_next_line, split function , 2D array and other Libft functions are helpful in the journey of learning and exploring FDF project.

The first step to accomplishing this project is as follows;

1. Read map data using get_next_line function and store in a 2D array of integer functions to help are atoi and split.
2. Open the Graphical interface on your computer but to achieve this you need to initialize the minilibx program to the right graphical system base on the operating
   a. system (macOs, linux, windows) with the function mlx_init(); for e.g void *mlx_ptr; mlx_ptr = mlx_init();.
   b. To open a window in your computer it can be achieved with mlx_new_window; for e.g. void *mlx_win = mlx_new_window(mlx_ptr, width, height, "default message");
   c. To keep the window active you need mlx_loop, for e.g mlx_loop(mlx_ptr);.
3. At this point we already have our 2D array and a new window next its time to start drawing, there are a number of algorithms to use but the most common i have stumbled across are brensenham and linear interpolation.
4. how do we draw an isometric view on a 2 dimensional screen well the function that achieves this is cosine and sine if you know your maths well this shouldn't be a problem.
   a. To express the function for e.g a struct named points with members of x , y and z , destination.x = points.x + cos(angle) * points.z; destination.y = points.y +       
      sine(angle) * points.z; the mathimatical equation for this is modifiable based on desired outcome.
   b. To draw you need to create a function that uses any of the 2 algorithm mentioned or any of your choice inorder to draw an object on the graphical user interface.
5. After drawing our object shall be static so we need to add events like mouseover, zoom in or out, color, exit the current window using escape on the keyboard or the cross       sign on the top left corner of the screen and the screen should exit smoothly.
   a. The function for this is called hook function mlx_hook(void *ptr_win, int func()(), void *ptr); it takes function that returns an integer each operating systems has     
      numbering systems for events like keyboard press, mouseover, zoom in or out . for e.g  mlx_hook(mlx_win, keypress, mlx); thats how we add events to our graphics.


