#include <stdio.h>
#include "ft_printf.h"  // Certifique-se de que o header correto está incluído

void test_null_pointers_in_printf() {
    printf("Esperado: \" 0x0 0x0 \"\n");
    int resultado = ft_printf(" %p %p ", 0, 0);
    printf("\nSaída real: \"%d\" (tamanho retornado)\n", resultado);
}

int main() {
    test_null_pointers_in_printf();
    return 0;
}
