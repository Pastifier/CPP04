/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:31:58 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 18:47:55 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& rhs);
	~Cat();

	void makeSound() const;
	const Brain* getCogito() const;
private:
	Brain* _cogito;
};
