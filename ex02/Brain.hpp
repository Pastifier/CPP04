/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:20:41 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/24 18:31:51 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT(X) std::cout << X << std::endl
# endif //!DEBUG_PRINT

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	Brain(const std::string& thoughts);
	Brain& operator=(const Brain& rhs);
	~Brain();

	const std::string& ergoSum() const;

private:
	std::string _thoughts;
};
