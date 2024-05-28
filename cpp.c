// calculator.cpp
#include <iostream>
#include <thread>
#include <vector>

// Functie pentru adunare
void add(int a, int b) {
    std::cout << "Adunare: " << a << " + " << b << " = " << a + b << std::endl;
}

// Functie pentru scadere
void subtract(int a, int b) {
    std::cout << "Scadere: " << a << " - " << b << " = " << a - b << std::endl;
}

// Functie pentru inmultire
void multiply(int a, int b) {
    std::cout << "Inmultire: " << a << " * " << b << " = " << a * b << std::endl;
}

// Functie pentru impartire
void divide(int a, int b) {
    if (b != 0) {
        std::cout << "Impartire: " << a << " / " << b << " = " << a / b << std::endl;
    } else {
        std::cout << "Impartire: Divizare cu zero!" << std::endl;
    }
}

int main() {
    int a = 10, b = 5;

    // Crearea thread-urilor pentru fiecare operatie
    std::thread t1(add, a, b);
    std::thread t2(subtract, a, b);
    std::thread t3(multiply, a, b);
    std::thread t4(divide, a, b);

    // Asteptam ca toate thread-urile sa se termine
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

