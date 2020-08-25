//
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
FILE* f1;
FILE* f2;

int Shifrovka(FILE* f1, FILE* f2, int key)  // функция Шифрования
{
    char s = getc(f1);

            key = key % 26;
            while (!feof(f1))
            {
                if (s >= 'a' && s <= 'z')
                {

                    if (s + key <= 'z')
                    {
                        s = s + key;
                        fprintf(f2,"%c",s);
                    } else
                    {
                        s = s - (26 - key);
                        fprintf(f2,"%c",s);
                    }

                } else if (s >= 'A' && s <= 'Z')

                {

                    if (s + key <= 'Z')
                    {
                        s = s + key;
                        fprintf(f2,"%c",s);
                    } else
                    {
                        s = s - (26 - key);
                        fprintf(f2,"%c",s);
                    }
                }
                else fprintf(f2,"%c",s);

            s = getc(f1);
            }

            fclose(f1);
            fclose(f2);
            return 0;
}


int RasShifrovka(FILE* f1, FILE* f2, int key) // функция Расшифрования
{
    char s = getc(f1);

            key = key % 26;
            while (!feof(f1))
            {
                if (s >= 'a' && s <= 'z')
                {

                    if (s - key >= 'a')
                    {
                        s = s - key;
                        fprintf(f2,"%c",s);
                    } else
                    {
                        s = s + (26 - key);
                        fprintf(f2,"%c",s);
                    }

                } else if (s >= 'A' && s <= 'Z')

                {

                    if (s - key >= 'A')
                    {
                        s = s - key;
                        fprintf(f2,"%c",s);
                    } else
                    {
                        s = s + (26 - key);
                        fprintf(f2,"%c",s);
                    }

                }
                else fprintf(f2,"%c",s);

            s = getc(f1);

            }

            fclose(f1);
            fclose(f2);
            return 0;
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    if (argc == 2 )
    {
        if (strcmp(argv[1],"-help") == 0)
        {
            printf("Создать консольную программу Caesar.exe, которая осуществляет шифровку и \n");

            printf("расшифровку текстового файла шифром Цезаря. Результаты шифровки-\n");

            printf("расшифровки должны сохраняться в отдельном файле. Шифруются только\n");
            printf("символы латинского алфавита.\n");

            printf("Если используется смещение 4, тогда А заменяется на E, B на C и т.д.\n\n");

            printf("Параметры командной строки:\n\n");

            printf("Шифровка файла        Caesar.exe -encode 4 input.txt encoded.txt\n");

            printf("Расшифровка           Caesar.exe -decode 4 encoded.txt decoded.txt\n");
            printf("Вывод помощи на экран Caesar.exe –help\n");
        }

        else
        printf("Введите '-help'\n");
    }
    else if (argc != 5)
         printf("Неправильный ввод");

    else if (strcmp(argv[1],"-decode") == 0)       // Если мы расшифровываем файл
         {
            f1 = fopen(argv[3],"rt");
            if (f1 == NULL)
            {
                printf("Не удалось открыть файл\n");
                return 0;
            }
            f2 = fopen(argv[4],"wt");
            if (f2 == NULL)
            {
                printf("Не удалось открыть файл\n");
                return 0;
            }

            int key = atoi(argv[2]);
            if (key <= 0)
            {
                printf("Неправильный ввод ключа\nВведите ключ больше нуля\n ");
                return 0;
            }

            RasShifrovka(f1,f2,key);


         }
         else if (strcmp(argv[1],"-encode") == 0)  // Если мы зашифровываем файл
         {
            f1 = fopen(argv[3],"rt");
            if (f1 == NULL)
            {
                printf("Не удалось открыть файл\n");
                return 0;
            }

            f2 = fopen(argv[4],"wt");
            if (f2 == NULL)
            {
                printf("Не удалось открыть файл\n");
                return 0;
            }

            int key = atoi(argv[2]);
            if (key <= 0)
            {
                printf("Неправильный ввод ключа\nВведите ключ больше нуля\n ");
                return 0;
            }

            Shifrovka(f1,f2,key);
         }
         else printf("Неправильный ввод (-encode/-decode) \n ");



    return 0;
}
