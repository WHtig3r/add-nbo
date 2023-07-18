#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main() {
    uint32_t value1;
    uint32_t value2;
    uint32_t sum;
    FILE *fp1, *fp2;

    fp1 = fopen("five-hundred.bin", "rb");
    fp2 = fopen("thousand.bin", "rb");

    fread(&value1, sizeof(value1), 1, fp1);
    fread(&value2, sizeof(value2), 1, fp2);

    value1 = ntohl(value1);
    value2 = ntohl(value2);
    sum = value1 + value2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value1, value1, value2, value2, sum, sum);

    fclose(fp1);
    fclose(fp2);

    return 0;
}

