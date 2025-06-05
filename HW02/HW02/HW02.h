#pragma once

#include <iostream>

//Animal�̶�� �⺻ Ŭ������ ���� �մϴ�.
//Animal Ŭ�������� `makeSound()`��� ���� ���� �Լ��� �����մϴ�.
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

//Animal Ŭ������ ��ӹ޾� �پ��� ���� Ŭ������ �����մϴ�. ��) Dog, Cat, Cow
class Dog : public Animal {
public:
    //�� Ŭ�������� makeSound()�Լ��� �������Ͽ� �ش� ������ �Ҹ��� ����մϴ�.
    void makeSound() override;
};

class Cat : public Animal {
public:
    void makeSound() override;
};

class Cow : public Animal {
public:
    void makeSound() override;
};

