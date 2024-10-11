/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:36 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 16:14:28 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
	return ;
}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y))
{
	return ;
}

Point::Point(const Point& src): x(src.x), y(src.y)
{
	return ;
}

Point& Point::operator=(const Point& src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

Point::~Point()
{
	return ;
}

Fixed const Point::getX() const
{
	return (this->x);
}

Fixed const Point::getY() const
{
	return (this->y);
}
