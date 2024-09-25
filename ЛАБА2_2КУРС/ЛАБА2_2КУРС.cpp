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

void Information(int index1, int* index2)
{
    system("cls");
    char text[] = "Выбор действия";
    char text2[] = "Количество";
    printf("Информация о заказе %s:\n", plate[index1][*index2].name);
    printf("Калорий: %d\nВес: %.1lf г\nЦена: %d", plate[index1][*index2].calories, plate[index1][*index2].weight, plate[index1][*index2].price);
    printf("\n----------------------\n");
    printf("1.Заказать\n\n2.Назад\n");
    int choice = Select(1, 2, text);
    if (choice == 1)
    {
        printf("\n");
        plate[index1][*index2].kol = Select(1, 100, text2);
        (*index2)++;
    }
    else return;
}

void Korzinka(int* index1, int index2)
{
    system("cls");
    char exit;
    if (plate[*index1 - 1][0].kol != 0)
    {
        int allprice = 0;
        printf("Корзинка Чек №%d:\n\n", *index1);
        for (int i = 0; i < index2; i++)
        {
            printf("%-39s %-3d шт. x %-20d\n", plate[*index1 - 1][i].name, plate[*index1 - 1][i].kol, plate[*index1 - 1][i].price);
            allprice += plate[*index1 - 1][i].price * plate[*index1 - 1][i].kol;
        }
        printf("----------------------\nОбщая сумма покупи: %d\n\n", allprice);
        do
        {
            printf("Нажмите на q, чтобы вернуться в меню\n");
        } while ((exit = _getch()) != 'q');
    }
    else
    {
        (*index1)--;
        printf("В корзинке пусто!\n\n");
        do
        {
            printf("Нажмите на q, чтобы вернуться в меню\n");
        } while ((exit = _getch()) != 'q');
        return;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    int index1 = 0;
    char exit;

}



