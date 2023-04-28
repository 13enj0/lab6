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

class Deque {
private:
    Tovar* dequeArray;
    int size;
    int front;
    int rear;
    int count;

public:
    Deque(int s) {
        size = s;
        dequeArray = new Tovar[size];
        front = -1;
        rear = 0;
        count = 0;
    }

    ~Deque() {
        delete[] dequeArray;
    }

    void addFront(Tovar p) {
        if (count == size) {
            cout << "Дек переповнений!" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (front == 0) {
                front = size - 1;
            }
            else {
                front--;
            }
            dequeArray[front] = p;
            count++;
        }
    }

    void addRear(Tovar p) {
        if (count == size) {
            cout << "Дек переповнений!" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
                rear = 0;
            }
            else if (rear == size - 1) {
                rear = 0;
            }
            else {
                rear++;
            }
            dequeArray[rear] = p;
            count++;
        }
    }

    void removeFront() {
        if (count == 0) {
            cout << "Дек порожній!" << endl;
        }
        else {
            if (front == rear) {
                front = -1;
                rear = 0;
            }
            else if (front == size - 1) {
                front = 0;
            }
            else {
                front++;
            }
            count--;
        }
    }

    void removeRear() {
        if (count == 0) {
            cout << "Дек порожній!" << endl;
        }
        else {
            if (front == rear) {
                front = -1;
                rear = 0;
            }
            else if (rear == 0) {
                rear = size - 1;
            }
            else {
                rear--;
            }
            count--;
        }
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == size);
    }

    Tovar frontElement() {
        return dequeArray[front];
    }

    Tovar rearElement() {
        return dequeArray[rear];
    }

    void removeByIndex(int index) {
        if (index < 0 || index >= count) {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            int i = (front + index) % size;
            while (i != rear) {
                dequeArray[i] = dequeArray[(i + 1) % size];
                i = (i + 1) % size;
            }
            rear = (rear - 1 + size) % size;
            count--;
        }
    }

    void printElement(int index) {
        if (index < 0 || index >= count)
        {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            int i = (front + index) % size;
            Tovar p = dequeArray[i];
            cout << "Назва: " << p.name << endl;
            cout << "Одиниця вимірювання: " << p.unit << endl;
            cout << "Сорт: " << p.sort << endl;
            cout << "Кількість: " << p.quantity << endl;
            cout << "Вага: " << p.weight << endl;
        }
    }
    void printAll() {
        if (count == 0) {
            cout << "Дек порожній!" << endl;
        }
        else {
            int i = front;
            while (i != rear) {
                Tovar p = dequeArray[i];
                cout << "Назва: " << p.name << endl;
                cout << "Одиниця вимірювання: " << p.unit << endl;
                cout << "Сорт: " << p.sort << endl;
                cout << "Кількість: " << p.quantity << endl;
                cout << "Вага: " << p.weight << endl;
                i = (i + 1) % size;
            }
            Tovar p = dequeArray[rear];
            cout << "Назва: " << p.name << endl;
            cout << "Одиниця вимірювання: " << p.unit << endl;
            cout << "Сорт: " << p.sort << endl;
            cout << "Кількість: " << p.quantity << endl;
            cout << "Вага: " << p.weight << endl;
        }
    }
};

int main() {


    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
    //для коректним виведення в консоль тільки так))
    Deque deque(5);
    Tovar p1 = { "Яблука", "кг", "Мішель", 10, 5.0 };
    Tovar p2 = { "Апельсини", "кг", "Навел", 7, 4.0 };
    Tovar p3 = { "Груші", "кг", "Льодовик", 15, 6.0 };
    Tovar p4 = { "Банани", "кг", "Кавендіш", 12, 3.5 };
    Tovar p5 = { "Мандарини", "кг", "Клебер", 8, 2.5 };
    deque.addFront(p1);
    deque.addRear(p2);
    deque.addFront(p3);
    deque.addRear(p4);
    deque.printAll();

    deque.removeByIndex(2);
    deque.printAll();

    deque.removeFront();
    deque.printAll();

    deque.removeRear();
    deque.printAll();

    deque.printElement(1);

    return 0;
}


