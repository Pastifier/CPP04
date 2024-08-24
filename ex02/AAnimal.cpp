/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:29:53 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 20:18:57 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	DEBUG_PRINT("AAnimal class default constructor called");
}

AAnimal::AAnimal(const AAnimal& other) {
	DEBUG_PRINT("AAnimal class copy-constructor called");

	_type = other._type;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	DEBUG_PRINT("AAnimal class assignment-operator overload called");

	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal() {
	DEBUG_PRINT("AAnimal class destructor called");
}

const std::string& AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(const std::string& newType) {
	_type = newType;
}
