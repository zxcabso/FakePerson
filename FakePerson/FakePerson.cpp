#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <ctime>	

namespace fs = std::filesystem;

class Person {
public:
	Person() {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	std::string getName()
	{
		return names[rndIndex(names)];
	}
	std::string getLastName()
	{
		return lastnames[rndIndex(lastnames)];
	}
	int getAge()
	{
		return generateRandomNumber(2000,2012);
	}
	std::string getBirthdayDay()
	{
		return months[rndIndex(months)] + "," + std::to_string(generateRandomNumber(1, 31));
	}
	std::string getLocation()
	{
		return location[rndIndex(location)];
	}
	std::string getMotherName()
	{
		return Fnames[rndIndex(Fnames)];
	}
	int getMotherAge()
	{
		return generateRandomNumber(1980, 2003);
	}
private:
	std::vector<std::string> names = {" ���� ", " ������ " , " ������ " , " ������ ", "�������", "����", "�����", "������", "�����", "��������", "�������", "�������", "�����", "������" };
	std::vector<std::string> lastnames = {"������" , "������", "������" , "����������"};
	std::vector<std::string> months = { "������", "�������", "����", "������", "���","����","����", "������", "��������", "�������", "������", "�������" };
	std::vector<std::string> location = {"105064, �. ������, ��. �������� ���, �. 27","191025, �. �����-���������, ��. ������, �. 32","620075, �. ������������, ��. ������, �. 15","454084, �. ���������, ��. �����, �. 45","603000, �. ������ ��������, ��. ������� ����������, �. 19","630099, �. �����������, ��. �����������, �. 1","350000, �. ���������, ��. �������, �. 69","443000, �. ������, ��. �������������, �. 7","620014, �. ������������, ��. ����������, �. 61","394018, �. �������, ��. ������, �. 8","127006, �. ������, ��. ��������, �. 22","196105, �. �����-���������, �����. ���� ��������, �. 34","625000, �. ������, ��. ����������, �. 80","660021, �. ����������, ��. ����� ������, �. 49","680000, �. ���������, ��. ���������-���������, �. 5","214000, �. ��������, ��. ������, �. 10","603005, �. ������ ��������, ��. ���������, �. 29","394000, �. �������, ��. ������������, �. 53","410012, �. �������, ��. ����������, �. 86","162600, �. ���������, ��. ������, �. 85","620137, �. ������������, ��. ���������, �. 68","660049, �. ����������, ��. ����, �. 90","630091, �. �����������, ��. ���������, �. 42"," 344002, �. ������-��-����, ��. ������� �������, �. 58","170100, �. �����, ��. ���������, �. 4","354000, �. ����, ��. ��������� ��������, �. 50","443013, �. ������, ��. ������, �. 10","614000, �. �����, ��. ������, �. 40","630000, �. �����������, ��. ������������, �. 47","414000, �. ���������, ��. ���������, �. 15"," 450000, �. ���, ��. ������, �. 76","432000, �. ���������, ��. ��������, �. 18","660049, �. ����������, ��. ������, �. 73"," 634050, �. �����, �����. ������, �. 30","190068, �. �����-���������, ��. ���������� ��������, �. 139"," 414000, �. ���������, ��. ������, �. 7","670000, �. ����-���, ��. ������, �. 5"," 414000, �. ���������, ��. ������� ����������, �. 18","664000, �. �������, ��. ������, �. 21","644000, �. ����, ��. ������, �. 10","660049, �. ����������, ��. ������"};
	std::vector<std::string> Fnames = { "���", "������" , "�����" , "�����", "��������", "���", "������", "���"};
	int rndIndex(const std::vector<std::string>& vec) {
		int size = vec.size();
		int random_index = std::rand() % size;
		return random_index;
	}
	int generateRandomNumber(int min, int max) {
		return min + std::rand() % (max - min + 1);
	}
};

void makeLogFolders(std::string directory,std::string writeToFile)
{
	if (!fs::exists(directory))
	{
		fs::create_directory(directory);
	}

	int count = 0;
	for (const auto& entry : fs::directory_iterator(directory)) {
		if (entry.is_regular_file()) {
			count++;
		}
	}

	std::string fileN = directory + "/Person" + std::to_string(count++) + ".txt";

	std::ofstream outFile(fileN);
	if (outFile.is_open()) {
		outFile << writeToFile;
		outFile.close();
		std::cout << "������ ��������� � " << fileN << std::endl;
	}
	else {
		std::cerr << "�� ������� ������� ���� " << fileN << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	Person person1;
	static std::string victimName = person1.getName();
	static std::string lastname = person1.getLastName();
	std::string data =
		"\nName [+] " + victimName
		+ "\nLastName[+] " + lastname +
		"\nAge [+] " + std::to_string(2024 - person1.getAge())
		+ "\nBirthday [+] " + person1.getBirthdayDay()
		+ "\nLocation [+] " + person1.getLocation()
		+ "\n-------------\n"
		+ "\nMother name [+] " + person1.getMotherName()
		+ "\nMother lastname [+] " + lastname + "a"
		+ "\nMother age [+] " + std::to_string(2024 - person1.getMotherAge())
		+ "\nMother birthday [+] " + person1.getBirthdayDay()
		+ "\n-------------\n"
		+ "\nDad name [+] " + person1.getName()
		+ "\nDad lastname [+] " + lastname
	    + "\nDad age [+] " + std::to_string((2024 - person1.getMotherAge()) + 3)
		+ "\nDad birthday [+] " + person1.getBirthdayDay();
	std::cout << "�������� ���� ���� ������� � txt ���� �� ������ ���������� C:\Persons " << std::endl;
	makeLogFolders("C://Persons",data);

}
