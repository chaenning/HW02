#include <iostream>
#include "HW02.h"

using namespace std;


void Dog::makeSound() {
    cout << "Dog : Bark" << endl;
}

void Cat::makeSound() {
    cout << "Cat : Meow" << endl;
}

void Cow::makeSound() {
    cout << "Cow : Moo" << endl;
}

// 동물을 동물원에 추가하는 함수
// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
// - 같은 동물이라도 여러 번 추가될 수 있습니다.
// - 입력 매개변수: Animal* (추가할 동물 객체)
// - 반환값: 없음
void Zoo::addAnimal(Animal* animal) {
    if (animalCount < 10) {
        animals[animalCount++] = animal;
    }
    else {
        cout << "동물원이 가득 찼습니다." << endl;
    }
}


// 동물원에 있는 모든 동물의 행동을 수행하는 함수
// - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
// - 입력 매개변수: 없음
// - 반환값: 없음
void Zoo::performActions() {
    for (int i = 0; i < animalCount; i++) {
        animals[i]->makeSound();
    }
}

// Zoo 소멸자
// - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
// - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
// - 입력 매개변수: 없음
// - 반환값: 없음
Zoo ::~Zoo() {
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
}

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal() {
    int r = rand() % 3; 
    switch (r) {
    case 0: return new Dog();
    case 1: return new Cat();
    case 2: return new Cow();
    default: return nullptr;  // 안전장치
    }
}

int main()
{
    cout << "- - - - - - 필수 기능 - - - - - -" << endl;
    // 메인 함수에서 Animal 타입의 포인터 배열을 선언합니다.
    Animal* animal[3];
    // Dog, Cat, Cow 자료형의 변수를 선언하고, 배열에 저장해봅니다.
    animal[0] = new Dog();
    animal[1] = new Cat();
    animal[2] = new Cow();

    // Animal 배열을 반복문으로 순회하면서 각 동물의 울음소리를 내게 합니다.
    for (int i = 0; i < 3; i++) {
        animal[i]->makeSound();
    }
    for (int i = 0; i < 3; i++) {
        delete animal[i];
    }

    cout << endl << "- - - - - - 도전 기능 - - - - - -" << endl;
    srand(static_cast<unsigned int>(time(NULL)));

    Zoo zoo;

    for (int i = 0; i < 10; ++i) {
        zoo.addAnimal(createRandomAnimal());
    }

    cout << "동물원에서 들리는 소리" << endl;
    zoo.performActions();

    return 0;
}
