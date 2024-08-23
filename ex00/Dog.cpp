/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:12:08 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 17:28:17 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	DEBUG_PRINT("Dog default constructor called");

	Dog::_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal() {
	DEBUG_PRINT("Dog copy constructor called");

	Animal::_type = other.Animal::_type;
	Dog::_type = other.Dog::_type;	/*	The `Dog::` can be omitted,
										I just want to make a point.*/
}

Dog& Dog::operator=(const Dog& rhs) {
	DEBUG_PRINT("Dog assignment-operator overload called");

	if (this == &rhs)
		return *this;

	Animal::_type = rhs.Animal::_type;
	_type = rhs._type;
	return *this;
}

Dog::~Dog() {
	DEBUG_PRINT("Dog destructor called");
}

void Dog::makeSound() const {
	DEBUG_PRINT("Woof!");
}
