// ЛАБА2_2КУРС.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

struct Plates
{
    int price;
    int calories;
    int kol = 0;
    double weight;
    char name[40]{};

    union
    {
        struct
        {
            int bludo; // 1 - суп, 2 - стейк, 3 - пицца, 4 - бургер
        }dish;

        struct
        {
            int zakuska; // 1 - картошка фри, 2 - наггетсы, 3 - крылашки
        }snack;

        struct
        {
            int sladkoe; // 1 - чизкейк, 2 - тирамису, 3 - муравейник
        }desert;

        struct
        {
            int x; // 1 - 5 за 200, 2 - 5 за 300, 3 - 5 за 350
        }combo;

        struct
        {
            int taste; //  1 - кола, 2 - спрайт, 3 - дюшес
        }drink;

        struct
        {
            int taste; //  1 - шоколадный, 2 - ванильный, 3 - клубничный
        }milkshake;

        struct
        {
            int taste; // 1 - кетчуп, 2 - сырный, 3 - барбекю
        }sous;
    }menu;

}plate[5][7];

int Select(int a, int b, char text[])
{
    int selection;
    do
    {
        printf("\n%s: ", text);
        scanf("%d", &selection);
    } while (selection < a || selection > b);

    return selection;
}



int main()
{
    setlocale(LC_ALL, "rus");
    int index1 = 0;
    char exit;

}



