#include <mlx.h>
#include <math.h>

#define SIZE 32
#define SPEED 10
#define WMAP 30
#define LMAP 20

#define MAPX 750
#define MAPY 500
#define VIEW M_SQRT1_2

typedef struct  s_player {
    int        x;
    int        y;
    double        turn;
    double      viewmin;
    double      viewmax;
}               t_player;

typedef struct  s_ptr {
    void    *mlx;
    void    *mlx_win;
}               t_ptr;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    t_player    perc;
    t_ptr       mlx;
    int         colour;
}               t_data;

int map[LMAP][WMAP] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_print_cub(int x, int y, t_data *img)
{
    int ax;
    int ix;
    int ay;
    int iy;

    iy = y;
    ax = 0;
    ay = 0;
    while (ay++ < SIZE)
    {
        ax = 0;
        ix = x;
        while (ax++ < SIZE)
            my_mlx_pixel_put(img, ix++, iy, img->colour);
        iy++;
    }      
}
void print_map(t_data *img)
{

    int i;
    int j;
    
    i = 0;
    while(i < LMAP * SIZE)
    {
        j = 0;
        while(j < WMAP *SIZE)
        {
            if(map[i/SIZE][j/SIZE] == 1)
            {
                my_mlx_pixel_put(img, j, i, 0xff0000);
            }
            if(map[i/SIZE][j/SIZE] == 0)
            {
                my_mlx_pixel_put(img, j, i, 0xffff00);
            }
           j++; 

        }
        i++;
    }
}



void ft_vector(t_data *img, double turn)
{
    int x;
    int y;
    int i;
    int flag = 0;
    i = 0;
    while (flag == 0)
    {
        
        x = (img->perc.x + SIZE/2) - i * sin(turn);
        y = (img->perc.y + SIZE/2) + i * cos(turn);
        if (map[y/SIZE][x/SIZE] == 1)
            flag = 1;
        my_mlx_pixel_put(img, x, y, 0x00ff00);
        i++;
    }
        
}
void ft_vectorview(t_data *img)
{
    int x;
    int y;
    int i;
    int flag = 0;
    double corner;
    corner = img->perc.turn - VIEW;
    i = 0;

    while (corner < img->perc.turn + VIEW)
    {
       ft_vector(img, corner);
        corner += 0.01;
    }

}

int ft_key_press(int keycode, t_data *img)
{
    mlx_destroy_image(img->mlx.mlx, img->img);
    

    img->img = mlx_new_image(img->mlx.mlx, 1500, 1000);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

    if (keycode == 0)  //A
    {
        img->perc.turn -= 0.05;
    }
    else if (keycode == 2) //D
    {
        img->perc.turn += 0.05;
    }
    else if (keycode == 13) //W
    {
        img->perc.y += SPEED * cos(img->perc.turn);
        img->perc.x -=  SPEED * sin(img->perc.turn);
    }
    else if (keycode == 1) //S
    {
        img->perc.y -= SPEED * cos(img->perc.turn);
        img->perc.x +=  SPEED * sin(img->perc.turn);
    }
    print_map(img);
    ft_print_cub(img->perc.x, img->perc.y, img);
    ft_print_cub(img->perc.x, img->perc.y, img);
    ft_vector(img, img->perc.turn);
    ft_vectorview(img);
    mlx_put_image_to_window(img->mlx.mlx, img->mlx.mlx_win, img->img, 0, 0);
    return (0);
}



int main()
{
    t_data img;
    img.perc.x = MAPX;
    img.perc.y = MAPY;
    img.perc.turn = 5 * M_PI_4;
    img.perc.viewmin = img.perc.turn - VIEW;
    img.perc.viewmax = img.perc.turn + VIEW;
    img.colour = 0xff00ff;

    img.mlx.mlx = mlx_init();
    img.mlx.mlx_win = mlx_new_window(img.mlx.mlx, 1500, 1000, "cub3d!");
    img.img = mlx_new_image(img.mlx.mlx, 1500, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    print_map(&img);
    ft_print_cub(img.perc.x, img.perc.y, &img);
    ft_vector(&img, img.perc.turn);
    ft_vectorview(&img);
    mlx_hook(img.mlx.mlx_win, 2, 0L, ft_key_press, &img);
   mlx_put_image_to_window(img.mlx.mlx, img.mlx.mlx_win, img.img, 0, 0);
    mlx_loop(img.mlx.mlx);
    return (0);
}