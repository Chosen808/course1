#include <stdio.h>

#define JOIN(s,r,t) (s##r##t)
#define VARIABLE(a) a
#define areaTri(base,height) 0.5 * base * height
#define BASE(s,r,t) (s##rt);

main ()
{
    //int a = 0x9;
    //int b = 0x2;

    //printf ("%d \n", a * 2);

    int temp = 0;
    int b10 = 361;
    int b16 = 0;
    int p0 = 0;
    char base2;

    char base16[16] = {'1','2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 0; i < 6; i++)
    {
        printf ("base16 = %c \n", base16[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        temp = b10 % 16;
        b10 = b10 / 16;

        if (i == 0)
        {
            p0 = temp;

            if (temp > 9)
            {
                for (int b = 10; i < temp; i++)
                {
                    base2 = base16[i];

                    BASE (0x,temp,base16[temp]);
                }
            }
        }

        printf ("b16 = %d \n", b16);

        
    }

    //JOIN(0x,6)
    char af = "a";
    int ab = af;
    char b = "b";
    int c = JOIN (0x,1,);

    int n = BASE (0x,10,15);

    printf ("n = %d \n", n);

    printf ("\nc = %d \n", c);

    int VARIABLE(df) = 8;

    int (as) = 2;

    as = 2;

    int base1 = 20;
    int height = 20;
    int area = areaTri (base1, height);

    printf ("Area = %.2f \n", areaTri (base1,height));

    puts ("\n");

    return 0;
}