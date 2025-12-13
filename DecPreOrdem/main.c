#include "DecoderFunctions.h"
#include "PGMWriterFunctions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Uso: %s <entrada.dp> <saida.pgm>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) return 2;

    FILE *out = fopen(argv[2], "wb");
    if (!out) return 3;

    unsigned char magic[2];
    fread(magic, 1, 2, in);

    if (magic[0] != 'D' || magic[1] != 'P') {
        printf("Formato inválido\n");
        return 4;
    }

    short larg, alt;
    fread(&larg, sizeof(short), 1, in);
    fread(&alt, sizeof(short), 1, in);

    QTree *tree = reconstruirQTree(in);

    escreverPGM(tree, out, larg, alt);

    liberarQTree(tree);

    fclose(in);
    fclose(out);

    return 0;
}
