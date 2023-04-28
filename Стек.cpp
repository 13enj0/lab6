#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct Tovar {
    string name;
    string unit;
    string sort;
    int quantity;
    float weight;
};

class Stack {
private:
    Tovar* stackArray;
    int size;
    int top;

public:
    Stack(int s) {
        size = s;
        stackArray = new Tovar[size];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(Tovar p) {
        if (top == size - 1) {
            cout << "Стек переповнений!" << endl;
        }
        else {
            top++;
            stackArray[top] = p;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Стек порожній!" << endl;
        }
        else {
            top--;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    Tovar topElement() {
        return stackArray[top];
    }

    void removeByIndex(int index) {
        if (index < 0 || index > top) {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            for (int i = index; i < top; i++) {
                stackArray[i] = stackArray[i + 1];
            }
            top--;
        }
    }

    void printElement(int index) {
        if (index < 0 || index > top) {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            Tovar p = stackArray[index];
            cout << "Інформація про товар з індексом " << index << ":" << endl;
            cout << "Назва: " << p.name << endl;
            cout << "Одиниця виміру: " << p.unit << endl;
            cout << "Сорт: " << p.sort << endl;
            cout << "Кількість: " << p.quantity << endl;
            cout << "Вага: " << p.weight << endl;
        }
    }

    void printAll() {
        if (top == -1) {
            cout << "Стек порожній!" << endl;
        }
        else {
            cout << "Інформація про всі товари:" << endl;
            for (int i = top; i >= 0; i--) {
                Tovar p = stackArray[i];
                cout << "Назва: " << p.name << endl;
                cout << "Одиниця виміру: " << p.unit << endl;
                cout << "Сорт: " << p.sort << endl;
                cout << "Кількість: " << p.quantity << endl;
                cout << "Вага: " << p.weight << endl;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
    //для коректним виведення в консоль тільки так))
    Stack stack(5);

    // Додавання нових елементів
    Tovar t1 = { "Молоко", "літри", "А", 2, 1.5 };
    stack.push(t1);

    Tovar t2 = { "Хліб", "штуки", "В", 3, 0.4 };
    stack.push(t2);

    // Видалення елементу зі структури
    //stack.removeByIndex(1);

    // Виведення на екран інформації про заданий елемент
    stack.printElement(1);

    // Виведення на екран інформації зі всієї структури
    stack.printAll();

    return 0;
}
