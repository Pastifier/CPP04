/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:29:53 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 17:36:24 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	DEBUG_PRINT("Animal class default constructor called");
}

Animal::Animal(const Animal& other) {
	DEBUG_PRINT("Animal class copy-constructor called");

	_type = other._type;
}

Animal& Animal::operator=(const Animal& rhs) {
	DEBUG_PRINT("Animal class assignment-operator overload called");

	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

Animal::~Animal() {
	DEBUG_PRINT("Animal class destructor called");
}

const std::string& Animal::getType() const {
	return _type;
}

void Animal::setType(const std::string& newType) {
	_type = newType;
}

void Animal::makeSound() const {
	DEBUG_PRINT("* ĨИDΞ$CЯ!BΛBLΞ GłBßΞЯ1$H *");
}
