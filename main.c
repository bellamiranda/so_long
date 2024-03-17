/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:22:21 by ismirand          #+#    #+#             */
/*   Updated: 2024/03/12 15:41:41 by ismirand         ###   ########.fr       */
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
		//game_init(game);
		game->library = mlx_init(); //inicializa a biblioteca
		game->window = mlx_new_window(game->library, 1000, 1000, "teste"); //abre uma janela
		mlx_loop(game->library); //mantem a janela aberta
		
		for (int i = 0; i < game->lines; i++)
			printf("%s\n", game->map[i]);
		free_struct(game);
		return (0);
		
		printf("ola\n");
	}
}

/* COMEÇANDO O JOGO:
- abrir e fechar janela
	mlx_new_window -> abre uma janela
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