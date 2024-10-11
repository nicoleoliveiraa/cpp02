/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 11:40:38 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _nbrValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNbr)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_nbrValue = intNbr << this->_fractBits;
}

Fixed::Fixed(const float floatNbr)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_nbrValue = roundf(floatNbr * (1 << this->_fractBits));
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nbrValue = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->_nbrValue);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed& fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed& fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed& fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed& fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed& fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed& fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator+(const Fixed& right) const
{
	Fixed fixed;
	int res;
	
	res = this->_nbrValue + right.getRawBits();
	fixed.setRawBits(res);
	return (fixed);
}

Fixed Fixed::operator-(const Fixed& right) const
{
	Fixed fixed;
	int res;
	
	res = this->_nbrValue - right.getRawBits();
	fixed.setRawBits(res);
	return (fixed);
}

Fixed Fixed::operator*(const Fixed& right) const
{
	Fixed fixed;
	int res;
	
	res = this->_nbrValue * right._nbrValue >> _fractBits;
	fixed.setRawBits(res);
	return (fixed);
}

Fixed Fixed::operator/(const Fixed& right) const
{
	Fixed fixed;
	int res;
	
	res = this->_nbrValue / right._nbrValue << _fractBits;
	fixed.setRawBits(res);
	return (fixed);
}

Fixed Fixed::operator++()
{
	this->_nbrValue++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_nbrValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed before = *this;
	
	this->_nbrValue++;
	return (before);
}

Fixed Fixed::operator--(int)
{
	Fixed before = *this;
	
	this->_nbrValue--;
	return (before);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{

	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}