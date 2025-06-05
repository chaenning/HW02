#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>


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


class Zoo {
private:
    Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
    int animalCount = 0;  // ���� ��ϵ� ���� ��
public:
    // ������ �������� �߰��ϴ� �Լ�
    // - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
    // - ���� �����̶� ���� �� �߰��� �� �ֽ��ϴ�.
    // - �Է� �Ű�����: Animal* (�߰��� ���� ��ü)
    // - ��ȯ��: ����
    void addAnimal(Animal* animal);

    // �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
    // - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
    // - �Է� �Ű�����: ����
    // - ��ȯ��: ����
    void performActions();

    // Zoo �Ҹ���
    // - Zoo ��ü�� �Ҹ�� ��, ���� ���Ϳ� ����� ��� ���� ��ü�� �޸𸮸� �����մϴ�.
    // - �޸� ������ �����ϱ� ���� ���� �Ҵ�� Animal ��ü�� `delete` �մϴ�.
    // - �Է� �Ű�����: ����
    // - ��ȯ��: ����
    ~Zoo();
};

// ���� ������ �����ϴ� �Լ�
// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
// - �Է� �Ű�����: ����
// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
Animal* createRandomAnimal();