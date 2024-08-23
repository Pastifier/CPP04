/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:36:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 19:07:19 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	DEBUG_PRINT("Cat default constructor called");

	Cat::_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal() {
	DEBUG_PRINT("Cat copy constructor called");

	Animal::_type = other.Animal::_type;
	Cat::_type = other.Cat::_type;	/*	The `Cat::` can be omitted,
										I just want to make a point.*/
}

Cat& Cat::operator=(const Cat& rhs) {
	DEBUG_PRINT("Cat assignment-operator overload called");

	if (this == &rhs)
		return *this;

	Animal::_type = rhs.Animal::_type;
	_type = rhs._type;
	return *this;
}

Cat::~Cat() {
	DEBUG_PRINT("Cat destructor called");
}

void Cat::makeSound() const {
	DEBUG_PRINT("Meow...");
}
