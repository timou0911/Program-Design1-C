#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
                    int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
    int a_numerator, a_denominator, b_numerator, b_denominator;
    scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
    int c_numerator, c_denominator;
    fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
                   &c_denominator);
    printf("%d/%d\n", c_numerator, c_denominator);
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {

    int denominator = a_denominator * b_denominator;
    int numerator = a_numerator * b_denominator + a_denominator * b_numerator;

    int min = denominator < numerator ? denominator : numerator;

    for (int i = min ; i > 0 ; i--) {
        if (denominator % i == 0 && numerator % i == 0) {
            denominator /= i;
            numerator /= i;
        }
    }

    *c_denominator_ptr = denominator;
    *c_numerator_ptr = numerator;

    return;
}