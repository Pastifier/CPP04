/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:36:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 18:44:52 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <exception>

Cat::Cat() : Animal() {
	DEBUG_PRINT("Cat default constructor called");

	Cat::_type = "Cat";
	try {
		_cogito = new Brain("Meow...");
	} catch (const std::exception& e) {
		ERROR_PRINT(e.what());
		ERROR_PRINT("Field `_cogito` will now point to `NULL`");
		_cogito = NULL;
	}
}

Cat::Cat(const Cat& other) : Animal() {
	DEBUG_PRINT("Cat copy constructor called");

	Animal::_type = other.Animal::_type;
	Cat::_type = other.Cat::_type;	/*	The `Cat::` can be omitted,
										I just want to make a point.*/
	try {
		if (!other._cogito) {
			_cogito = NULL;
			DEBUG_PRINT("WARNING: Field `_cogito` is pointing to `NULL`");
		} else {
			_cogito = new Brain();
			*_cogito = *(other._cogito);
		}
	} catch (const std::exception& e) {
		ERROR_PRINT(e.what());
		ERROR_PRINT("Field `_cogito` will now point to `NULL`");
		_cogito = NULL;
	}
}

Cat& Cat::operator=(const Cat& rhs) {
	DEBUG_PRINT("Cat assignment-operator overload called");

	if (this == &rhs)
		return *this;

	Animal::_type = rhs.Animal::_type;
	_type = rhs._type;

	try {
		if (!rhs._cogito) {
			_cogito = NULL;
			DEBUG_PRINT("WARNING: Field `_cogito` is pointing to `NULL`");
		} else {
			*_cogito = *(rhs._cogito);
		}
	} catch (const std::exception& e) {
		ERROR_PRINT(e.what());
		ERROR_PRINT("Field `_cogito` will now point to `NULL`");
		_cogito = NULL;
	}
	return *this;
}

Cat::~Cat() {
	DEBUG_PRINT("Cat destructor called");
	if (_cogito)
		delete _cogito;
}

void Cat::makeSound() const {
	if (_cogito)
		DEBUG_PRINT(_cogito->ergoSum());
	else
		DEBUG_PRINT("* HEAD EMPTY *");
}

const Brain* Cat::getCogito() const {
	return _cogito;
}
