#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>


class GlidingWindow {
private:
	std::string message;
	std::string path;
	std::string window;
	short windowSize, bandWidh;

	std::string sender;
	std::string receiver;

public:
	GlidingWindow(std::string str) {
		this->path = str;
		if (!readFromFile()) {
			this->message = str;
			this->path = "";
		}
	}

private:
	bool readFromFile() {
		std::ifstream file(path);
		std::getline(file, this->message);
		if (!file.is_open()) {
			return false;
		}
		file.close();
		return true;
	}
public:
	void printMessage() {
		std::cout << "Mesajul este: " << message << std::endl;
	}

};

int main() {
	std::cout << "Citire mesaj sau cale de la tastatura(1) sau din fisier(Default)?\n";
	int option;
	std::cin >> option;
	std::string str;
	//in cin ramane un caracter newline care trebuie eliminat
	//cin.ignore curata bufferul de intrare de caracterele ramase de la citirea optiunii de mai sus 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (option) {
	case 1:
		std::cout << "Toarna!\n";
		std::getline(std::cin, str);
		break;
	default:
		str = "G:/My Drive/Mate info ID/An II/Semestrul II/Retele de calculatoare/Tema 2/Test.txt";
		break;
	}
	GlidingWindow glidingWindow(str);
	glidingWindow.printMessage();
	return 0;
}