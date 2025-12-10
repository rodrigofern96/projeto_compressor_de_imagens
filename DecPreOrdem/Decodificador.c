#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    unsigned char eh_folha;
    unsigned char cor;
    struct Node *q1, *q2, *q3, *q4;
} Node;

Node* readNode(FILE *f) {
    Node *n = calloc(1, sizeof(Node));
    if (!n){
        exit(1);
    }

    fread(&n->eh_folha, 1, 1, f);

    if (n->eh_folha) {
        fread(&n->cor, 1, 1, f);
    } else {
        n->q1 = readNode(f);
        n->q2 = readNode(f);
        n->q3 = readNode(f);
        n->q4 = readNode(f);
    }

    return n;
}

void fillImage(Node *n, unsigned char *img, int x, int y, int w, int h, int W){
    if (n->eh_folha) {
        for (int i = y; i < y + h; i++)
            for (int j = x; j < x + w; j++)
                img[i * W + j] = n->cor;
        return;
    }

    int mw = w / 2;
    int mh = h / 2;

    fillImage(n->q1, img, x,       y,       mw,     mh,     W);
    fillImage(n->q2, img, x+mw,    y,       w-mw,   mh,     W);
    fillImage(n->q3, img, x,       y+mh,    mw,     h-mh,   W);
    fillImage(n->q4, img, x+mw,    y+mh,    w-mw,   h-mh,   W);
}

void freeTree(Node *n) {
    if (!n) return;
    if (!n->eh_folha) {
        freeTree(n->q1);
        freeTree(n->q2);
        freeTree(n->q3);
        freeTree(n->q4);
    }
    free(n);
}

int main(int argc, char *argv[]) {

    if(argc != 3){

        printf("Formato:\n\t%s <bistreamEntrada.dp> <PGMNomeSaida.pgm>\n", argv[0]);
        exit(1);
        
    }


    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("Erro abrindo bitstream");
        return 1;
    }

    unsigned char tag[2];
    fread(tag, 1, 2, f);
    if (tag[0] != 'D' || tag[1] != 'P') {
        printf("Bitstream inválido!\n");
        return 1;
    }

    short largura, altura;
    fread(&largura, sizeof(short), 1, f);
    fread(&altura, sizeof(short), 1, f);

    Node *root = readNode(f);
    fclose(f);

    unsigned char *img = calloc(largura * altura, 1);

    fillImage(root, img, 0, 0, largura, altura, largura);

    FILE *out = fopen(argv[2], "wb");
    fprintf(out, "P5\n%d %d\n255\n", largura, altura);
    fwrite(img, 1, largura * altura, out);
    fclose(out);

    free(img);
    freeTree(root);

    printf("Concluído, imagem reconstruída em P5.\n");

    return 0;
}
