//

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
FILE *fp;

int FuctionWith(FILE *fp)
{
    char s;

    // �������� �� ���-�� �������

    int kov = 0;
    while(!feof(fp))
    {
        s = fgetc(fp);
        if (s == '"')
        kov++;
    }
     if (kov != 0 && kov % 2 != 0)
     {
         printf("���-�� ������� �� ������\n\n");
         return 0;
     }

    rewind(fp);
    //���-�� (), [], {}:

    int kr = 0;
    int kv = 0;
    int figur = 0;



    while(!feof(fp))
    {
        s = fgetc(fp);
        if (s == '"') // ���� ����������� �������, �� ���� �� ��������� ������� �� ������� �������� �� �������
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
        printf("��������� \n\n���������� = %d\n������� = %d\n�������� = %d \n",abs(kv),abs(kr),abs(figur));
    else
        printf("������� � ���-��� ������ ���\n");
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
        printf("��������� \n\n���������� = %d\n������� = %d\n�������� = %d \n",abs(kv),abs(kr),abs(figur));
    else
        printf("������� � ���-��� ������ ���\n");
    fclose(fp);
    return 0;
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    printf("������� ���� � ����� ��� �������� ���-�� ������\n");
    char str[100];
    scanf("%s",&str);
    while ((fp = fopen(str,"rt")) == NULL)
    {
        puts("������� ���� �� �������, ������� ������ ���� � �����");
        scanf("%s",&str);
    }
    char ot[10];
    printf("\n");
    printf("��������� ������� (��/���)\n");

    scanf("%s",&ot);

    while ((strcmp(ot,"��") != 0) && (strcmp(ot,"���") != 0))
    {
    printf("������� (��/���)\n");
    scanf("%s",&ot);
    }

    if ((strcmp(ot,"���") == 0))
        FuctionWithout(fp);
    else
        FuctionWith(fp);

    return 0;
}
