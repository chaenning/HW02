#include <iostream>
#include "HW02.h"

using namespace std;


void Dog::makeSound() {
    cout << "Bark" << endl;
}

void Cat::makeSound() {
    cout << "Meow" << endl;
}

void Cow::makeSound() {
    cout << "Moo" << endl;
}


int main()
{
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

    return 0;
}
