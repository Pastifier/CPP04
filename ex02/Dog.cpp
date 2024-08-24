/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:12:08 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 20:20:54 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	DEBUG_PRINT("Dog default constructor called");

	Dog::_type = "Dog";
	try {
		_cogito = new Brain("Woof!");
	} catch (const std::exception& e) {
		ERROR_PRINT(e.what());
		ERROR_PRINT("Field `_cogito` will now point to `NULL`");
		_cogito = NULL;
	}
}

Dog::Dog(const Dog& other) : AAnimal() {
	DEBUG_PRINT("Dog copy constructor called");

	AAnimal::_type = other.AAnimal::_type;
	Dog::_type = other.Dog::_type;	/*	The `Dog::` can be omitted,
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

Dog& Dog::operator=(const Dog& rhs) {
	DEBUG_PRINT("Dog assignment-operator overload called");

	if (this == &rhs)
		return *this;

	AAnimal::_type = rhs.AAnimal::_type;
	_type = rhs._type;

	try {
		if (!rhs._cogito) {
			_cogito = NULL;
			DEBUG_PRINT("WARNING: Field `_cogito` is pointing to `NULL`");
		} else {
			_cogito = new Brain();
			*_cogito = *(rhs._cogito);
		}
	} catch (const std::exception& e) {
		ERROR_PRINT(e.what());
		ERROR_PRINT("Field `_cogito` will now point to `NULL`");
		_cogito = NULL;
	}
	return *this;
}

Dog::~Dog() {
	DEBUG_PRINT("Dog destructor called");
	if (_cogito)
		delete _cogito;
}

void Dog::makeSound() const {
	if (_cogito)
		DEBUG_PRINT(_cogito->ergoSum());
	else
		DEBUG_PRINT("* HEAD EMPTY *");
}

const Brain* Dog::getCogito() const {
	return _cogito;
}
