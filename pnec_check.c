/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnec_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gd-auria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:02:01 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/26 12:29:31 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

static int  p_echeck(t_first *letters)
{
    int he;
    int wi;

    he = -1;
    while (++he < letters->Ymax - 1)
    {
        wi = 0;
        while (wi < letters->Xmax - 1)
        {
			if (letters->matrix[he][wi] == 'P')
				letters->map.P++;
			else if (letters->matrix[he][wi] == 'E')
				letters->map.E++;
            wi++;
		}
	}
	if (letters->map.P != 1)
	{
        printf ("P ERROR\n");
        exit (0);
        return (0);
    }
	else if (letters->map.E != 1)
		return (0);
	return (1);
}

static int n_check(t_first *letters)
{
    int he;
    int wi;

    he = -1;
    while (++he < letters->Ymax)
    {
        wi = -1;
        while (++wi < letters->Xmax)
        {
            if (letters->matrix[he][wi] == 'N')
            {
                letters->map.N++;
                if (letters->map.N > 1)
                {
                    printf("WRONG N\n");
                    return (0);
                }
            }
        }
    }
    return (1);
}

static int c_check(t_first *letters)
{
    int he;
    int wi;

    he = -1;
    while (++he < letters->Ymax)
    {
        wi = -1;
        while (++wi < letters->Xmax)
        {
            if (letters->matrix[he][wi] == 'C')
            {
                letters->map.C++;
            }
        }
    }
    if (letters->map.C <= 0 || letters->map.C > 6 )
    {
        printf("WRONG C\n");
        return (0);
    }
    return (1);
}

int	my_char(t_first *str)
{
    int i;
    int j;


    i = -1;
    while (str->matrix[++i])
    {
        j = 0;
        while (str->matrix[i][j])
        {
            if (str->matrix[i][j] != '0' && str->matrix[i][j] != '1' && str->matrix[i][j] != 'E' && str->matrix[i][j] != 'N' && str->matrix[i][j] != 'C' && str->matrix[i][j] != 'P')
            {
                printf ("MY_CHAR = WRONG LETTER");
                return (0);
            }
            j++;
        }
    }
	//if (x == '0' || x == '1' || x == 'P' || x == 'E' || x == 'C' || x == 'N')
    return (1);
}

int letter_check(t_first *letters)
{
    printf ("mychar\n");
	if (my_char(letters) == 1)
    {
        if (p_echeck(letters) == 1 && n_check(letters) == 1 && c_check(letters) == 1)
            return (1);
    }
    return (0);
}
