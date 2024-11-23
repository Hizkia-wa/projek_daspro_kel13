#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NIM 21
#define MAX_BINARY 64
#define MAX_POLY 256

int main()
{
    FILE *input_file, *output_file;
    char nim[MAX_NIM];
    char binary[MAX_BINARY];
    char polynomial[MAX_POLY];
    char primitive_polynomial[MAX_BINARY];
    char crc_result[MAX_BINARY];

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w+");

    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening files!\n");
        return 1;
    }

    fprintf(output_file, "=== HASIL SIMULASI CRC ===\n\n");

    while (fgets(nim, MAX_NIM, input_file))
    {
        nim[strcspn(nim, "\n")] = 0;

        nimToBinary(nim, binary);
        selectPrimitivePolynomial(strlen(binary), primitive_polynomial);
        binaryToPolynomial(binary, polynomial);
        calculateCRC(binary, primitive_polynomial, crc_result);

        fprintf(output_file, "NIM: %s\n", nim);
        fprintf(output_file, "Binary: %s\n", binary);
        fprintf(output_file, "Polynomial: %s\n", polynomial);
        fprintf(output_file, "Primitive Polynomial (binary): %s\n", primitive_polynomial);

        char poly_str[MAX_POLY];
        binaryToPolynomial(primitive_polynomial, poly_str);
        fprintf(output_file, "Primitive Polynomial: %s\n", poly_str);
        fprintf(output_file, "CRC Result: %s\n", crc_result);

        char verification_data[MAX_BINARY * 2];
        strcpy(verification_data, binary);
        strcat(verification_data, crc_result);
        char verify_result[MAX_BINARY];
        calculateCRC(verification_data, primitive_polynomial, verify_result);

        int is_valid = 1;
        for (int i = 0; verify_result[i] != '\0'; i++)
        {
            if (verify_result[i] != '0')
            {
                is_valid = 0;
                break;
            }
        }

        fprintf(output_file, "Verification: %s\n", is_valid ? "Valid" : "Invalid");
        fprintf(output_file, "\n-------------------\n\n");
    }

    fclose(input_file);
    fclose(output_file);
    printf("Program selesai! Silakan cek file output.txt\n");

    return 0;
}