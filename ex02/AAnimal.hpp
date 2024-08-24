/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:59:24 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 20:17:05 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT(X) std::cout << X << std::endl
# endif // !DEBUG_PRINT

# ifndef ERROR_PRINT
#  define ERROR_PRINT(X) std::cerr << X << std::endl;
# endif // !ERROR_PRINT

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& rhs);
	virtual ~AAnimal();

	const std::string& getType() const;

	void setType(const std::string& newType);

	virtual void makeSound() const = 0;
protected:
	std::string _type;
};
