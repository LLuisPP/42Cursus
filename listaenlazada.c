/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listaenlazada.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:01 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/29 16:59:46 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
	char *nombre;
	struct s_nodo *sig;
}libro;

libro *listalibro(libro *lista)
{
	lista = NULL;
	return (lista);
}

libro *agregarlibro(libro *lista, char *nombre)
{
	libro *nuevolibro;
	*aux
	nuevolibro = (libro*)malloc(sizeof(libro));
	nuevolibro->nombre = nombre;
	nuevolibro->sig = NULL;
	if (lista == NULL){
	lista = nuevolibro;
	}
	else
	{
		aux = lista;
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevolibro
	}
	return (lista);
}

int	main()
{
	libro *lista = listalibro(lista);
	lista = NULL;
	lista = agregarlibro(lista,"hola manola");
	lista = agregarlibro(lista,"elemento agregado");
	while (lista != NULL)
	{
	printf("%s\n", lista->nombre);
	lista = lista->sig;
	}
	printf("%p\n", lista->sig);
	return (0);
}
