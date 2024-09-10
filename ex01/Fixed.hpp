/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:45 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/10 18:13:10 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed(int const int_val);
		Fixed(float const float_val);		
		Fixed& operator=(const Fixed& fixed);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif