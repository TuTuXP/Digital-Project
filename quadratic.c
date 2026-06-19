#include <stdio.h>
#include <math.h>

// Function to solve the quadratic equation ax^2 + bx + c = 0
void solveQuadratic(double a, double b, double c) {
    // Edge case: If 'a' is 0, it's a linear equation, not quadratic
    if (a == 0) {
        printf("Error: 'a' cannot be 0 in a quadratic equation.\n");
        return;
    }

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    // Case 1: Discriminant is positive (Two distinct real roots)
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        
        printf("The roots are real and distinct:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } 
    // Case 2: Discriminant is zero (Two equal real roots)
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        
        printf("The roots are real and equal:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } 
    // Case 3: Discriminant is negative (Two complex roots)
    else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        
        printf("The roots are complex and distinct:\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }
}

int main() {
    double a, b, c;

    // Ask the user for inputs
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("\nSolving equation: %.2lfx^2 + %.2lfx + %.2lf = 0\n", a, b, c);
    printf("-------------------------------------------------\n");
    
    // Call the function
    solveQuadratic(a, b, c);

    return 0;
}

