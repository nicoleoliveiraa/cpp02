/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/09 19:39:59 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _nbrValue;
	static const int _fractBits;

public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif // FIXED_HPP