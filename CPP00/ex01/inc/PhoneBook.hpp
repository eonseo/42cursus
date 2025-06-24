/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:36:08 by eonoh             #+#    #+#             */
/*   Updated: 2025/06/20 01:31:38 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {
	private:
		int currentIndex;
		Contact contactList[8];

		void moveContactList();
		void printContactList();
		int getCurrentIndex();
		int isValidIndex(int index);
		void printSpecificContact(int i);
		void printPersonalInformation(int i);
	public:
		PhoneBook();
		void searchPhoneBook();
		void addContact();
};
