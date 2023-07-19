#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

uint32_t file_read(const char* filename) {
    FILE* file = fopen(filename, "rb");

    uint32_t number;
    fread(&number, sizeof(number), 1, file);
    fclose(file);
    return ntohl(number);
}

int main() {
    const char* filename1 = "thousand.bin";
    const char* filename2 = "five-hundred.bin";

    uint32_t number1 = file_read(filename1);
    uint32_t number2 = file_read(filename2);

    uint32_t sum = number1 + number2;
    printf("%u(0x%02x) + %u(0x%02x) = %u(0x%02x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}

