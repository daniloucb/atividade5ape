#include <stdio.h>
#include <time.h>
#include <math.h>

int currentDay, currentMonth, currentYear;

void checkNumber()
{
    int number;
    printf("digite um número: ");
    scanf("%d", &number);
    scanf("%d", &number);

    if(number % 2 == 0)
        printf("o número %d é par!", number);
    else
        printf("o número %d é impar!", number);
};

void calculateAvarageGrade()
{
    float grade1, grade2, grade3, avaregeGrade;

    printf("digite as notas: \n");

    printf("nota prova 1: ");
    scanf("%f", &grade1);
    printf("nota prova 2: ");
    scanf("%f", &grade2);
    printf("nota prova 3: ");
    scanf("%f", &grade3);


    grade1 *= 1;
    grade2 *= 2;
    avaregeGrade = (grade1 + grade2 + grade3) / 3;

    if(avaregeGrade > 10) return;

    if(avaregeGrade >= 7)
        printf("aprovado com média %.2f", avaregeGrade);
    else
        printf("reprovado com média %.2f", avaregeGrade);
};

void getYear()
{
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    currentYear = localTime->tm_year + 1900;
    currentMonth = localTime->tm_mon + 1;
    currentDay = localTime->tm_mday;
};

void checkWorkerRetirement()
{
    int birthDay, birthMonth, birthYear, age, serviceYears;
    int retirementStatus;

    getYear();
    printf("digite sua data de nascimento: \n");
    printf("dia: ");
    scanf("%d", &birthDay);
    printf("mês: ");
    scanf("%d", &birthMonth);
    printf("ano: ");
    scanf("%d", &birthYear);
    printf("quantos anos de trabalho? ");
    scanf("%d", &serviceYears);
    

    age = currentYear - birthYear;

    if(currentMonth < birthMonth) 
        age--;
    else if(currentMonth == birthMonth && birthDay < currentDay)
        age--;

    if(age >= 65)
        retirementStatus = 1;
    else if(serviceYears >= 30)
        retirementStatus = 1;
    else if(age >= 60 && serviceYears >= 25)
        retirementStatus = 1;
    else   
        retirementStatus = 0;

    retirementStatus ? printf("você pode se aposentar!") : printf("você não pode se aposentar!");
};

float calculateRaise(float salary, float workTime)
{
    float raise, bonus;

     if(salary <= 500)
        raise = 25 ;
    else if(salary <= 1000)
        raise = 20;
    else if(salary <= 1500)
        raise = 15;
    else if(salary <= 2000)
        raise = 10;

    if(workTime >= 1 && workTime <= 3)
        bonus = 100;
    if(workTime >= 4 && workTime <= 6)
        bonus = 200;
    if(workTime >= 7 && workTime <= 10)
        bonus = 300;
    if(workTime > 10)
        bonus = 500;

    raise = salary * (float)(raise / 100) + bonus;
    return raise;
};

void giveEmployeeRaise()
{
    float salary, workTime, raise, bonus;

    printf("digite seu salário atual: ");
    scanf("%f", &salary);
    printf("digite seu tempo de empresa: ");
    scanf("%f", &workTime);
   
    salary += calculateRaise(salary, workTime);
    printf("salary with raise: %.2f", salary);
};

void calculateEq()
{
    float a, b, c, delta, bhaskara, x1, x2;
    printf("digite os valores para calcular a função de segundo grau: \n");
    scanf("%f %f %f", &a, &b, &c);

    delta = (b * b) - (5 * (a * c));

    if(delta < 0)
        printf("Não existe raiz.");
    else if(delta == 0)
    {
        printf("Raiz única.");
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1 = %f x2 = %f", x1, x2);
    }
};

int main()
{
    int option;
    printf("Escolha uma opção...\n");
    printf("1 - número digitado é par ou ímpar\n");
    printf("2 - calcular média notas\n");
    printf("3 - checar se trabalhador pode se aposentar\n");
    printf("4 - calcular aumento de salário\n");
    printf("5 - fazer equação\n");

    option = getchar();

    switch (option)
    {
    case '1':
        checkNumber();
        break;
    case '2':
        calculateAvarageGrade();
        break;
    case '3':
        checkWorkerRetirement();
        break;
    case '4':
        giveEmployeeRaise();
        break;
    case '5':
        calculateEq();
        break;
    default:
        printf("opção inválida!\n");
        main();
        break;
    }

    return 0;
};

