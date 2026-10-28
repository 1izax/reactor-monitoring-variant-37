#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double read_X()
{
    double x;
    printf("Введите температуру X (от 20 до 160 °C): ");
    scanf("%lf", &x);
    return x;
}

double calc_Q(double X)
{
    double Q;
    if (X < 60.0)
    {
        Q = 2.0 * (X - 60.0) + 5.0;
    }
    else if (X >= 60.0 && X <= 100.0)
    {
        Q = 0.5 * (X - 80.0) * (X - 80.0) + 45.0;
    }
    else
    {
        Q = 2.0 * log(X - 100.0 + 2.0) + 60.0;
    }
    return Q;
}

void check_control(double Q)
{
    double Q0 = 45.00;
    double q_min8 = Q0 * 0.92;
    double q_max8 = Q0 * 1.08;
    double q_min15 = Q0 * 0.85;
    double q_max15 = Q0 * 1.15;

    printf("Оперативный контроль:\n");
    printf("Допустимый диапазон (8%%): [%.2f ; %.2f]\n", q_min8, q_max8);
    printf("Текущее состояние системы : ");

    if (Q >= q_min8 && Q <= q_max8)
    {
        printf("НОРМА\n");
    }
    else if (Q >= q_min15 && Q <= q_max15)
    {
        printf("ПРЕДУПРЕЖДЕНИЕ\n");
    }
    else
    {
        printf("ТРЕВОГА\n");
    }
}

void calculate_statistics(const double q[], int n)
{
    (void)q;
    (void)n;
    printf("Статистический анализ (Q[11..34]):\n");
    printf("-\n");
}

int main()
{
    setlocale(LC_CTYPE, "RUS");

    printf("=============================================================\n");
    printf("                 МОНИТОРИНГ РЕАКТОРА\n");
    printf("            (Температура теплоносителя, вар. 37)\n");
    printf("=============================================================\n");
    double X = read_X();
    printf("-------------------------------------------------------------\n");

    if (X < 20.0 || X > 160.0)
    {
        printf("ОШИБКА ВВОДА! Температура должна быть от 20 до 160 °C.\n");
    }
    else
    {
        double Q = calc_Q(X);

        printf("Исходные данные:\n");
        printf("Температура теплоносителя X = %.2f °C\n", X);
        printf("-------------------------------------------------------------\n");
        printf("Результаты расчета:\n");
        printf("Значение показателя Q       = %.2f\n", Q);
        printf("-------------------------------------------------------------\n");
        check_control(Q);
    }
    printf("=============================================================\n");
    double q_array[50] = { 0 };
    calculate_statistics(q_array, 50);
    printf("=============================================================\n");
    return 0;
}