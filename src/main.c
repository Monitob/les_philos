/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:47:16 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/10 08:09:18 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "philo.h"

pthread_mutex_t		sticks[THREADS];

void 	init_mutex(t_philo *table)
{
	int 	i;

	i = 0;
	while (i < THREADS)
	{
		if (pthread_mutex_init(&(sticks[i]), NULL))
			return ;
		i++;
	}
	(void)table;
}

void	start_dinner(t_philo *table)
{
	int 	i;

	i = MAX_LIFE;
	pthread_mutex_lock(&sticks[i]);
	while (i > 0)
	{

		i--;
	}
	pthread_mutex_unlock(&sticks[i]);
}

void	*fct_thread_son(void *param)
{
	int i;

	i = 0;
	pthread_mutex_lock(&sticks[i]);
	while (1)
	{
		printf("thread param %d and i-> %d\n", *((int *)param), );
		i++;
		sleep (1);
	}
	pthread_mutex_unlock(&sticks[i]);
	pthread_exit(0);
}

// PTHREAD_CREATE_JOINABLE-> on peut attendre pour le thread(fil)
// PTHREAD_CREATE_DETACHED -> on libere automatiquement

void		creat_threats(t_philo *table)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < THREADS)
	{
		if (pthread_create(&(table->philosopher_id[i]), NULL, fct_thread_son, &sticks[i]))
		{
			ft_putendl("Couldn't create a philosopher");
			return ;
		}
		i++;
	}
	start_dinner(table);
	i = 0;
	while (i < THREADS)
    {
        pthread_join(table->philosopher_id[i], &ret);
        i++;
    }
}

void	init_maieutic(t_philo *table)
{
	init_mutex(table);
	creat_threats(table);
}

int		main(void)
{
	t_philo		table;

	init_maieutic(&table);

	// init_mutex(&table);
	// wait_threats(table);
	//table.mlx = mlx_init();
	//table.win = mlx_new_window(table.mlx, 1200, 1000, "Les Philos");
	//mlx_expose_hook(table.win, expose_hook, &wlf);
	//mlx_loop(table.mlx);

	return (0);
}
