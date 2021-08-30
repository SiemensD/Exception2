#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BaseException
{
protected:

    string text;

public:

    virtual string what() = 0;
};

// класс, который соответствует арифметическим операциям
class MathsException :public BaseException
{
public:

    MathsException()
    {
        text = "Error. Maths Exception.";
    }

    // конструктор с заданным текстом
    MathsException(string _text) { text = _text; }

    // переопределяем виртуальную функцию what()
    string what() { return text; }
};

// разновидность класса ArithmeticException - деление на 0,
class DivideByZero final :public MathsException
{
public:
    // конструктор, который содержит текст описывающий данное исключение
    DivideByZero() :MathsException()
    {
        text = "Divide by zero.";
    }
    // конструктор, который получает строку текста от пользователя
    DivideByZero(string _text) :MathsException(_text)
    {
    }

    string what() { return text; }
};

// отрицательный индекс в массиве
class NegativeIndex final :public BaseException
{
public:

    NegativeIndex(string _text = "Error. Negative Index.") { text = _text; }

    string what() { return text; }
};

class OpenFile :public BaseException
{
public:
    OpenFile(string _text = "Error. File is not open") { text = _text; }

    string what() { return text; }

};


// Демонстрационная функция для класса NegativeIndex
void DemoExceptions1()
{
    int a[10];
    int index;

    for (int i = 0; i < 10; i++)
        a[i] = i * i;
    cout << "Input index: " << endl;
    cin >> index;

    // проверка индекса на отрицательное значение
    if (index < 0)
        throw NegativeIndex();
    cout << "a[" << index << "] = " << a[index] << endl;
}

// Демонстрационная функция для класса MathsException
void DemoExceptions2()
{
    int a, b, c;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    if (b == 0)
        throw DivideByZero("Divide by 0.");
    cout << "a / b = " << (double)a / b << endl;
}

// Демонстрационная функция для класса OpenFile
void DemoExceptions3()
{
    string path = "MyFile.txt";

    ifstream fin;

    fin.open(path);

    // проверка на открытие файла
    if (!fin.is_open())
        throw OpenFile("File cosd");

}

void main()
{
    try
    {

        DemoExceptions1();
        DemoExceptions2();
        DemoExceptions3();
        cout << "OK!" << endl;
    }
    catch (NegativeIndex e)
    {

        cout << e.what() << endl;
    }
    catch (DivideByZero e)
    {
        cout << e.what() << endl;
    }
    catch (OpenFile e)
    {
        cout << e.what() << endl;
    }
}



/*Задание 2.
Создайте иерархию пользовательских классов-исклю-
чений. В ней должны быть классы для разных ситуа-
ций. В качестве предметной области используйте ваши
практические и домашние задания. Например, должны
присутствовать классы для обработки всевозможных
математических ошибок, нехватки памяти, проблемам
по работе с файлами и т.д.*/