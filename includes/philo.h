/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 04:33:38 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/11 05:44:41 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
/*
** Maccros
*/
# define MAX_LIFE		50 // nombre de poins de vie max
# define EAT_T			5 //nombre de segs pour manger
# define REST_T			3 // nombre de segs lesquels un philo se repose
# define THINK_T		2 // nombre de segs pour reflechir
# define THINK_OUT		5 // nombre de segs pour arreter la simulation
# define THREADS		7
# define EBUSY			0

typedef struct		s_thread
{
	int				life;
	int 			ph_id;
	int				ph_state;
	pthread_t		philosopher_id;
	pthread_mutex_t	*m_left;
	pthread_mutex_t	*m_right;	
}					t_thread;

typedef struct		s_philo
{
	void			*mlx;
	void			*win;
	t_thread		philo_st[THREADS];
	int				nb;
}					t_philo;

void	init_left_right_mutex(t_thread *philosopher_st, int nb);
void	*fct_thread_son(void *param);
void	init_maieutic(t_philo *table);
// void	*fct_thread_son(void	*param);
// t_philo	*init_maieutic(t_philo *table);

#endif
