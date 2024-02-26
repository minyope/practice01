// 2023531001_final_Exam.h
#pragma once
#include <iostream>
#include <cstring>

class EDU_Person {
protected:
    char* name;
    int age;
    int number;
    char* department;

public:
    EDU_Person();
    virtual ~EDU_Person();
    virtual void getData() = 0;
    virtual void show() const = 0;
};

class Professor : public EDU_Person {
private:
    char* grade;
    int year;
    int pay;
    int subject;

public:
    Professor();
    ~Professor() override;
    void getData() override;
    void show() const override;
};

class Employee : public EDU_Person {
private:
    char* grade;
    int year;
    int pay;

public:
    Employee();
    ~Employee() override;
    void getData() override;
    void show() const override;
};

class Contract : public EDU_Person {
private:
    int pay;
    int date;

public:
    Contract();
    ~Contract() override;
    void getData() override;
    void show() const override;
};
