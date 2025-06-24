/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:33:40 by eonoh             #+#    #+#             */
/*   Updated: 2025/06/20 00:38:28 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Contact {
	private:
		std::string lastName;
		std::string firstName;
		std::string nickName;
		std::string phoneNumber;
		std::string secret;

	public:
		const Contact& operator=(const Contact& other);
		void	 	fill();
		std::string getLastName();
		std::string getFirstName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};