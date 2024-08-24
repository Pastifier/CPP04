/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:55:36 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 18:32:04 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	DEBUG_PRINT("Brain default constructor called");
}

Brain::Brain(const Brain& other) : _thoughts(other._thoughts) {
	DEBUG_PRINT("Brain copy-constructor called");
}

Brain::Brain(const std::string& thoughts) : _thoughts(thoughts) {
	DEBUG_PRINT("Brain constructor with string called");
}

Brain& Brain::operator=(const Brain& rhs) {
	DEBUG_PRINT("Brain assignment-operator overload called");

	if (this == &rhs)
		return *this;
	_thoughts = rhs._thoughts;
	return *this;
}

Brain::~Brain() {
	DEBUG_PRINT("Brain destructor called");
}

const std::string& Brain::ergoSum() const {
	return _thoughts;
}
