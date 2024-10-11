/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:25:17 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/11 16:28:40 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RESET       "\033[0m"
#define BOLD_RED         "\033[1m\033[31m"
#define BOLD_GREEN       "\033[1m\033[32m"
#define BOLD_WHITE       "\033[1m\033[37m"

int main()
{	
	Point A(3.4f, 1.3f);
	Point B(-1.2f, 4.0f);
	Point C(7.0f, 3.2f);
	Point point(5.0f, 3.2f);
	
	if (bsp(A, B, C, point))
		std::cout << BOLD_WHITE << "The point is" << BOLD_GREEN << " inside " << BOLD_WHITE << "the triangle! 🎉" << RESET << std::endl;
	else
		std::cout << BOLD_WHITE << "The point is" << BOLD_RED << " outside " << BOLD_WHITE << "the triangle! ❌" << RESET << std::endl;
	return 0;
}
