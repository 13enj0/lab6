#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Tovar
{
	string name = "default";/*Назва*/
	string type = "default";/*одиниця вимірування*/
	string sort = "default";/*сорт*/
	int k = 0;/*кількість(вага)*/
	float cost = 0;//ціна
};

void take_data(Tovar& tovar)
{
	cout << "Iм'я:  ";
	cin >> tovar.name;
	char change = 1;
	cout << "Одиниця вимірювання товару: " << endl;
	cin >> tovar.type;
	cout << "Сорт:  ";
	cin >> tovar.sort;
	cout << "Вага Кг.:  ";
	cin >> tovar.k;
	cout << "Вартiсть грн:  ";
	cin >> tovar.cost;
}


class Stack {
public:
    // Масив для зберігання елементів стеку
    Tovar* stackArray;
   
    // Індекс верхнього елементу стеку
    int top;
public:
 // Розмір масиву
    int size;
public:
    // Конструктор
    Stack(int s) {
        size = s;
        stackArray = new Tovar[size];
        top = -1;
    }

    // Деструктор
    ~Stack() {
        delete[] stackArray;
    }

    // Додавання елемента до стеку
    void push(Tovar p) {
        if (top == size - 1) {
            cout << "Стек переповнений!" << endl;
        }
        else {
            top++;
            stackArray[top] = p;
        }
    }

    // Видалення елемента зі стеку
    void pop() {
        if (top == -1) {
            cout << "Стек порожній!" << endl;
        }
        else {
            top--;
        }
    }
    
  
    //вивід в консоль
    void Print(int n)
    {
        cout << "\nName: " << stackArray[n].name << "\nType: " << stackArray[n].type << "\nSort: " << stackArray[n].sort << "\nquantity: " << stackArray[n].k << "\nCost: " << stackArray[n].cost << endl;

    }
    // Перевірка, чи є стек порожнім
    bool isEmpty() {
        return (top == -1);
    }

    // Перевірка, чи є стек переповненим
    bool isFull() {
        return (top == size - 1);
    }

    // Показати верхній елемент стеку
    Tovar topElement() {
        return stackArray[top];
    }
 
};

//видалення елемента по індексу
void deleteElement(Stack& stack, int index) {
    int n = stack.size;

    // Перевіряємо, чи індекс належить допустимому діапазону
    if (index < 0 || index >= n) {
        cout << "Недопустимий індекс" << endl;
        return;
    }

    // Видаляємо елемент за індексом
    stack.stackArray[index] = {};

    stack.pop();
}
int main()
{
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
    //для коректним виведення в консоль тільки так))
    int x = 2;
    Tovar tovar ;
    Stack TovarStack(x); 
    
    while (true)
    {
        
        cout << "1 - добавить товар\n2 - видалити товар\n3 - Огляд складу" << endl;
      char m = _getch();

        if (m == '1')
        {
            system("cls");
            take_data(tovar);
            TovarStack.push(tovar);
        }
        if (m == '2')
        {
            system("cls");
            int n = 0;
            cout << "Номер товару для видалення: " ;
            cin >> n;
            deleteElement(TovarStack, n);
        } 
        if (m == '3')
        {
            system("cls");
            for (int i = 0; i < x; i++)
            {
                TovarStack.Print(i);
            }
        }
    }

    return 0;
}