/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 11:40:17 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _nbrValue;
	static const int _fractBits;

public:
	Fixed();
	Fixed(const int intNbr);
	Fixed(const float floatNbr);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed& fixed);
	bool operator<(const Fixed& fixed);
	bool operator>=(const Fixed& fixed);
	bool operator<=(const Fixed& fixed);
	bool operator==(const Fixed& fixed);
	bool operator!=(const Fixed& fixed);

	Fixed operator+(const Fixed& right) const;
	Fixed operator-(const Fixed& right) const;
	Fixed operator*(const Fixed& right) const;
	Fixed operator/(const Fixed& right) const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
	static Fixed& min(Fixed& first, Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
};
	
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP