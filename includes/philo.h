/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 04:33:38 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/09 04:42:18 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <mlx.h>
# include <libft.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
/*
** Maccros
*/
# define MAX_LIFE		2000 // nombre de poins de vie max
# define EAT_T			15 //nombre de segs pour manger
# define REST_T			9 // nombre de segs lesquels un philo se repose
# define THINK_T		10 // nombre de segs pour reflechir
# define THINK_OUT		60 // nombre de segs pour arreter la simulation

#endif
