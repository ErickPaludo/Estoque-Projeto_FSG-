#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

FILE *lista;

int ver = 0, h = 1, quant[100];
float preco[100], sum[100], sum_2 = 0; // Variáveis globais
char name[100][100];
void msg_error()
{
    system("cls");
    printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
    system("pause > null");
    system("cls");
}
int validar(char user[3], int pass, int cont) // Verifica senha
{
    if (strcmp(user, "ADM") == 0 && pass == 2605223) {
        return 1;
    } else {
        system("cls");
        if (cont == 3) {
            printf("Attempt limit reached, please come back later!");
            exit(0);
        } else {
            printf("=====[InvControlVanilla]=====");
            printf("\n\nPassword or username is incorrect(%d/3)", cont);
            printf("\n\nUser: ");
        }
        return 0;
    }
}

void maiuscula(char user[3])
{
    for (int i = 0; i < 3; i++) {
        user[i] = toupper(user[i]);
    }
}

int no_copy(char name_nocopy[35]) {
    for (int i = 1; i < h; i++) {
        if (strcmp(name_nocopy, name[i]) == 0) {
            system("cls");
            printf("NOME JÁ ESTÁ EM USO!");
            system("pause > null");
            return 1;
        }
    }
    return 0;
}

void action(int x)
{
    if (x >= 0 && x <= 5) { // Adiciona registro
        if (x == 0) {
        do {
            char tmp[100];
            system("CLS");
            printf("\n===============");
            printf("\n Registro ADD");
            printf("\n===============");
            sum[h];
            printf("\nDigite o nome do produto: ");
            if (h == 1) {
                 getchar();
                 fgets(name[h], sizeof(name[h]), stdin);
                 name[h][strcspn(name[h],"\n")] = '\0';

                printf("\nInforme a quantidade inicial do estoque: ");
                scanf("%d", &quant[h]);
                if(quant[h] > 0){
                     printf("\nInforme o valor do produto: R$ ");
                scanf("%f", &preco[h]);
                if(preco[h] > 0){
                printf("\nDeseja continuar? (0=Sim / 1=Não)");
                printf("\n");
                scanf("%d", &ver);
                h++;
                if (ver != 0) {
                    ver = 1;
                }
                }
                else{
                    msg_error();
                    ver = 1;
                }
                }
                else{
                    msg_error();
                    ver = 1;
                }

            } else {
                getchar();
                 fgets(tmp, sizeof(tmp), stdin);
                 tmp[strcspn(tmp,"\n")] = '\0';


                int ver_2 = no_copy(tmp);
                if (ver_2 != 1) {
                    strcpy(name[h], tmp);
                    printf("\nInforme a quantidade inicial do estoque: ");
                scanf("%d", &quant[h]);
                if(quant[h] > 0){
                     printf("\nInforme o valor do produto: R$ ");
                scanf("%f", &preco[h]);
                if(preco[h] > 0){
                printf("\nDeseja continuar? (0=Sim / 1=Não)");
                printf("\n");
                scanf("%d", &ver);
                h++;
                if (ver != 0) {
                    ver = 1;
                }
                }
                else{
                    msg_error();
                    ver = 1;
                }
                }
                else{
                    msg_error();
                    ver = 1;
                }
            }
            }
        } while (ver != 1);
        system("cls");
    }
    else if (x == 1) { // Editar registro
        system("cls");
        printf("============================EDITOR DE REGISTROS============================");
        for (int i = 1; i < h; i++) {
            sum_2 = sum_2 + sum[i];
            printf("\n===========================================================================");
            printf("\nREGISTRO %d, NOME: %s, QUANTIDADE ATUAL: %d, VALOR R$%.2f", i, name[i], quant[i], preco[i]);
            printf("\n===========================================================================");
        }
        printf("\n\nInforme o registro que deseja EDITAR: ");
        scanf("%d", &x);

        if (x > 0 && x <= h - 1) {
            system("cls");
            printf("=========== EDITOR DE REGISTROS ===========");
            printf("\n============== REGISTRO N° %d ==============", x);
            printf("\n===========================================");
            for (int i = 1; i < h; i++) {
                if (i == x) {
                    printf("\nNome: %s", name[i]);
                    printf("\nQuantidade: %d", quant[i]);
                    printf("\nPreço: R$%2.f", preco[i]);
                    printf("\n===========================================");
                    printf("\n              -ALTERAR NOME <0>");
                    printf("\n              -ALTERAR PREÇO <1>");
                    printf("\n===========================================");
                    printf("\nInforme qual ação deve ser realizada: ");
                    scanf("%d", &x);
                    if (x == 0) { // Alterar nome
                        system("cls");
                        printf("============== ALTERAR NOME ===============");
                        printf("\n=========== REGISTRO N° %d ===========", i);
                        printf("\n==========================================");
                        char tmp[100];
                        printf("\nInforme o nome do novo item: ");
                        getchar();
                        fgets(tmp, sizeof(tmp), stdin);
                        tmp[strcspn(tmp,"\n")] = '\0';
                        int var_nocopy = no_copy(tmp);
                        if(var_nocopy != 1){
                          strcpy(name[i], tmp);
                          system("cls");
                        printf("AS ALTERAÇÕES FORAM REALIZADAS COM SUCESSO!");
                        system("pause > null");
                        system("cls");
                        }
                        else{

                        }

                    }
                    else if (x == 1) { // Alterar preço
                    system("cls");
                        printf("============== ALTERAR PREÇO ===============");
                        printf("\n=============== REGISTRO N° %d ===============", x);
                        printf("\n==========================================");
                        float tmp;
                        printf("\nInforme o novo preço do item: R$ ");
                        scanf("%f", &tmp);
                        if(tmp > 0){
                        preco[i] = tmp;
                        system("cls");
                        printf("AS ALTERAÇÕES FORAM REALIZADAS COM SUCESSO!");
                        system("pause > null");
                        system("cls");
                    }
                    else{
                        system("cls");
                        printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
                        system("pause > null");
                        system("cls");
                    }
                    }
                    else{
                        system("cls");
                        printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
                        system("pause > null");
                        system("cls");}
                    }
                    else { // Error

                }
            }
        }
         else {
            system("cls");
            printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
            system("pause > null");
            system("cls");
        }
    }
    else if (x == 2) { // Adiciona produto
        system("cls");
        printf("=========== ADICIONER PREÇO ===========");
        for (int i = 1; i < h; i++) {
            sum_2 = sum_2 + sum[i];
            printf("\n===========================================================================");
            printf("\nREGISTRO %d, NOME: %s, QUANTIDADE ATUAL: %d", i, name[i], quant[i]);
            printf("\n===========================================================================");
        }

        printf("\nDigite o REGISTRO do item que deseja ADICIONAR quantidade: ");
        scanf("%d", &x);

        if (x > 0 && x <= h - 1) {
            for (int i = 1; i <= h; i++) {
                if (i == x) {
                    printf("\nQuantos itens devem ser adicionados: ");
                    scanf("%d", &x);
                    if (x > 0) {
                        quant[i] = quant[i] + x;
                        system("cls");
                        printf("Foram adicionados %d itens em %s, totalizando %d itens!", x, name[i], quant[i]);
                        system("pause > null");
                        system("cls");
                    }
                    else {
                        system("cls");
                        printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
                        system("pause > null");
                        system("cls");
                    }
                } else {
                }
            }
        } else {
            system("cls");
            printf("REGISTRO INVALIDO");
            system("pause > null");
            system("cls");
        }
    }
    else if (x == 3) { // Remove produto
        system("cls");
        printf("======REMOVER PRODUTO======");
        for (int i = 1; i < h; i++) {
            sum_2 = sum_2 + sum[i];
            printf("\n===========================================================================");
            printf("\nREGISTRO %d, NOME: %s, QUANTIDADE ATUAL: %d", i, name[i], quant[i]);
            printf("\n===========================================================================");
        }

        printf("\nDigite o REGISTRO do item que deseja REMOVER quantidade: ");
        scanf("%d", &x);

        if (x > 0 && x <= h - 1) {
            for (int i = 1; i < h; i++) {
                if (i == x) {
                    printf("\nQuantos itens devem ser removidos: ");
                    scanf("%d", &x);
                    if (x > 0 && x <= quant[i]) {
                        quant[i] = quant[i] - x;
                        system("cls");
                        printf("Foram removidos %d itens em %s, totalizando %d itens!", x, name[i], quant[i]);
                        system("pause > null");
                        system("cls");
                    } else if (x > quant[i] || x <= 0) {
                        system("cls");
                        printf("NÃO FOI POSSÍVEL CONCLUIR A OPERAÇÃO!");
                        system("pause > null");
                        system("cls");
                    }
                } else {
                }
            }
        } else {
            system("cls");
            printf("REGISTRO INVALIDO");
            system("pause > null");
            system("cls");
        }
    }
    else if (x == 4) { // Listador
        system("cls");

        printf("======EXTRATO DO ESTOQUE======");

        for (int i = 1; i < h; i++) {
            sum[i] = (float)quant[i] * preco[i];
        }
        sum_2 = 0;
        for (int i = 1; i < h; i++) {
            sum_2 = sum_2 + sum[i];
            printf("\n      ==================");
            printf("\n         %d°  REGISTRO", i);
            printf("\n      ==================");
            printf("\n\nNome do produto: %s ", name[i]);
            printf("\n\nA quantidade armazenada é: %d", quant[i]);
            printf("\n\nValor do produto é de R$%.2f", preco[i]);
            printf("\n\n---------------------------------------------");
            printf("\nValor total do produto em Estoque: R$%.2f", sum[i]);
            printf("\n---------------------------------------------");
            printf("\n");
        }
        printf("\n---------------------------------------------");
        printf("\nValor total no estoque: R$%.2f", sum_2);
        printf("\n---------------------------------------------");
        printf("\nDeseja salvar o extrato? Sim <0> | Não <1>");
        printf("\nDigite: ");
        scanf("%d",&x);
        if(x == 0){
            system("cls");
        lista = fopen("extrato.txt", "w");
        fprintf(lista, "======EXTRATO DO ESTOQUE======");

        if (lista == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        sum_2 = 0;
        for (int i = 1; i < h; i++) {
            sum_2 = sum_2 + sum[i];
            fprintf(lista, "\n      ==================");
            fprintf(lista, "\n         %d°  REGISTRO", i);
            fprintf(lista, "\n      ==================");
            fprintf(lista, "\n\nNome do produto: %s ", name[i]);
            fprintf(lista, "\n\nA quantidade armazenada é: %d", quant[i]);
            fprintf(lista, "\n\nValor do produto é de R$%.2f", preco[i]);
            fprintf(lista, "\n\n---------------------------------------------");
            fprintf(lista, "\nValor total do produto em Estoque: R$%.2f", sum[i]);
            fprintf(lista, "\n---------------------------------------------");
            fprintf(lista, "\n");
        }
        fprintf(lista, "\n---------------------------------------------");
        fprintf(lista, "\nValor total no estoque: R$%.2f", sum_2);
        fprintf(lista, "\n---------------------------------------------");
        system("Cls");
        fclose(lista);
        system("start extrato.txt");
        system("cls");
        }
        else{
        system("cls");
        }
    }
    else if (x == 5) { // Sair
        system("cls");
        printf("PROGRAMA FINALIZADO");
        exit(0);
    }
    }
else{
    system("cls");
}

}


int main() {
    setlocale(LC_ALL, "Portuguese"); // Serve para por acentos

    char user[3];
    int veri = 0, pass, cont = 1;
    printf("=====[InvControlVanilla]=====");
    printf("\n\nUser: ");

    do {
        scanf("%s", user);
        maiuscula(user);
        printf("Password: ");
        scanf("%d", &pass);
        veri = validar(user, pass, cont);
        cont++;

    } while (veri == 0);

    int x;
    system("cls");
    veri = 0;
    do {
        printf("|=======================================================|");
        printf("\n|=====[ Welcome for InvControlVanilla, User: %s ]======|", user);
        printf("\n|=======================================================|");

        printf("\n|            - Registrar novo item [0]                  |");

        printf("\n|            - Editar registro [1]                      |");

        printf("\n|            - Adicionar item [2]                       |");

        printf("\n|            - Remover item [3]                         |");

        printf("\n|            - Extrato do estoque [4]                   |");

        printf("\n|            - Sair [5]                                 |");
        printf("\n|=======================================================|");
        printf("\n|                                                       |");
        printf("\n|               <Escolha uma ação>                      |");
        printf("\n|                                                       |");
        printf("\n|=======================================================|");
        printf("\n                         ");
        scanf("%d", &x);
        action(x);
    } while (veri == 0);

    return 0;
}
