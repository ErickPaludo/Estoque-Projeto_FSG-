#include <stdio.h>
#include <stdlib.h>

int main()
{
    char user;
    int pass;
    int verfificator;

   do
   {
       printf("User: ");
       scanf("%s", &user);
   }while(user == 'ADM' || user != 'UserD');
    return 0;
}
