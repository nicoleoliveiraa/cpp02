/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/10 11:13:37 by nsouza-o         ###   ########.fr       */
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

	bool operator>(Fixed& fixed) const;
	bool operator<(Fixed& fixed) const;
	bool operator>=(Fixed& fixed) const;
	bool operator<=(Fixed& fixed) const;
	bool operator==(Fixed& fixed) const;
	bool operator!=(Fixed& fixed) const;
};
	
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP