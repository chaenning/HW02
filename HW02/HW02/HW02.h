#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>


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


class Zoo {
private:
    Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
    int animalCount = 0;  // 현재 등록된 동물 수
public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal);

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions();

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo();
};

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal();