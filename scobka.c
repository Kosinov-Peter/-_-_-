//

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
FILE *fp;

int FuctionWith(FILE *fp)
{
    char s;

    // Проверка на кол-во ковычек

    int kov = 0;
    while(!feof(fp))
    {
        s = fgetc(fp);
        if (s == '"')
        kov++;
    }
     if (kov != 0 && kov % 2 != 0)
     {
         printf("Кол-во ковычек не четное\n\n");
         return 0;
     }

    rewind(fp);
    //кол-во (), [], {}:

    int kr = 0;
    int kv = 0;
    int figur = 0;



    while(!feof(fp))
    {
        s = fgetc(fp);
        if (s == '"') // Если встречается ковычка, то идем до следующей ковычки не обращая внимания на символы
        {
            char s1 = fgetc(fp);
            while (s1 != '"')
            s1 = fgetc(fp);
        }

        if (s == '(')
        kr++;
        else
        if (s == '{')
        figur++;
        else
        if (s == '}')
        figur--;
        else
        if (s == ')')
        kr--;
        else
        if (s == '[')
        kv++;
        else
        if (s == ']')
        kv--;
    }
    if ((kv != 0) || (kr != 0) || (figur != 0))
        printf("Нехватает \n\nКвадратных = %d\nКруглых = %d\nФигурных = %d \n",abs(kv),abs(kr),abs(figur));
    else
        printf("Ошибока с кол-вом скобок нет\n");
    fclose(fp);
    return 0;
}

int FuctionWithout(FILE *fp)
{
    int kr = 0;
    int kv = 0;
    int figur = 0;
    char s;


    while(!feof(fp))
    {
        s = fgetc(fp);

        if (s == '(')
        kr++;
        else
        if (s == '{')
        figur++;
        else
        if (s == '}')
        figur--;
        else
        if (s == ')')
        kr--;
        else
        if (s == '[')
        kv++;
        else
        if (s == ']')
        kv--;
    }
    if ((kv != 0) || (kr != 0) || (figur != 0))
        printf("Нехватает \n\nКвадратных = %d\nКруглых = %d\nФигурных = %d \n",abs(kv),abs(kr),abs(figur));
    else
        printf("Ошибока с кол-вом скобок нет\n");
    fclose(fp);
    return 0;
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    printf("Введите путь к файлу для проверки кол-во скобок\n");
    char str[100];
    scanf("%s",&str);
    while ((fp = fopen(str,"rt")) == NULL)
    {
        puts("Открыть файл не удалось, введите другой путь к файлу");
        scanf("%s",&str);
    }
    char ot[10];
    printf("\n");
    printf("Учитывать ковычки (да/нет)\n");

    scanf("%s",&ot);

    while ((strcmp(ot,"да") != 0) && (strcmp(ot,"нет") != 0))
    {
    printf("Введите (да/нет)\n");
    scanf("%s",&ot);
    }

    if ((strcmp(ot,"нет") == 0))
        FuctionWithout(fp);
    else
        FuctionWith(fp);

    return 0;
}
