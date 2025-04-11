/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:32:46 by miaghabe          #+#    #+#             */
/*   Updated: 2025/04/11 19:57:17 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_hendle(fractal);
}