/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:28 by eonoh             #+#    #+#             */
/*   Updated: 2025/06/21 18:11:16 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Contact::fill() {
	std::string tmp;

	this->firstName = getValidInput("firstname");
	this->lastName = getValidInput("lastname");
	this->nickName = getValidInput("nickname");
	this->phoneNumber = getValidInput("phonenumber");;
	this->secret = getValidInput("secret");
}

const Contact& Contact::operator=(const Contact &other) {
	this->lastName = other.lastName;
	this->firstName = other.firstName;
	this->nickName = other.nickName;
	this->phoneNumber = other.phoneNumber;
	this->secret = other.secret;

	return *this;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getNickName()
{
	return nickName;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return secret;
}
