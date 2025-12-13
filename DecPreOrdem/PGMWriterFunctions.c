#include "PGMWriterFunctions.h"
#include <stdlib.h>

static void preencher(
    QTree *n,
    unsigned char *img,
    int x, int y,
    int w, int h,
    int larguraTotal
) {
    if (n->folha) {
        for (int i = y; i < y + h; i++)
            for (int j = x; j < x + w; j++)
                img[i * larguraTotal + j] = n->valor;
        return;
    }

    int hw = w / 2;
    int hh = h / 2;

    preencher(n->q1, img, x,         y,         hw,        hh,        larguraTotal);
    preencher(n->q2, img, x + hw,    y,         w - hw,    hh,        larguraTotal);
    preencher(n->q3, img, x,         y + hh,    hw,        h - hh,    larguraTotal);
    preencher(n->q4, img, x + hw,    y + hh,    w - hw,    h - hh,    larguraTotal);
}

void escreverPGM(QTree *tree, FILE *f, int larg, int alt) {

    unsigned char *img = calloc(larg * alt, 1);

    preencher(tree, img, 0, 0, larg, alt, larg);

    fprintf(f, "P5\n%d %d\n255\n", larg, alt);
    fwrite(img, 1, larg * alt, f);

    free(img);
}
