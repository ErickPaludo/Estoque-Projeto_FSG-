#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user[10];
    int pass, name_arq, op;
    int vrfc = 0, cont_0 = 0;


while(vrfc == 0) // cadeia de repetição
{
    system("Cls");
     printf("User: "); //solicitar User ADM
     scanf("%s", &user);

     //LOGIN ADM ------------------------------------------------

    if (strcmp(user, "ADM") == 0)
        {
            system("Cls");
            do
            {

                printf("User: %s", user);
                printf("\nPassword: "); //solicita senha ADM
                scanf("%d", &pass);
                cont_0++;
                system("Cls");

                if(cont_0 <= 3)
                {
                    printf("Tentativa %d/3 \n", cont_0);
                }

                if(cont_0 == 3)
                {
                    printf("Voce execeu o numero de tentativas, tente novamente mais tarde! \n", cont_0);
                    exit(0);

                }


            } while (pass != 409027);
             vrfc = 1;
        }
         //lOGIN FUNCIONRIO ------------------------------------------------

       else if (strcmp(user, "EMP") == 0)
        {
            system("Cls");
            do
            {

                printf("User: %s", user);
                printf("\nPassword: "); //solicita senha ADM
                scanf("%d", &pass);
                system("Cls");
                cont_0++;

                if(cont_0 <= 3)
                {
                    printf("Tentativa %d/3 \n", cont_0);
                }

                if(cont_0 == 3)
                {
                    printf("Voce execeu o numero de tentativas, tente novamente mais tarde! \n", cont_0);
                    exit(0);

                }

            } while (pass != 300468);
             vrfc = 1;
        }

        //User INVALID

        else
        {

        }
    }

    //ACESSO
    system("CLS");
    printf("\033[32mACESSADO\033[0m\n");

    //ABA ORIGINAL ADM


     for(int i = 0; i <= 100;i++)
     {

    char nome_arquivo[10];
        sprintf(nome_arquivo, "Nome%d.txt", i);
        FILE *fp;
        fp = fopen(nome_arquivo, "w");
        fprintf(fp, " NULL ");
        fclose(fp);

        char preco_arquivo[10];
        sprintf(preco_arquivo, "Preco%d.txt", i);
        fp = fopen(preco_arquivo, "w");
        fprintf(fp, "NHE ");
        fclose(fp);
     }


    if (strcmp(user, "ADM") == 0)
        {
            //Home
            printf("\nADD estoque: (1)");
            printf("\nRemove estoque: (2)");
            printf("\nAdd no estoque (3)");
            printf("\nSaida do estoque (4)");
            scanf("%d", &op);

        }

    return 0;
}
