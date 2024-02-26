// 2023531001_final_Exam.cpp
#include "2023531001_final_Exam.h"

#include <vector>

using namespace std;

// Implementation of EDU_Person
EDU_Person::EDU_Person() : name(nullptr), age(0), number(0), department(nullptr) {}

EDU_Person::~EDU_Person() {
    delete[] name;
    delete[] department;
}

// Implementation of Professor
Professor::Professor() : grade(nullptr), year(0), pay(0), subject(0) {}

Professor::~Professor() {
    delete[] grade;
}

void Professor::getData() {
    cout << "교원의 이름: ";
    cin.ignore();
    char temp[100];
    cin.getline(temp, sizeof(temp));
    name = new char[strlen(temp) + 1];
    strcpy(name, temp);

    cout << "나이: ";
    cin >> age;

    cout << "교직원번호: ";
    cin >> number;

    cout << "소속 학과: ";
    cin.ignore();
    cin.getline(temp, sizeof(temp));
    department = new char[strlen(temp) + 1];
    strcpy(department, temp);

    cout << "직급: ";
    cin.getline(temp, sizeof(temp));
    grade = new char[strlen(temp) + 1];
    strcpy(grade, temp);

    cout << "근무 연수: ";
    cin >> year;

    cout << "연봉: ";
    cin >> pay;

    cout << "강의 과목 수: ";
    cin >> subject;
}

void Professor::show() const {
    cout << "교원 정보\n";
    cout << "이름: " << name << "\n";
    cout << "나이: " << age << "\n";
    cout << "교직원번호: " << number << "\n";
    cout << "소속 학과: " << department << "\n";
    cout << "직급: " << grade << "\n";
    cout << "근무 연수: " << year << "\n";
    cout << "연봉: " << pay << "\n";
    cout << "강의 과목 수: " << subject << "\n";
}

// Implementation of Employee
Employee::Employee() : grade(nullptr), year(0), pay(0) {}

Employee::~Employee() {
    delete[] grade;
}

void Employee::getData() {
    cout << "행정직원의 이름: ";
    cin.ignore();
    char temp[100];
    cin.getline(temp, sizeof(temp));
    name = new char[strlen(temp) + 1];
    strcpy(name, temp);

    cout << "나이: ";
    cin >> age;

    cout << "교직원번호: ";
    cin >> number;

    cout << "소속 학과: ";
    cin.ignore();
    cin.getline(temp, sizeof(temp));
    department = new char[strlen(temp) + 1];
    strcpy(department, temp);

    cout << "직급: ";
    cin.ignore();
    cin.getline(temp, sizeof(temp));
    grade = new char[strlen(temp) + 1];
    strcpy(grade, temp);

    cout << "근무 연수: ";
    cin >> year;

    cout << "연봉: ";
    cin >> pay;
}

void Employee::show() const {
    cout << "행정직원 정보\n";
    cout << "이름: " << name << "\n";
    cout << "나이: " << age << "\n";
    cout << "교직원번호: " << number << "\n";
    cout << "소속 학과: " << department << "\n";
    cout << "직급: " << grade << "\n";
    cout << "근무 연수: " << year << "\n";
    cout << "연봉: " << pay << "\n";
}

// Implementation of Contract
Contract::Contract() : pay(0), date(0) {}

Contract::~Contract() {}

void Contract::getData() {
    cout << "임시직원의 이름: ";
    cin.ignore();
    char temp[100];
    cin.getline(temp, sizeof(temp));
    name = new char[strlen(temp) + 1];
    strcpy(name, temp);

    cout << "나이: ";
    cin >> age;

    cout << "교직원번호: ";
    cin >> number;

    cout << "소속 학과: ";
    cin.ignore();
    cin.getline(temp, sizeof(temp));
    department = new char[strlen(temp) + 1];
    strcpy(department, temp);

    cout << "임금: ";
    cin >> pay;

    cout << "계약 만료일: ";
    cin >> date;
}

void Contract::show() const {
    cout << "임시직원 정보\n";
    cout << "이름: " << name << "\n";
    cout << "나이: " << age << "\n";
    cout << "교직원번호: " << number << "\n";
    cout << "소속 학과: " << department << "\n";
    cout << "임금: " << pay << "\n";
    cout << "계약 만료일: " << date << "\n";
}

int main() {
    vector<EDU_Person*> eduStaff;  // Vector to store different types of EDU_Person objects

    int choice;
    do {
        cout << "=========================\n";
        cout << "대학교의 교직원들을 관리하는 프로그램\n";
        cout << "=========================\n";
        cout << "1. 교원 입력\n";
        cout << "2. 행정직원 입력\n";
        cout << "3. 임시직원 입력\n";
        cout << "4. 교원 조회\n";
        cout << "5. 행정직원 조회\n";
        cout << "6. 임시직원 조회\n";
        cout << "0. 종료\n";

        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Professor* professor = new Professor();
                professor->getData();
                eduStaff.push_back(professor);
                break;
            }
            case 2: {
                Employee* employee = new Employee();
                employee->getData();
                eduStaff.push_back(employee);
                break;
            }
            case 3: {
                Contract* contract = new Contract();
                contract->getData();
                eduStaff.push_back(contract);
                break;
            }
            case 4:
            case 5:
            case 6: {
                int type = choice - 4;  // Map menu options to indices 0, 1, 2
                for (const auto& person : eduStaff) {
                    // Check the type and call show() accordingly
                    if (type == 0 && dynamic_cast<Professor*>(person)) {
                        person->show();
                    } else if (type == 1 && dynamic_cast<Employee*>(person)) {
                        person->show();
                    } else if (type == 2 && dynamic_cast<Contract*>(person)) {
                        person->show();
                    }
                }
                break;
            }
            case 0:
                cout << "프로그램을 종료합니다.\n";
                break;
            default:
                cout << "올바르지 않은 선택입니다. 다시 선택해주세요.\n";
        }
    } while (choice != 0);

    // Clean up allocated memory
    for (const auto& person : eduStaff) {
        delete person;
    }

    return 0;
}
