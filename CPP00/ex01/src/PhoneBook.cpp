/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:31 by eonoh             #+#    #+#             */
/*   Updated: 2025/06/20 01:26:18 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(): currentIndex(-1) {}

void PhoneBook::addContact() {
	currentIndex++;
	if (currentIndex == 8) {
		moveContactList();
		currentIndex = 7;
	}
	contactList[currentIndex].fill();
}

void PhoneBook::moveContactList() {
	for (int i = 0; i < 7; i++) {
		contactList[i] = contactList[(i + 1)];
	}
}

int PhoneBook::isValidIndex(int index) {
	if (std::cin.fail()) {
		clearBuffer();
		return 0;
	}
	else if (!(index >= 0 && index < 8)) {
		std::cout << "Please select an index between 0 and 7" << std::endl;
		std::cout << "Please try again." << std::endl;
		clearBuffer();
		return 0;
	}
	if (index > currentIndex) {
		std::cout << "There's no data in index " << index << std::endl;
		std::cout << "Please try again." << std::endl;
		clearBuffer();
		return 0;
	}
	return 1;
}

void PhoneBook::printSpecificContact(int i) {
	std::cout << "|";
	std::cout << std::setw(10) << i << "|";
	printCell(contactList[i].getFirstName());
	printCell(contactList[i].getLastName());
	printCell(contactList[i].getNickName());
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::printPersonalInformation(int i) {
	std::cout << "Firstname: " << contactList[i].getFirstName() << std::endl;
	std::cout << "Lastname: " << contactList[i].getLastName() << std::endl;
	std::cout << "Nickname: " << contactList[i].getNickName() << std::endl;
	std::cout << "Phonenumber: " << contactList[i].getPhoneNumber() << std::endl;
	std::cout << "Darkestsecret: " << contactList[i].getDarkestSecret() << std::endl;
}

void PhoneBook::printContactList() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|-----index|first name|-last name|--nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i <= currentIndex; i++) {
		printSpecificContact(i);
	}
}

void printCell(std::string str){
	if (str.length() > 10) {
		std::cout << str.substr(0, 9) << ".|";
	}
	else {
		std::cout << std::setw(10) << str << "|";
	}
}

void PhoneBook::searchPhoneBook() {
	int selectedIndex;

	printContactList();
	std::cout << "Please select an index to view their phone number: ";
	std::cin >> selectedIndex;
	if (isValidIndex(selectedIndex)) {
		clearBuffer();
		printPersonalInformation(selectedIndex);
		return ;
	}
}

int PhoneBook::getCurrentIndex() {
	return currentIndex;
}
 