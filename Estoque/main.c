#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user[10];
    int pass;
    int vrfc, cont_0 = 0;

while(vrfc == 0) // cadeia de repetição
{
     printf("User: "); //solicitar User ADM
     scanf("%s", &user);

     //LOGIN ADM ------------------------------------------------

    if (strcmp(user, "ADM") == 0)
        {
            do
            {
                system("Cls");
                printf("User: %s", user);
                printf("\nPassword: "); //solicita senha ADM
                scanf("%d", &pass);

                cont_0++;
                if(cont_0 == 3)
                {
                    exit(0);
                }


            } while (pass != 409027);
             vrfc = 1;
        }
         //lOGIN FUNCIONRIO ------------------------------------------------

       else if (strcmp(user, "EMP") == 0)
        {
            do
            {
                system("Cls");
                printf("User: %s", user);
                printf("\nPassword: "); //solicita senha ADM
                scanf("%d", &pass);

            } while (pass != 300468);
             vrfc = 1;
        }

        //User INVALID

        else
        {
            system("CLS");
        }
    }

    //NOVA ÀREA

    printf("\033[32mACESSADO\033[0m\n");

    if (strcmp(user, "ADM") == 0)
        {

        }

    return 0;
}
