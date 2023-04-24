#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char user[10];
    int pass;
    int vrfc;

while(vrfc == 0)
{
     printf("User: ");
     scanf("%s", &user);

    if (strcmp(user, "ADM") == 0 || strcmp(user, "empeloyee") == 0)
    {
    printf("Password: ");
    scanf("%d", &pass);
    }
    else
    {
        system("CLS");
    }

}
    return 0;
}
