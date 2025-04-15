/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:12 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 17:49:20 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*	
int	main(void)
{
	int *array1, *array2;
	size_t i = 0, size = 5;

	// Testando ft_calloc
	array1 = (int *)ft_calloc(size, sizeof(int));
	if (!array1)
	{
		printf("Erro ao alocar memória com ft_calloc.\n");
		return (1);
	}

	// Testando calloc do sistema
	array2 = (int *)calloc(size, sizeof(int));
	if (!array2)
	{
		printf("Erro ao alocar memória com calloc.\n");
		free(array1);
		return (1);
	}

	// Exibindo resultados para comparação
	printf("Conteúdo do array alocado com ft_calloc:\n");
	while (i < size)
	{
		printf("array1[%zu] = %d\n", i, array1[i]);
		i++;
	}

	i = 0; // resetando o índice para o próximo loop

	printf("\nConteúdo do array alocado com calloc:\n");
	while (i < size)
	{
		printf("array2[%zu] = %d\n", i, array2[i]);
		i++;
	}

	// Liberando a memória
	free(array1);
	free(array2);

	return (0);
}
}*/