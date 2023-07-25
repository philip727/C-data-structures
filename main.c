#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"

int main() {
    vector* vecOne = new_vec(sizeof(int));

    int notMeow[] = {1,5,53,45,3234,5,346,346};

    for (int i = 0; i < 7; i++) {
        vec_push(vecOne, &notMeow[i]);
    }

    int* int_data = (int*)vecOne->data;
    for (size_t i = 0; i < vecOne->length; i++) {
        printf("%d\n", int_data[i]);
    }

    return 0;
}
