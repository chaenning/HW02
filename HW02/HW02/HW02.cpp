#include <iostream>

using namespace std;

//Animal이라는 기본 클래스를 정의 합니다.
//Animal 클래스에는 `makeSound()`라는 순수 가상 함수를 포함합니다.
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal(){}
};

//Animal 클래스를 상속받아 다양한 동물 클래스를 생성합니다. 예) Dog, Cat, Cow
class Dog : public Animal {
public:
    //각 클래스에서 makeSound()함수를 재정의하여 해당 동물의 소리를 출력합니다.
    void makeSound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Moo" << endl;
    }
};

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
