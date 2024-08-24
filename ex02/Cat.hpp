/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:31:58 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 20:19:47 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
