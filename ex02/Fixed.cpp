/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:53 by akovalev          #+#    #+#             */
/*   Updated: 2024/09/12 17:04:37 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_fixedPointValue);
}

void Fixed::setRawBits(int const raw) 
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

Fixed::Fixed(int const int_val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = int_val << this->_fractionalBits;
}

Fixed::Fixed(float const float_val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(float_val * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return(_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return(out << fixed.toFloat());
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed temp;

	temp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (temp);
}
Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed temp;

	temp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (temp);
}
Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed temp;

	temp.setRawBits(static_cast<int>(static_cast<long long>(this->getRawBits()) * static_cast<long long>(fixed.getRawBits()) >> _fractionalBits));
	return (temp);
}
Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed temp;

	if (fixed.getRawBits() == 0)
	{
		std::cout << "Error: divison by zero" << std::endl;
		return Fixed(0);
	}
	temp.setRawBits(static_cast<int>((static_cast<long long>(this->getRawBits()) << _fractionalBits) / fixed.getRawBits()));
	return (temp);
}

Fixed& Fixed::operator++()
{
	++this->_fixedPointValue;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++this->_fixedPointValue;
	return(temp);
}
Fixed& Fixed::operator--()
{
	--this->_fixedPointValue;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->_fixedPointValue;
	return(temp);	
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
		