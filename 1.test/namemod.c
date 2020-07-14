//To compile:
// gcc namemod.c -Wall -Wextra -Werror -D BUFFER_SIZE=32 ../get_next_line.c ../get_next_line_utils.c -o NameModifier

//Additional test for fun. Memory leaks not handled.

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include "../get_next_line.h"

char *ft_vowel_changer(char *mods, char *ors);
int ft_isvowel(int ch);

int main(void)
{
    //_____Declarations_____
    char *name;
    char *newname = ft_strnew(0);

    //____Get Name of User__
    printf("\tWelcome!\n");
    printf("Enter your name: \n");
    get_next_line(0, &name);    //User name gotten by GNL function 

    //____Modify User Name__
    ft_vowel_changer(newname, name);

    //__Print Modified Name__
    printf("Your modified name is: \n%s\n", newname);
    free(newname);
    return (0);   
}

char     *ft_vowel_changer(char *mods, char *ors) //modified string | original string
{
    //Return a new string wich is the result of
    //the original name with random vowels.
    //
    //Open to improvements.

    int i = 0;
    int r;

    while (ors[i] != '\0')
    {
        if ((ft_isvowel(ors[i])) == 1) //change vowel for another vowel randomly
        {
            r = rand() % 6;
            if ((islower(ors[i])) > 0)
            {
                if (r == 1)
                    ors[i] = 'a';
                else if (r == 2)
                    ors[i] = 'e';
                else if (r == 3)
                    ors[i] = 'i';
                else if (r == 4)
                    ors[i] = 'o';
                else if (r == 5)
                    ors[i] = 'u';
                else
                    ors[i] = 'a';
            }
            else
            {
                 if (r == 1)
                    ors[i] = 'A';
                else if (r == 2)
                    ors[i] = 'E';
                else if (r == 3)
                    ors[i] = 'I';
                else if (r == 4)
                    ors[i] = 'O';
                else if (r == 5)
                    ors[i] = 'U';
                else
                    ors[i] = 'A';  
            }
        }
        mods[i] = ors[i];
        i++;
    }
    return (mods);
}

int ft_isvowel(int ch)
{
     //detect if char is vowel
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return (1);
    return(0);
}