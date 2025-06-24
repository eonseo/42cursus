/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:52:04 by eonoh             #+#    #+#             */
/*   Updated: 2025/06/20 01:31:52 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void printIntro() {
	std::cout << "Phonebook Program Usage:" << std::endl;
	std::cout << "This program allows you to manage your contacts in a phonebook." << std::endl;
	std::cout << "The available commands are as follows" << std::endl;
}

void printCommands() {
	std::cout << "\nADD: save new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: quit the program\n" << std::endl;
}

int main()
{
	std::string tmp;
	PhoneBook phoneBook;

	printIntro();
	while (1)
	{
		printCommands();
		tmp = readCommand();
		if (tmp == "ADD") {
			phoneBook.addContact();
		}
		else if (tmp == "SEARCH") {
			phoneBook.searchPhoneBook();
		}
		else if (tmp == "EXIT") {
			std::cout << "Bye bye ~!*_< (찡긋)" << std::endl;
			break ;
		}
		else {
			std::cout << "\nInvalid command. Please check the available commands below:" << std::endl;
		}
	}
	return (0);
}
