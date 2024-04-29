/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotber_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/26 12:28:20 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

int dot_ber(char *fileber)
{
    int glen;

    glen = ft_strlen(fileber) - 1;
    if (glen > 4)
    {
        if(fileber[glen] == 'r' && fileber[glen - 1] == 'e'
            && fileber[glen - 2] == 'b' && fileber[glen - 3] == '.')
        {
                return (1);
        }
        else
        {
            exit (0);
        }
    }
    return (1);
}
