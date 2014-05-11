/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:47:16 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/11 17:17:07 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "philo.h"

pthread_mutex_t		g_sticks[THREADS];

void 	init_mutex(void)
{
	int 	i;

	i = 0;
	while (i < THREADS)
	{
		if (pthread_mutex_init(&(g_sticks[i]), NULL))
			return ;
		i++;
	}
}

void	*fct_thread_son(void *param)
{
	t_philo	*table;
	int		nb;
	int		rizq;
	int 	rrigh;

	table = (t_philo *)param;
	nb = table->nb;
	
		rizq = pthread_mutex_trylock(table->philo_st[nb].m_left);
		if (rizq == EBUSY)
			rrigh = pthread_mutex_trylock(table->philo_st[nb].m_right);
		if (rizq == EBUSY && rrigh == EBUSY)
		{
			printf("EATING THE SUSHI!\n");
			printf("je suis le thread numero %d\n mes points de vie sont %d\n mon mutex de gauche c'est %p\n mon mutex de droite c'est %p\n", nb,
			table->philo_st[nb].life, table->philo_st[nb].m_left, table->philo_st[nb].m_right);
			// if ((usleep(EAT_T)) == EBUSY)
			// {
			// 	if (table->philo_st[nb].life != MAX_LIFE)
			// 		table->philo_st[nb].life = MAX_LIFE;
			// 	pthread_mutex_unlock(table->philo_st[nb].m_left);
			// 	pthread_mutex_unlock(table->philo_st[nb].m_right);
			// }		
		}
		if ((rrigh != EBUSY && rizq == EBUSY) || (rrigh == EBUSY && rizq != EBUSY))
		{
			printf("philo in THINKING\n");
			printf("je suis le thread numero %d\n mes points de vie sont %d\n mon mutex de gauche c'est %p\n mon mutex de droite c'est %p\n", nb,
				table->philo_st[nb].life, table->philo_st[nb].m_left, table->philo_st[nb].m_right);
			if (usleep(THINK_T) == 0)
		 		table->philo_st[nb].life--;
		 	// if ((rrigh != EBUSY && rizq == EBUSY))
		 	// {
		 		

		 	// }
			if (table->philo_st[nb].life == 0)
			{
				pthread_mutex_destroy(table->philo_st[nb].m_left);
				pthread_mutex_destroy(table->philo_st[nb].m_right);
			}
		}
		if (rrigh != EBUSY && rizq != EBUSY)
		{
			printf("philo in rest ZZZZzzZZ\nb");
			printf("je suis le thread numero %d\n mes points de vie sont %d\n mon mutex de gauche c'est %p\n mon mutex de droite c'est %p\n", nb,
		 	table->philo_st[nb].life, table->philo_st[nb].m_left, table->philo_st[nb].m_right);
		 	if (usleep(REST_T) == 0)
		 		table->philo_st[nb].life--;
			if (table->philo_st[nb].life == 0)
			{
				pthread_mutex_destroy(table->philo_st[nb].m_left);
				pthread_mutex_destroy(table->philo_st[nb].m_right);
			}
		}
	return (0);

}

void	init_left_right_mutex(t_thread *philosopher_st, int nb)
{
	if (nb == 0)
	{
		philosopher_st->life = MAX_LIFE;
		philosopher_st->m_left = &g_sticks[6];
		philosopher_st->m_right = &g_sticks[nb];
		philosopher_st->ph_state = 0;
	}
	else
	{
		philosopher_st->life = MAX_LIFE;
		philosopher_st->m_left = &g_sticks[nb - 1];
		philosopher_st->m_right = &g_sticks[nb];
		philosopher_st->ph_state = 0;
	}
}

void		creat_threats(t_philo *table)
{
	// void	*ret;

	table->nb = 0;
	while (table->nb < THREADS)
	{
		// define life to MAX_LIFE
		// call function init_lr_mutex()
		init_left_right_mutex(&(table->philo_st[table->nb]), table->nb);
		if (pthread_create(&(table->philo_st[table->nb].philosopher_id), NULL, fct_thread_son, table))
		{
			ft_putendl("Couldn't create a philosopher");
			return ;
		}
		usleep(500);
		table->nb++;
	}
	// i = 0;
	// while (i < THREADS)
 //    {
 //        pthread_join(table->philosopher_id[i], &ret);
 //        i++;
 //    }
}

void	init_maieutic(t_philo *table)
{
	init_mutex();
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
