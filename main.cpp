/*
* Шахниязов Ботир. Группа: м8о-201Б.
* 
* Создать класс Modulo для работы с целыми числами по модулю N.
* В классе должно быть два поля: число и N.
* Реализовать все арифметические операции. Реализовать операции сравнения.
* Операции сложения, вычитания, умножения,
* деления, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
* Необходимо реализовать пользовательский литерал для работы с константами типа Modulo.
*/
#include <iostream>

class Modulo
{
private:
    int number;
    int N;
public:
    Modulo(int _number, int _N)
    {
        number = _number;
        N = _N;
    }

    Modulo(int _number)
    {
        number = _number;
        N = 1;
    }

    Modulo()
    {
        number = 0;
        N = 1;
    }
    
    Modulo operator +(Modulo b)
    {
        Modulo c(0,N);
        if (N == b.N)
            c.number = (number + b.number) % N;
        else{
            c.number = 0;
            c.N = 1;
            std::cout << "Модули не равны, операция" << " + " << "не корректна\n"; 
        }
        return c;
    }

    Modulo operator -(Modulo b)
    {
        Modulo c(0,N);
        if (N == b.N)
            c.number = (number - b.number) % N;
        else{
            c.number = 0;
            c.N = 1;
            std::cout << "Модули не равны, операция" << " - " << "не корректна\n"; 
        }
        return c;
    }

    Modulo operator *(Modulo b)
    {
        Modulo c(0,N);
        if (N == b.N)
            c.number = (number * b.number) % N;
        else{
            c.number = 0;
            c.N = 1;
            std::cout << "Модули не равны, операция" << " * " << "не корректна\n"; 
        }
        return c;
    }

    Modulo operator /(Modulo b)
    {
        Modulo c(0,N);
        if (N == b.N && b.number != 0)
            c.number = (number / b.number) % N;
        else{
            c.number = 0;
            c.N = 1;
            std::cout << "Модули не равны, операция" << " / " << "не корректна\n"; 
            std::cout << "Или делитель равен нулю\n";
        }
        return c;
    }
    
    int operator ==(Modulo b)
    {
        Modulo c;
        if(number % N == b.number % b.N)
            return 1;
        else
            return 0;
    }

    int operator >(Modulo b)
    {
        Modulo c;
        if(number % N > b.number % b.N)
            return 1;
        else
            return 0;
    }

    int operator <(Modulo b)
    {
        Modulo c;
        if(number % N < b.number % b.N)
            return 1;
        else
            return 0;
    }

    const void print_modula() const
    {
        std::cout << number << " % " << N << " = " << number % N << std::endl;
    }

    void set(int _number, int _N)
    {
        number = _number;
        N = _N;
    }
};

Modulo operator "" _num(unsigned long long b)
{     
    return b;
}

int main()
{
    std::cout << "\n\nWelcome to the modula calculator!\n";
    std::cout << "A,B - variable\n";
    std::cout << "C - result\n";
    std::cout << "A = A.num % A.mod\n\n";

    Modulo a, b, c;
    int k=1, num, mod;
    bool loop = true;

    while(loop)
    {
        switch (k)
        {
        case 1: 
            std::cout << "Menu\n";
            std::cout << "0. quit\n";
            std::cout << "1. print menu\n";
            std::cout << "2. input A\n";
            std::cout << "3. input B\n";
            std::cout << "4. C = A + B\n";
            std::cout << "5. C = A - B\n";
            std::cout << "6. C = A * B\n";
            std::cout << "7. C = A / B\n";
            std::cout << "8. C = A == B\n";
            std::cout << "9. C = A > B\n";
            std::cout << "10. C = A < B\n";
            break;
        case 2:
                std::cout << "A = "; std::cin >> num;
                std::cout << "mod = "; std::cin >> mod;
                if(mod > 0)
                    a.set(num,mod);
                else
                    std::cout << "остаток от деления должен быть больше нуля.\n";
                break;
        case 3: 
                std::cout << "B = "; std::cin >> num;
                std::cout << "mod = "; std::cin >> mod;
                if(mod > 0)
                    b.set(num,mod);
                else
                    std::cout << "остаток от деления должен быть больше нуля.\n";
                break;
        case 4: c = a + b; break;
        case 5: c = a - b; break;
        case 6: c = a * b; break;
        case 7: c = a / b; break;
        case 8: c.set(a == b,2); break;
        case 9: c.set(a > b,2); break;
        case 10: c.set(a < b,2); break;
        default: break;
        }
        std::cout << "\nЗначения:" << std::endl;
        std::cout << "A = "; a.print_modula();
        std::cout << "B = "; b.print_modula();
        std::cout << "C = "; c.print_modula();
        std::cout << " \n-->";
        std::cin >> k;
        if(!k) loop = false;
    }
    return 0;
}