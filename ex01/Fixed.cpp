/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/09 20:21:30 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _nbrValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbrValue = intNbr << this->_fractBits;
}

Fixed::Fixed(const float floatNbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbrValue = roundf(floatNbr * (1 << this->_fractBits));
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbrValue = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->_nbrValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbrValue = raw;
}

float Fixed::toFloat() const
{
	float nbr;
	
	nbr = (float)this->_nbrValue / (float)(1 << this->_fractBits);
	return (nbr);
}

int Fixed::toInt() const
{
	int nbr;

	nbr = this->_nbrValue >> this->_fractBits;
	return (nbr);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}