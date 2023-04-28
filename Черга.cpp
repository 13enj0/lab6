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

class Queue {
private:
    Tovar* queueArray;
    int size;
    int front;
    int rear;
    int count;

public:
    Queue(int s) {
        size = s;
        queueArray = new Tovar[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] queueArray;
    }

    void enqueue(Tovar p) {
        if (count == size) {
            cout << "Черга переповнена!" << endl;
        }
        else {
            rear = (rear + 1) % size;
            queueArray[rear] = p;
            count++;
        }
    }

    void dequeue() {
        if (count == 0) {
            cout << "Черга порожня!" << endl;
        }
        else {
            front = (front + 1) % size;
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
        return queueArray[front];
    }

    void removeByIndex(int index) {
        if (index < 0 || index >= count) {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            int i = front + index;
            while (i != rear) {
                queueArray[i % size] = queueArray[(i + 1) % size];
                i = (i + 1) % size;
            }
            rear = (rear - 1 + size) % size;
            count--;
        }
    }

    void printElement(int index) {
        if (index < 0 || index >= count) {
            cout << "Неправильний індекс!" << endl;
        }
        else {
            int i = front + index;
            Tovar p = queueArray[i % size];
            cout << "Інформація про товар з індексом " << index << ":" << endl;
            cout << "Назва: " << p.name << endl;
            cout << "Одиниця виміру: " << p.unit << endl;
            cout << "Сорт: " << p.sort << endl;
            cout << "Кількість: " << p.quantity << endl;
            cout << "Вага: " << p.weight << endl;
        }
    }

    void printAll() {
        if (count == 0) {
            cout << "Черга порожня!" << endl;
        }
        else {
            cout << "Інформація про всі товари:" << endl;
            int i = front;
            int j = 0;
            while (j < count) {
                Tovar p = queueArray[i];
                cout << "Назва: " << p.name << endl;
                cout << "Одиниця виміру: " << p.unit << endl;
                cout << "Сорт: " << p.sort << endl;
                cout << "Кількість: " << p.quantity << endl;
                cout << "Вага: " << p.weight << endl;
                i = (i + 1) % size;
                j++;
            }
        }
    }
    };

int main() {
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
    //для коректним виведення в консоль тільки так))
    Queue q(5);
    Tovar t1 = { "Шоколад", "штуки", "молочний", 10, 0.1 };
    Tovar t2 = { "Молоко", "літри", "звичайне", 5, 1 };
    Tovar t3 = { "Сир", "кілограми", "гауда", 2, 0.5 };
    Tovar t4 = { "Яблука", "кілограми", "зелені", 20, 0.2 };
    Tovar t5 = { "Хліб", "штуки", "білий", 3, 0.4 };
    q.enqueue(t1);
    q.enqueue(t2);
    q.enqueue(t3);
    q.enqueue(t4);
    q.enqueue(t5);

    q.printAll();

    q.dequeue();
    q.dequeue();

    q.printAll();

    q.removeByIndex(1);

    q.printAll();

    q.printElement(2);

    return 0;

}
