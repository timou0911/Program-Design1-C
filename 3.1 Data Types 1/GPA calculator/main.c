#include<stdio.h>

int main () {

    int credit = 0, total = 0, ch;
    float grade = 0, grade_sum = 0;

    while ((ch = getchar()) != '\n') {
        if (ch >= 48 && ch <= 57) {
            grade_sum += grade * credit;
            credit = ch - 48;
            total += credit;
        }

        else if (ch >= 65 && ch <= 70) {
            switch (ch) {
                case 65 :
                    grade = 4.0;
                    break;
                case 66 :
                    grade = 3.0;
                    break;
                case 67 :
                    grade = 2.0;
                    break;
                case 70 :
                    grade = 0;
                    break;
                default :
                    printf("error");
            }
        }

        else if (ch == 43 || ch == 45) { // 43+ 45-
            if (ch == 43) {
                grade += 0.3;
            }
            else {
                grade -= 0.3;
            }
        }

        else {
            ;
        }
    }
    grade_sum += grade * credit;
    printf("%.2f", grade_sum / total);
    return 0;
}
