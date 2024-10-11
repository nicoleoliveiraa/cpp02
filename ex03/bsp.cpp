/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:03:47 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 16:06:21 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float isInside(Point const first, Point const second, Point const point)
{
	Fixed aX = first.getX();
	Fixed bX = second.getX();
	Fixed pX = point.getX();
	Fixed aY = first.getY();
	Fixed bY = second.getY();
	Fixed pY = point.getY();
	Fixed ret = (bX - aX) * (pY - aY) - (bY - aY) * (pX - aX);
	return (ret.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float one = isInside(a, b, point);
	float two = isInside(b, c, point);
	float three = isInside(c, a, point);

	if ((one > 0 && two > 0 && three > 0) || (one < 0 && two < 0 && three < 0))
		return (true);
	return (false);
}