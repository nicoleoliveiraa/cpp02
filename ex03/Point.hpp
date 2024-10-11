/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:46:59 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 15:08:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& src);
	Point& operator=(const Point& src);
	~Point();
	Fixed const getX() const;
	Fixed const getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP