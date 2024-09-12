/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:37 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/12 17:11:03 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a(42);
		Fixed b(42.5f);

		std::cout << "Comparison operator test:" << std::endl;
		if (a > b)
			std::cout << "a > b" << std::endl;
		if (a < b)
			std::cout << "a < b" << std::endl;
		if (a >= b)
			std::cout << "a >= b" << std::endl;
		if (a <= b)
			std::cout << "a <= b" << std::endl;
		if (a == b)
			std::cout << "a == b" << std::endl;
		if (a != b)
			std::cout << "a != b" << std::endl;
			
		std::cout << "Arithmetic operator test:" << std::endl;
		std::cout << "a + b:" << std::endl << a + b << std::endl;
		std::cout << "a - b:" << std::endl << a - b << std::endl;
		std::cout << "a * b:" << std::endl << a * b << std::endl;
		std::cout << "a / b:" << std::endl << a / b << std::endl;

		Fixed c(42);
		
		std::cout << "Increment and decrement operator test:" << std::endl;
		std::cout << "++c: " << ++c << std::endl;
		std::cout << "c++: " << c++ << std::endl;
		std::cout << "--c: " << --c << std::endl;
		std::cout << "c--: " << c-- << std::endl;

		std::cout << "Minimum and maximum test:" << std::endl;
		std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
		std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

		const Fixed d(7);
		const Fixed e(6.5f);
		
		std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
		std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;
	}
}