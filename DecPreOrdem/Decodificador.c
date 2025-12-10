#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    unsigned char folha;
    unsigned char pixel;
    struct QNode *q1, *q2, *q3, *q4;
} QNode;

QNode* encaminharNo(FILE *f) {
    QNode *no = calloc(1, sizeof(QNode));
    if (!no) exit(1);

    fread(&no->folha, 1, 1, fp);

    if (no->folha) {
        fread(&n->pixel, 1, 1, fp);
    } else {
        n->1a = encaminharNo(f);
        n->2a = encaminharNo(f);
        n->3a = encaminharNo(f);
        n->4a = encaminharNo(f);
    }

    return no;
}

void preencher(Quad *no, unsigned char *mat, int px, int py, int w, int h, int largura) {
    if (no->folha) {
        for (int i = py; i < py + h; i++)
            for (int j = px; j < px + w; j++)
                mat[i * largura + j] = no->pixel;
        return;
    }

    int w2 = w / 2;
    int h2 = h / 2;

    preencher(no->1a, mat, px,       py,       w2,     h2,     largura);
    preencher(no->2a, mat, px+w2,    py,       w-w2,   h2,     largura);
    preencher(no->3a, mat, px,       py+h2,    w2,     h-h2,   largura);
    preencher(no->4a, mat, px+w2,    py+h2,    w-w2,   h-h2,   largura);
}

void liberar(QNode *no) {
    if (!no) return;
    if (!no->folha) {
        liberar(no->1a);
        liberar(no->2a);
        liberar(no->3a);
        liberar(no->4a);
    }
    free(no);
}

int main(int argc, char *argv[]) {

    if(argc != 3){

        printf("Utilização: %s <Entrada.dp> <Saída.pgm>\n", argv[0]);
        return 1; 
    }


    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Erro abrindo bitstream(arquivo)");
        return 1;
    }

    unsigned char assinatura[2];
    fread(assinatura, 1, 2, fp);
    if (assinatura[0] != 'D' || assinatura[1] != 'P') {
        printf("Bitstream(formato) inválido!\n");
        return 1;
    }

    short w, h;
    fread(&w, sizeof(short), 1, fp);
    fread(&h, sizeof(short), 1, fp);

    QNode *raiz = carregarNo(f);
    fclose(fp);

    unsigned char *buf = calloc(w * h, 1);

    encaminharNo(raiz, buf, 0, 0, w, h, w);

    FILE *out = fopen(argv[2], "wb");
    fprintf(out, "P5\n%d %d\n255\n", largura, altura);
    fwrite(buf, 1, w * h, out);
    fclose(out);

    free(buf);
    liberar(raiz);

    printf("Concluído, imagem reconstruída em P5.\n");

    return 0;
}

