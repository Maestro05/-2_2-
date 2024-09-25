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

void First(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Блюдо";
        do
        {
            system("cls");
            printf("Главное блюдо:\n\n1.Суп\n\n2.Стейк\n\n3.Пицца\n\n4.Бурегр\n\n5.Выход\n");
            plate[index1][*index2].menu.dish.bludo = Select(1, 5, text);
            if (plate[index1][*index2].menu.dish.bludo == 1) { plate[index1][*index2].price = 360; plate[index1][*index2].calories = 200; plate[index1][*index2].weight = 330; strcpy(plate[index1][*index2].name, "Суп"); }
            else if (plate[index1][*index2].menu.dish.bludo == 2) { plate[index1][*index2].price = 1300; plate[index1][*index2].calories = 678; plate[index1][*index2].weight = 230; strcpy(plate[index1][*index2].name, "Стейк"); }
            else if (plate[index1][*index2].menu.dish.bludo == 3) { plate[index1][*index2].price = 579; plate[index1][*index2].calories = 1291; plate[index1][*index2].weight = 420; strcpy(plate[index1][*index2].name, "Пицца"); }
            else if (plate[index1][*index2].menu.dish.bludo == 4) { plate[index1][*index2].price = 620; plate[index1][*index2].calories = 1320; plate[index1][*index2].weight = 439; strcpy(plate[index1][*index2].name, "Бургер"); }
            else return;
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Second(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Закуска";
        do
        {
            system("cls");
            printf("Закуски:\n\n1.Картошка фри\n\n2.Наггетсы\n\n3.Крылашки\n\n4.Выход\n");
            plate[index1][*index2].menu.snack.zakuska = Select(1, 4, text);
            if (plate[index1][*index2].menu.snack.zakuska == 1) { plate[index1][*index2].price = 94; plate[index1][*index2].calories = 310; plate[index1][*index2].weight = 155; strcpy(plate[index1][*index2].name, "Картошка фри"); }
            else if (plate[index1][*index2].menu.snack.zakuska == 2) { plate[index1][*index2].price = 109; plate[index1][*index2].calories = 290; plate[index1][*index2].weight = 165; strcpy(plate[index1][*index2].name, "Наггетсы"); }
            else if (plate[index1][*index2].menu.snack.zakuska == 3) { plate[index1][*index2].price = 60; plate[index1][*index2].calories = 71; plate[index1][*index2].weight = 33; strcpy(plate[index1][*index2].name, "Крылашки"); }
            else return;
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Third(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Десерт";
        do
        {
            system("cls");
            printf("Десерты:\n\n1.Чизкейк\n\n2.Тирамису\n\n3.Муравейник\n\n4.Выход\n");
            plate[index1][*index2].menu.desert.sladkoe = Select(1, 4, text);
            if (plate[index1][*index2].menu.desert.sladkoe == 1) { plate[index1][*index2].price = 169; plate[index1][*index2].calories = 330; plate[index1][*index2].weight = 100; strcpy(plate[index1][*index2].name, "Чизкейк"); }
            else if (plate[index1][*index2].menu.desert.sladkoe == 2) { plate[index1][*index2].price = 219; plate[index1][*index2].calories = 420; plate[index1][*index2].weight = 140; strcpy(plate[index1][*index2].name, "Тирамису"); }
            else if (plate[index1][*index2].menu.desert.sladkoe == 3) { plate[index1][*index2].price = 150; plate[index1][*index2].calories = 380; plate[index1][*index2].weight = 100; strcpy(plate[index1][*index2].name, "Муравейник"); }
            else return;
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Fourth(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Комбо";
        do
        {
            system("cls");
            printf("Комбо:\n\n1.5 за 200\n\n2.5 за 300\n\n3.5 за 350\n\n4.Выход\n");
            plate[index1][*index2].menu.combo.x = Select(1, 4, text);
            if (plate[index1][*index2].menu.combo.x == 1) { plate[index1][*index2].price = 200; plate[index1][*index2].calories = 1000; plate[index1][*index2].weight = 500; strcpy(plate[index1][*index2].name, "5 за 200"); }
            else if (plate[index1][*index2].menu.combo.x == 2) { plate[index1][*index2].price = 300; plate[index1][*index2].calories = 1100; plate[index1][*index2].weight = 550; strcpy(plate[index1][*index2].name, "5 за 300"); }
            else if (plate[index1][*index2].menu.combo.x == 3) { plate[index1][*index2].price = 350; plate[index1][*index2].calories = 1200; plate[index1][*index2].weight = 600; strcpy(plate[index1][*index2].name, "5 за 350"); }
            else return;
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Fiveth(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Закуска";
        do
        {
            system("cls");
            printf("Закуски:\n\n1.Кола\n\n2.Спрайт\n\n3.Дюшес\n\n4.Выход\n");
            plate[index1][*index2].menu.drink.taste = Select(1, 4, text);
            if (plate[index1][*index2].menu.drink.taste != 4) { plate[index1][*index2].price = 90; plate[index1][*index2].calories = 220; plate[index1][*index2].weight = 500; }
            else return;
            if (plate[index1][*index2].menu.drink.taste == 1) { strcpy(plate[index1][*index2].name, "Кола"); }
            else if (plate[index1][*index2].menu.drink.taste == 2) { strcpy(plate[index1][*index2].name, "Спрайт"); }
            else { strcpy(plate[index1][*index2].name, "Дюшес"); }
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Sixth(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Милкшейк";
        do
        {
            system("cls");
            printf("Милкшейки:\n\n1.Шоколадный\n\n2.Ванильный\n\n3.Клубничный\n\n4.Выход\n");
            plate[index1][*index2].menu.milkshake.taste = Select(1, 4, text);
            if (plate[index1][*index2].menu.milkshake.taste != 4) { plate[index1][*index2].price = 120; plate[index1][*index2].calories = 380; plate[index1][*index2].weight = 500; }
            else return;
            if (plate[index1][*index2].menu.milkshake.taste == 1) { strcpy(plate[index1][*index2].name, "Шоколадный милкшейк"); }
            else if (plate[index1][*index2].menu.milkshake.taste == 2) { strcpy(plate[index1][*index2].name, "Ванильный милкшейк"); }
            else { strcpy(plate[index1][*index2].name, "Клубничный милкшейк"); }
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }
}

void Seventh(int index1, int* index2)
{
    if ((*index2) < 7)
    {
        char text[] = "Соус";
        do
        {
            system("cls");
            printf("Соусы:\n\n1.Кетчуп\n\n2.Сырный\n\n3.Барбекю\n\n4.Выход\n");
            plate[index1][*index2].menu.sous.taste = Select(1, 4, text);
            if (plate[index1][*index2].menu.sous.taste != 4) { plate[index1][*index2].price = 59; plate[index1][*index2].calories = 110; plate[index1][*index2].weight = 25; }
            else return;
            if (plate[index1][*index2].menu.sous.taste == 1) { strcpy(plate[index1][*index2].name, "Соус Кетчуп"); }
            else if (plate[index1][*index2].menu.sous.taste == 2) { strcpy(plate[index1][*index2].name, "Cырный соус"); }
            else { strcpy(plate[index1][*index2].name, "Барбекю соус"); }
            Information(index1, index2);
        } while (1);
    }
    else { printf("\nЗаказ переполнен!\n"); return; }

}


int main()
{
    setlocale(LC_ALL, "rus");
    int index1 = 0;
    char exit;

}



