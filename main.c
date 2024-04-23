/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:22:21 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/23 17:26:02 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && find_ber(argv[1], ".ber") && fd > 0)
	{
		map_init(&game, argv[1]);
		map_validations(game);
		game->mlx = mlx_init();//inicializa a biblioteca
		game->wd = mlx_new_window(game->mlx, game->width * SZ,
				game->height * SZ, "so_long");//abre uma janela
		set_images_to_pointer(game, SZ);
		put_images_on_window(game);
		game->movements = 0;
		game->was_exit = 0;
		mlx_hook(game->wd, KeyPress, KeyPressMask, put_keys, game);//key continuously pressed
		mlx_hook(game->wd, DestroyNotify, ButtonPressMask, exit_game, game);//x clicked
		mlx_loop_hook(game->mlx, find_collectable, game);//spin the coin
		//mlx_loop_hook(game->mlx, find_enemy, game);//enemy movement
		//mlx_key_hook(game->wd, put_keys, game);//key pressed once
		mlx_loop(game->mlx);
	}
	if (fd < 0)
		return (write(2, "Error\nInvalid input\n", 21));
	return (0);
}

/* 
		PRINT THE MAP
		for (int i = 0; i < game->height; i++)
			printf("%s\n", game->map[i]);

		exit_game(game, 0); */

//fazer loop antes de encontrar cada C
//função rand da biblioteca mat

/* VALIDAÇÕES DO MAPA:
- se tem caracter invalido (!= 0, 1, P, E, C)
- se tem somente 1 E e 1 P
- se tem pelo menos um C
- se é fechado por 1s
- tamanho minimo (x + y > 8)
- se é retangular (tamanho das linhas tem que ser igual)
- se tem caminho valido pro P chegar ao E (colectables?) (flood fill)

- tamanho maximo (tamanho da tela do pc) - NAO FIZ
RETORNA mensagem de erro configurável \n

para ser valido, a abertura do mapa tem que ser valida e 
os 4 ultimos digitos tem que ser ".ber"*/
