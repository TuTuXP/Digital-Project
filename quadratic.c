#include <stdio.h>
#include <math.h>
#include <string.h> // Needed for string comparison (strcmp)

void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        printf("\nError: 'a' cannot be 0 in a quadratic equation.\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        
        printf("The roots are real and distinct:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } 
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        
        printf("The roots are real and equal:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } 
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
    int inputsRead;
    char input[100]; // Create a text buffer to hold up to 100 characters

    while (1) {
        printf("Enter coefficients a, b, and c (e.g., 1 -5 6): ");
        
        // 1. Read the entire line of input as text
        fgets(input, sizeof(input), stdin);

        // Remove the 'Enter' key (\n) from the end of the text
        input[strcspn(input, "\n")] = 0;

        // 2. EASTER EGG CHECK: Did they type "i love you"?
        if (strcmp(input, "i love you") == 0 || strcmp(input, "I love you") == 0) {
            printf("\n[ERROR] Aww, I appreciate it! But I am just a math program. Please give me numbers!\n\n");
            continue; // Skip the rest of the loop and ask again
        }

        // 3. If it wasn't the secret phrase, try to extract 3 numbers from the text
        inputsRead = sscanf(input, "%lf %lf %lf", &a, &b, &c);

        if (inputsRead == 3) {
            break; // Success! We got 3 numbers, escape the loop.
        } 
        
        // 4. Standard error for any other invalid text
        printf("\n[ERROR] Invalid input detected! Please enter numbers only.\n\n");
    }

    printf("\nSolving equation: %.2lfx^2 + %.2lfx + %.2lf = 0\n", a, b, c);
    printf("-------------------------------------------------\n");
    
    solveQuadratic(a, b, c);

    return 0;
}