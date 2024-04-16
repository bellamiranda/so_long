/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:22:21 by ismirand          #+#    #+#             */
/*   Updated: 2024/04/16 15:29:24 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && open(argv[1], O_RDONLY) && find_ber(argv[1], ".ber"))
	{
		map_init(&game, argv[1]);
		map_validations(game);
		game->mlx = mlx_init();
		game->window = mlx_new_window(game->mlx, game->width * SZ, game->height * SZ, "so_long");
		set_images_to_pointer(game, SZ);
		put_images_on_window(game);
		game->movements = 0;
		game->was_exit = 0;
		mlx_hook(game->window, KeyPress, KeyPressMask, put_keys, game);
		//mlx_key_hook(game->window, put_keys, game); ->apenas 1 clique
		//mlx_loop_hook(game->window, put_keys, game); ->RODAR A MOEDA
		mlx_loop(game->mlx);
/* 
		for (int i = 0; i < game->height; i++)
			printf("%s\n", game->map[i]);

		exit_game(game, 0); */
	}
	return (write(2, "Error\nInvalid input\n", 21));
}

/* COMEÇANDO O JOGO:
- mlx_init -> inicializa a biblioteca
	guardar em um ponteiro void (NULL if init fails)
- abrir e fechar janela
	mlx_new_window -> abre uma janela
		(void *mlx(library pointer), int width, int height, char *title(window name))
		return window pointer void
	mlx_clear_window -> fecha a janela
	mlx_loop -> mantem a janela aberta
	mlx_hook -> linca clique de tecla a funcionalidades (A W S D)

- completa todos os requisitos para o jogo
	inicializa imagens para ponteiro
		mlx_put_image_to_xpm
	renderiza
		mlx_put_
 */

/* VALIDAÇÕES DO MAPA:
- se tem caracter invalido (!= 0, 1, P, E, C)
- se tem somente 1 E e 1 P
- se tem pelo menos um C
- se é fechado por 1s
- tamanho minimo (x + y > 8)
- se é retangular (tamanho das linhas tem que ser igual)
- se tem caminho valido pro P chegar ao E (colectables?) (flood fill)

- tamanho maximo (tamanho da tela do pc) - NAO FIZ
RETORNA mensagem de erro configurável \n */

/* para ser valido, a abertura do mapa tem que ser valida e 
os 4 ultimos digitos tem que ser ".ber"*/