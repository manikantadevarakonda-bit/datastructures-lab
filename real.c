#include <stdio.h>
typedef struct {
    double real;
    double imaginary;
} Complex;
Complex add_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}
Complex multiply_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    result.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    return result;
}
void display_complex(Complex c) {
    if (c.imaginary >= 0) {
        printf("%.2f + %.2fi", c.real, c.imaginary);
    } else {
        printf("%.2f - %.2fi", c.real, -c.imaginary);
    }
}
int main() {
    Complex num1, num2, sum, product;
    printf("Enter real and imaginary parts of the first complex number:\n");
    printf("Real part: ");
    scanf("%lf", &num1.real);
    printf("Imaginary part: ");
    scanf("%lf", &num1.imaginary);
    printf("\nEnter real and imaginary parts of the second complex number:\n");
    printf("Real part: ");
    scanf("%lf", &num2.real);
    printf("Imaginary part: ");
    scanf("%lf", &num2.imaginary);
    sum = add_complex(num1, num2);
    product = multiply_complex(num1, num2);
    printf("\nFirst complex number: ");
    display_complex(num1);
    printf("\nSecond complex number: ");
    display_complex(num2);
    printf("\n\nSum = ");
    display_complex(sum);
    printf("\nProduct = ");
    display_complex(product);
    printf("\n");
    return 0;
}
