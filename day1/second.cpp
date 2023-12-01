#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//word to int ?
int	wtoi(std::string str)
{
	
	return (0);
}

int	lastdigit(std::string line) {

	for (int len = line.length(); len >= 0; len--) {
		if (line[len] >= '0' && line[len] <= '9')
			return (line[len] - '0');
		if (wtoi(&line[len]))
			return (wtoi(&line[len]));
	}
	return (0);
}

int	firstdigit(std::string line) {
	int	len = line.length();

	for (int i = 0; i < len; i++) {
		if (line[i] >= '0' && line[i] <= '9')
			return (line[i] - '0');
	}
	return (0);
}

int	get_calibrval(std::string line) {
	int	res;

	res = 0;
	res = firstdigit(line) * 10 + lastdigit(line);
	return (res);
}

int	main(void) {
	std::fstream	file;
	std::string sa;
	int result;

	file.open("1input.txt");
	result = 0;

	if (file.is_open()) {
		while (std::getline(file, sa))
		{
			result += get_calibrval(sa);
			std::cout << result << std::endl;
		}
		file.close();
		std::cout << "res : " << result << std::endl;
	}
	return (0);
}
