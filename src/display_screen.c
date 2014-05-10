/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 21:25:31 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/10 01:09:29 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "philo.h"

int			key_hook(int keycode, t_wf *game)
{
	if (keycode == ESC)
		exit (0);
	return (0);
}

int			expose_hook(t_wf *game)
{
	(void)draw;
	return (0);
}
