#include <iostream>
#include <string>

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}
    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::string response;
    std::cout << "Хотите указать начальное значение счетчика? Введите yes или no: ";
    std::cin >> response;

    int initialValue = 1;
    if (response == "yes") {
        std::cout << "Введите начальное значение счетчика: ";
        std::cin >> initialValue;
    }

    Counter counter(initialValue);

    char command;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << "Текущее значение счетчика: " << counter.getValue() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Неверная команда. Попробуйте снова." << std::endl;
        }
    } while (command != 'x');

    return 0;
}