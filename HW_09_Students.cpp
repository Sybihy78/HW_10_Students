#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>


using Student = std::tuple<std::string, std::string, int>;
using Group = std::pair<std::string, std::vector<Student>>;


void printStudent(const Student& st) {
	std::cout << std::get<0>(st) << " ";
	std::cout << std::get<1>(st) << ", ";
	std::cout << std::get<2>(st) << "\n";
}


void printGroup(const Group& gr) {
	const auto& name = gr.first;
	const auto& students = gr.second;
	std::cout << "Group Name: " << name << "\n";
	std::cout << "Count of students: " << students.size() << "\n";
	std::cout << "Students:\n";
	for (auto& st : students) {
		printStudent(st);
	}
}


void searchName(const std::vector<Student>& vec, const std::string& str) {
	std::cout << "Search student with name: " << str << std::endl;
	for (auto a : vec) {
		auto& studentName = std::get<0>(a);
		if (studentName == str) {
			printStudent(a);
		}
	}
}


void searchSurname(const std::vector<Student>& vec, const std::string& str) {
	std::cout << "Search student with surname: " << str << std::endl;
	for (auto a : vec) {
		auto& studentSurname = std::get<1>(a);
		if (studentSurname == str) {
			printStudent(a);
		}
	}
}


void searchAge(const std::vector<Student>& vec, const int& age) {
	std::cout << "Search student with age: " << age << std::endl;
	for (auto a : vec) {
		auto& studentAge = std::get<2>(a);
		if (studentAge == age) {
			printStudent(a);
		}
	}
}


int main() {

	Group g1("G001", {});
	auto& students = g1.second;
	students.emplace_back("Petr", "Petrov", 20); 
	students.emplace_back("Natalia", "Smirnova", 19);
	students.emplace_back("Victor", "Andreev", 18);
	Student s("Ivan", "Ivanov", 20);
	students.push_back(s);
	students.emplace_back("Natalia", "Kuhno", 18);

	printGroup(g1);
	std::cout << std::endl;

	std::cout << "Sort group for student's name:" << std::endl;
	std::sort(students.begin(), students.end(),
		[](const Student& lhs, const Student& rhs) {
		return std::get<0>(lhs) < std::get<0>(rhs);
	});

	for (auto a : students) {
		printStudent(a);
	}
	std::cout << std::endl;
	
	std::cout << "Sort group for student's surname:" << std::endl;
	std::sort(students.begin(), students.end(),
		[](const Student& lhs, const Student& rhs) {
		return std::get<1>(lhs) < std::get<1>(rhs);
	});

	for (auto a : students) {
		printStudent(a);
	}
	std::cout << std::endl;

	std::cout << "Sort group for student's age:" << std::endl;
	std::sort(students.begin(), students.end(),
		[](const Student& lhs, const Student& rhs) {
		return std::get<2>(lhs) < std::get<2>(rhs);
	});

	for (auto a : students) {
		printStudent(a);
	}
	std::cout << std::endl;

	searchName(students, "Natalia");
	std::cout << std::endl;
	searchSurname(students, "Petrov");
	std::cout << std::endl;
	searchAge(students, 20);
	std::cout << std::endl;
	
	system("pause");
	return 0;
}
