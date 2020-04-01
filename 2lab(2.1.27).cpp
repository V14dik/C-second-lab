#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


void infmat()
{
    int *i = 0;
    system("cls");
    printf("Цемент-$230 за тонну\n");
    printf("Гравий-$142 за тонну\n");
    printf("Бетон-$260 за тонну\n");
    printf("Нажмите любую клавишу для выхода в меню\n");
    _getch();
    return;
}


void info()
{
    int *i = 0;
    system("cls");
    printf("Программу составил Черенкевич В.А.\n");
    printf("Версия программы №1\n");
    printf("Нажмите любую клавишу для выхода в меню\n");
    _getch();
    return;
}


int kol (int wheaght)
{
    int  vag = 0;
    if ((wheaght % 50) > 0)
        vag = (wheaght / 50) + 1;
    else vag = wheaght / 50;
    return vag;
}


int country()
{
    system("cls");
    int choice = 0;
    printf("Выберете страну доставки\n");
    printf("1.Беларусь\n");
    printf("2.Россия\n");
    printf("3.Украина\n");
    printf("4.Молдавия\n");
    if (scanf_s("%i", &choice) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод\n");
    }
    else 
        while ((choice < 1) and (choice > 4))
        {
            rewind(stdin);
            printf("Оформить заказ можно только в предложенные страны\n");
            scanf_s("%i", &choice);
        }
    return choice;
}

int coastcountry(int ordercountry)
{
    switch (ordercountry)
    {
    case 1: return 200;
    case 2: return 320;
    case 3: return 320;
    case 4: return 360;
    }
}
int cem()
{
    system("cls");
    int material = 0, sumord = 0, realsum = 0, resh = 0, wheaght = 0, ordercountry = 0, raz = 0;
    printf("Введите количество цемента в тоннах\n");
    if (scanf_s("%i", &wheaght) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод");
    }
    sumord += wheaght * 230;
    realsum += wheaght * 160;
    ordercountry = country();
    sumord += kol(wheaght) * coastcountry(ordercountry);
    realsum += kol(wheaght) * coastcountry(ordercountry);
    raz = sumord - realsum;
    if (raz >= 25000)
    {
        system("cls");
        printf("Общая стоимость заказа с учётом доставки составила:$%i\n", sumord);
        printf("Прибыль предприятия:$%i\n", raz);
    }
    else
    {
        system("cls");
        printf("Заказ не принят");
    }
    return 0;
}

int grav()
{
    system("cls");
    int material = 0, sumord = 0, realsum = 0, resh = 0, wheaght = 0, ordercountry = 0, raz = 0;
    printf("Введите количество гравия в тоннах\n");
    if (scanf_s("%i", &wheaght) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод");
    }
    sumord += wheaght * 142;
    realsum += wheaght * 96;
    ordercountry = country();
    sumord += kol(wheaght) * coastcountry(ordercountry);
    realsum += kol(wheaght) * coastcountry(ordercountry);
    if (raz >= 25000)
    {
        system("cls");
        printf("Общая стоимость заказа с учётом доставки составила:$%i\n", sumord);
        printf("Прибыль предприятия:$%i\n", raz);
    }
    else
    {
        system("cls");
        printf("Заказ не принят");
    }
    return 0;
}

int bet()
{
    int material = 0, sumord = 0, realsum = 0, resh = 0, wheaght = 0, ordercountry = 0, raz = 0;
    system("cls");
    printf("Введите количество бетона в тоннах\n");
    if (scanf_s("%i", &wheaght) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод");
    }
    sumord += wheaght * 260;
    realsum += wheaght * 205;
    ordercountry = country();
    sumord += kol(wheaght) * coastcountry(ordercountry);
    realsum += kol(wheaght) * coastcountry(ordercountry);
    if (raz >= 25000)
    {
        system("cls");
        printf("Общая стоимость заказа с учётом доставки составила:$%i\n", sumord);
        printf("Прибыль предприятия:$%i\n", raz);
    }
    else
    {
        system("cls");
        printf("Заказ не принят");
    }
    return 0;
}

int menu()
{
    m:
    printf("1.Заказ на цемент\n");
    printf("2.Заказ на гравий\n");
    printf("3.Заказ на бетон\n");
    printf("4.Информация о материалах\n");
    printf("5.Информация о пограмме\n");
    printf("6.Выход из программы\n");
    int material = 0, raz = 0;
    if (scanf_s("%i", &material) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод\n");
    }
    while ((material < 1) or (material > 6))
    {
        rewind(stdin);
        printf("Неверный ввод(введите заново)\n");
        scanf_s("%i", &material);
    }
    switch (material)
    {
    case 1: cem(); break;
    case 2: grav(); break;
    case 3: bet(); break;
    case 4:
    {
        infmat();
        system("cls");
        goto m;
    }
    case 5:
    {
        info();
        system("cls");
        goto m;
    }
    case 6: return 0;
    }
    return 0;

}


int main()
{
    int raz=0;
    system("chcp 1251");
    system("cls");
    menu();
    return 0;

}