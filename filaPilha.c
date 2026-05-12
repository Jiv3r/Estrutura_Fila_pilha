#include stdio.h

#define MAX 10

int pilha[MAX];
int fila[MAX];
int topo = -1;
int frente = 0, tras = 0;

void inserir_pilha() {
    if (topo  MAX - 1) {
        int num;
        printf(Digite um numero para inserir na pilha );
        scanf(%d, &num);
        pilha[++topo] = num;
    } else {
        printf(Pilha cheia!n);
    }
}

void remover_pilha() {
    if (topo = 0) {
        printf(Elemento removido %dn, pilha[topo--]);
    } else {
        printf(Pilha vazia!n);
    }
}

void mostrar_pilha() {
    if (topo = 0) {
        printf(Pilha );
        for (int i = topo; i = 0; i--) {
            printf(%d , pilha[i]);
        }
        printf(n);
    } else {
        printf(Pilha vazia!n);
    }
}

void inserir_fila() {
    if (tras  MAX) {
        int num;
        printf(Digite um numero para inserir na fila );
        scanf(%d, &num);
        fila[tras++] = num;
    } else {
        printf(Fila cheia!n);
    }
}

void remover_fila() {
    if (frente  tras) {
        printf(Elemento removido %dn, fila[frente++]);
    } else {
        printf(Fila vazia!n);
    }
}

void mostrar_fila() {
    if (frente  tras) {
        printf(Fila );
        for (int i = frente; i  tras; i++) {
            printf(%d , fila[i]);
        }
        printf(n);
    } else {
        printf(Fila vazia!n);
    }
}

int main() {
    int modo, escolha;

    while (1) {
        printf(nEscolha o modon1. Pilha (LIFO)n2. Fila (FIFO)n3. Sairn);
        scanf(%d, &modo);

        if (modo == 3) break;

        while (1) {
            printf(nEscolha a operacaon1. Inserirn2. Removern3. Mostrarn4. Voltarn);
            scanf(%d, &escolha);

            if (escolha == 4) break;

            if (modo == 1) {   Modo Pilha
                if (escolha == 1) inserir_pilha();
                else if (escolha == 2) remover_pilha();
                else if (escolha == 3) mostrar_pilha();
            } else if (modo == 2) {   Modo Fila
                if (escolha == 1) inserir_fila();
                else if (escolha == 2) remover_fila();
                else if (escolha == 3) mostrar_fila();
            }
        }
    }

    return 0;
}
