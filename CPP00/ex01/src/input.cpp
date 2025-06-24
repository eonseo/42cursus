#include "main.hpp"

void clearBuffer() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

int isEOF() {
    if (std::cin.eof()) {
        clearBuffer();
        return 1;
    }
    return 0;
}

int isValidPhoneNumber(std::string tmp) {
	for (unsigned long i = 0; i < tmp.length(); i++) {
		if (!isdigit(tmp[i])) {
			std::cout << "Only numbers are allowed." << std::endl;
			return 0;
		}
	}
	return 1;
}

int isValidString(std::string tmp) {
	for (unsigned long i = 0; i < tmp.length(); i++) {
		if (!isalpha(tmp[i])) {
			std::cout << "Only alphabets are allowed" << std::endl;
			return 0;
		}
	}
	return 1;
}

std::string readCommand() {
    std::string tmp;

    getline(std::cin, tmp);
	if (isEOF()) {
		std::cout << "\nThe program has exited due to EOF." << std::endl;
		exit(0);
	}
    for (unsigned long i = 0; i < tmp.length(); i++) {
		tmp[i] = toupper(tmp[i]);
	}
    return tmp;
}

std::string getValidInput(std::string information) {
	std::string tmp;

	while (1) {
		std::cout << information << ": ";
		getline(std::cin, tmp);
		if (isEOF()) {
			std::cout << "\nThe program has exited due to EOF." << std::endl;
			exit(0);
		}
		if (tmp.empty()) {
			std::cout << "Empty field is not allowed" << std::endl;
			continue;
		}
		if (information == "phonenumber") {
			if (isValidPhoneNumber(tmp))
				return tmp;
		}
		else {
			if (isValidString(tmp))
				return tmp;
		}
	}
	return NULL;
}
