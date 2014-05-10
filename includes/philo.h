/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 04:33:38 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/10 07:50:23 by jbernabe         ###   ########.fr       */
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

typedef struct		s_philo
{
	void			*mlx;
	void			*win;
	pthread_t		philosopher_id[THREADS];
	int 			ph_id;
	int				ph_state;
	int				point_php_life;			
}					t_philo;

// void	*fct_thread_son(void	*param);
// t_philo	*init_maieutic(t_philo *table);

#endif
