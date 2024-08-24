/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:34:34 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 18:44:04 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& rhs);
	~Dog();

	void makeSound() const;
	const Brain* getCogito() const;
private:
	Brain* _cogito;
};
