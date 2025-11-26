#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char categoria[30];
    int ativo;
} Produto;

// ---------- CRUD ----------
void cadastrar(Produto lista[], int *contador) {
    if (*contador >= MAX) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    Produto p;
    p.id = *contador + 1;

    printf("Nome do produto: ");
    fflush(stdin);
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &p.quantidade);

    printf("Preço: ");
    scanf("%f", &p.preco);

    printf("Categoria: ");
    fflush(stdin);
    fgets(p.categoria, 30, stdin);
    p.categoria[strcspn(p.categoria, "\n")] = '\0';

    p.ativo = 1;

    lista[*contador] = p;
    (*contador)++;

    printf("Produto cadastrado com sucesso!\n");
}

void listar(Produto lista[], int contador) {
    printf("\n--- LISTA DE PRODUTOS ---\n");
    for (int i = 0; i < contador; i++) {
        if (lista[i].ativo == 1) {
            printf("ID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Quantidade: %d\n", lista[i].quantidade);
            printf("Preço: R$ %.2f\n", lista[i].preco);
            printf("Categoria: %s\n", lista[i].categoria);
            printf("-------------------------\n");
        }
    }
}

void atualizar(Produto lista[], int contador) {
    int id;
    printf("Digite o ID para atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (lista[i].id == id && lista[i].ativo == 1) {

            printf("Novo nome: ");
            fflush(stdin);
            fgets(lista[i].nome, 50, stdin);
            lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

            printf("Nova quantidade: ");
            scanf("%d", &lista[i].quantidade);

            printf("Novo preço: ");
            scanf("%f", &lista[i].preco);

            printf("Nova categoria: ");
            fflush(stdin);
            fgets(lista[i].categoria, 30, stdin);
            lista[i].categoria[strcspn(lista[i].categoria, "\n")] = '\0';

            printf("Produto atualizado!\n");
            return;
        }
    }

    printf("ID não encontrado!\n");
}

void deletar(Produto lista[], int contador) {
    int id;
    printf("Digite o ID para deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (lista[i].id == id && lista[i].ativo == 1) {
            lista[i].ativo = 0;
            printf("Produto deletado!\n");
            return;
        }
    }

    printf("ID não encontrado!\n");
}

// ---------- FUNCIONALIDADE ADICIONAL ----------
void ordenarPorPreco(Produto lista[], int contador) {
    Produto temp;

    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (lista[j].preco > lista[j + 1].preco) {

                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }

    printf("\nProdutos ordenados por preço!\n");
}

int main() {
    Produto lista[MAX];
    int contador = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA CRUD DE PRODUTOS ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Atualizar produto\n");
        printf("4 - Deletar produto\n");
        printf("5 - Ordenar por preço\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar(lista, &contador); break;
            case 2: listar(lista, contador); break;
            case 3: atualizar(lista, contador); break;
            case 4: deletar(lista, contador); break;
            case 5: ordenarPorPreco(lista, contador); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
