/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:24 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/23 18:43:57 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT(X) std::cout << X << std::endl
# endif // !DEBUG_PRINT

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	~WrongAnimal();

	const std::string& getType() const;

	void setType(const std::string& newType);

	void makeSound() const;
protected:
	std::string _type;
};
