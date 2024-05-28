
#include <iostream>
#include <thread>
void add(int a, int b) {
    std::cout << "adunare: " << a << " + " << b << " = " << a + b << std::endl;
}
void subtract(int a, int b) {
    std::cout << "scadere: " << a << " - " << b << " = " << a - b << std::endl;
}
void multiply(int a, int b) {
    std::cout << "inmultire: " << a << " * " << b << " = " << a * b << std::endl;
}
void divide(int a, int b) {
    if (b != 0) {
        std::cout << "impartire: " << a << " / " << b << " = " << a / b << std::endl;
    } else {
        std::cout << "impartire:" << std::endl;
    }
}
int main() {
    int a, b;
    char operation;
    std::cout << "introduceti numarul 1: ";
    std::cin >> a;
    std::cout << "introduceti numarul 2: ";
    std::cin >> b;
    std::cout << "ilegeti ce vrei sa faci(+, -, *, /): ";
    std::cin >> operation;
    std::thread t;
    switch(operation) {
        case '+':
            t = std::thread(add, a, b);
            break;
        case '-':
            t = std::thread(subtract, a, b);
            break;
        case '*':
            t = std::thread(multiply, a, b);
            break;
        case '/':
            t = std::thread(divide, a, b);
            break;
        default:
            std::cout << "operatie nu merge" << std::endl;
            return 1;
    }
    t.join();

    return 0;
}

