/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:34:34 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 20:21:08 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
