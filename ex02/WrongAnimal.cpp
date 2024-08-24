/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:29:53 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 18:44:33 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	DEBUG_PRINT("WrongAnimal class default constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	DEBUG_PRINT("WrongAnimal class copy-constructor called");

	_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	DEBUG_PRINT("WrongAnimal class assignment-operator overload called");

	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	DEBUG_PRINT("WrongAnimal class destructor called");
}

const std::string& WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(const std::string& newType) {
	_type = newType;
}

void WrongAnimal::makeSound() const {
	DEBUG_PRINT("* ĨИDΞ$CЯ!BΛBLΞ GłBßΞЯ1$H *");
}
