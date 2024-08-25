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
	std::vector<std::string> names = {" Иван ", " Володя " , " Сергей " , " Никита ", "Алексей", "Влад", "Артур", "Богдан", "Борис", "Валентин", "Василий", "Виталий", "Денис", "Матвей" };
	std::vector<std::string> lastnames = {"Агапов" , "Алехин", "Блохин" , "Шестипалов"};
	std::vector<std::string> months = { "Январь", "Февраль", "Март", "Апрель", "Май","Июнь","Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	std::vector<std::string> location = {"105064, г. Москва, ул. Земляной Вал, д. 27","191025, г. Санкт-Петербург, ул. Марата, д. 32","620075, г. Екатеринбург, ул. Ленина, д. 15","454084, г. Челябинск, ул. Труда, д. 45","603000, г. Нижний Новгород, ул. Большая Покровская, д. 19","630099, г. Новосибирск, ул. Депутатская, д. 1","350000, г. Краснодар, ул. Красная, д. 69","443000, г. Самара, ул. Ленинградская, д. 7","620014, г. Екатеринбург, ул. Белинского, д. 61","394018, г. Воронеж, ул. Кирова, д. 8","127006, г. Москва, ул. Тверская, д. 22","196105, г. Санкт-Петербург, просп. Юрия Гагарина, д. 34","625000, г. Тюмень, ул. Республики, д. 80","660021, г. Красноярск, ул. Карла Маркса, д. 49","680000, г. Хабаровск, ул. Муравьева-Амурского, д. 5","214000, г. Смоленск, ул. Ленина, д. 10","603005, г. Нижний Новгород, ул. Пискунова, д. 29","394000, г. Воронеж, ул. Плехановская, д. 53","410012, г. Саратов, ул. Московская, д. 86","162600, г. Череповец, ул. Ленина, д. 85","620137, г. Екатеринбург, ул. Восточная, д. 68","660049, г. Красноярск, ул. Мира, д. 90","630091, г. Новосибирск, ул. Каменская, д. 42"," 344002, г. Ростов-на-Дону, ул. Большая Садовая, д. 58","170100, г. Тверь, ул. Советская, д. 4","354000, г. Сочи, ул. Курортный проспект, д. 50","443013, г. Самара, ул. Победы, д. 10","614000, г. Пермь, ул. Ленина, д. 40","630000, г. Новосибирск, ул. Орджоникидзе, д. 47","414000, г. Астрахань, ул. Советская, д. 15"," 450000, г. Уфа, ул. Ленина, д. 76","432000, г. Ульяновск, ул. Спасская, д. 18","660049, г. Красноярск, ул. Ленина, д. 73"," 634050, г. Томск, просп. Ленина, д. 30","190068, г. Санкт-Петербург, ул. Московский проспект, д. 139"," 414000, г. Астрахань, ул. Кирова, д. 7","670000, г. Улан-Удэ, ул. Ленина, д. 5"," 414000, г. Астрахань, ул. Красная Набережная, д. 18","664000, г. Иркутск, ул. Ленина, д. 21","644000, г. Омск, ул. Ленина, д. 10","660049, г. Красноярск, ул. Вейнба"};
	std::vector<std::string> Fnames = { "Юля", "Милана" , "Алиса" , "Арина", "Виктория", "Зоя", "Лариса", "Оля"};
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
		std::cout << "Данные сохранены в " << fileN << std::endl;
	}
	else {
		std::cerr << "Не удалось создать файл " << fileN << std::endl;
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
	std::cout << "Сохранил вашу фейк персону в txt файл по данной директории C:\Persons " << std::endl;
	makeLogFolders("C://Persons",data);

}
