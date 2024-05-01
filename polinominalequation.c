#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

void print_centered(const char *fmt, ...) {

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int term_width = w.ws_col;
    int padding = (term_width - strlen(fmt)) / 2;

    for (int i = 0; i < padding; ++i) {
        putchar(' ');
    }

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

int main() {
    printf("\033[1m");
    printf("\033[36m");
    printf("\033[1;36m");
    print_centered("**************************************************\n");
    print_centered("*                                                *\n");
    print_centered("*          Welcome to the Coding World!          *\n");
    print_centered("*                                                *\n");
    print_centered("**************************************************\n");
    printf("\n");

    printf("\033[1;31m");
    print_centered("Presented by:\n");
    print_centered("Sadi Mahmud Sajid / Devildon\n");
    print_centered("(devil㉿kali)\n");
    print_centered("Contact Number:01890731620\n");
    print_centered("Gmail:sadimahmudsajid@gmail.com\n");
    printf("\033[0m");   
    printf("\033[0m");
    printf("\033[0m");
    printf("\n");

    print_centered("\033[1;33m        >>>C program to calculate the result of polinominalequation<<<\n");

    char choice;
    do {
        printf("\n");
        double a, b, c, discriminant, realPart, imaginaryPart;

        print_centered("\033[32m     Enter the coefficients (a, b, c) of the quadratic equation: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            realPart = (-b + sqrt(discriminant)) / (2 * a);
            imaginaryPart = (-b - sqrt(discriminant)) / (2 * a);
            print_centered("\033[32m   Distinct real roots: %.3f and %.3f\n", realPart, imaginaryPart);
        } else if (discriminant == 0) {
            realPart = -b / (2 * a);
            print_centered("\033[32m Repeated real root: %.3f\n", realPart);
        } else {
            realPart = -b / (2 * a);
            imaginaryPart = sqrt(-discriminant) / (2 * a);
            print_centered("\033[32m    Complex roots: %.3f + %.3fi and %.3f - %.3fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
        }

        printf("\n");
        print_centered("\033[1;35m       Do you want to calculate another volume? (y/n): ");
        scanf(" %c", &choice);

        printf("\n");
        while (choice != 'y' && choice != 'n') {
        print_centered("\033[1;31m       Please enter 'y' or 'n': ");
        scanf(" %c", &choice);
        }
        
        } while (choice == 'y');

    return 0;
}