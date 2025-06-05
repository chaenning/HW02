#pragma once

#include <iostream>

//Animal이라는 기본 클래스를 정의 합니다.
//Animal 클래스에는 `makeSound()`라는 순수 가상 함수를 포함합니다.
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

//Animal 클래스를 상속받아 다양한 동물 클래스를 생성합니다. 예) Dog, Cat, Cow
class Dog : public Animal {
public:
    //각 클래스에서 makeSound()함수를 재정의하여 해당 동물의 소리를 출력합니다.
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

