/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:53:04 by candriam          #+#    #+#             */
/*   Updated: 2024/07/15 17:50:08 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
