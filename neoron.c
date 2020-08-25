//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <double> vec_weigth; // массив весов

class Neuron
{
private:
    double y; // Выходной сигнал

public:
    Neuron()
    {
        this->y = 0;
    }

    Neuron( int kol1, double(*func)(double) ) //основной конструктор
    {
        double x; // один из входов
        double h_ = 0; // сумма взвешанных входов

        // Нужно узнать - h
        for (int i = 0; i < kol1; i++)
        {
        cout << "Введите " << i+1 <<"-ый(ой) входной сигнал: x = ";
        cin >> x;
        h_ += x * vec_weigth[i];
        cout << endl;
    }

    y = func(h_);
    cout <<"Выходной сигнал (sigmoida) = " << y << endl;

    }
    double GetY()
    {
        return this->y;
    }

    Neuron (const Neuron &other) // конструктор копирования
    {
        this->y = other.y;
    }

    Neuron operator=(Neuron &other); // перегрузка оператора "="
};

Neuron Neuron::operator=(Neuron &other)
{
    this->y = other.y;
    return *this;
}

// функция активации "СИГМОИДА"
double Func_Act(double h1)
{
    return ( 1 / (1 + pow(M_E, -h1) ) );
}

int main()
{
    // глобальный вектор весов
    vec_weigth = {0.23, 0.34, 0.56, 0.12, 0.29, 0.89, 0.03, 0.93};

    setlocale(0,"");

    Neuron f1(6,Func_Act);

    return 0;
}
