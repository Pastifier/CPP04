/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:36:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 18:48:08 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	DEBUG_PRINT("WrongCat default constructor called");

	WrongCat::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	DEBUG_PRINT("WrongCat copy constructor called");

	WrongAnimal::_type = other.WrongAnimal::_type;
	WrongCat::_type = other.WrongCat::_type;	/*	The `WrongCat::` can be omitted,
										I just want to make a point.*/
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	DEBUG_PRINT("WrongCat assignment-operator overload called");

	if (this == &rhs)
		return *this;

	WrongAnimal::_type = rhs.WrongAnimal::_type;
	_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat() {
	DEBUG_PRINT("WrongCat destructor called");
}

void WrongCat::makeSound() const {
	DEBUG_PRINT("Meow...");
}
