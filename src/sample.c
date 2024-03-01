#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PASTE(x, y) x##y // This will concatenate two integers. 15 and 15 will become 1515

uint8_t *myMemmove (uint8_t *src, uint8_t *dst, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        *dst++ = *src++;
    }

    return *dst;
}

uint8_t *myMemset (uint8_t *src, size_t length, uint8_t value)
{
    src[sizeof (length)] = value;

    return src[sizeof (length)];
}

uint8_t *myset (int *src, int length, int *value)
{
    src[sizeof (uint8_t) * length] = value;

    return &src[sizeof (uint8_t) * length];
}

uint8_t *myReverse (uint8_t *src, size_t length)
{
    uint8_t copy = 0;
    uint8_t mask = 1;
    uint8_t final = 0;

    for (int i = 0, j = length -1; i < length, j > -1; i++, j--)
    {
        copy = (*src >> i) & (mask);
        final = (final) | (copy << j);
    }

    src = final;

    return src;
}

int32_t *reserveWords (size_t length)
{
    size_t *word = NULL;

    word = (int32_t*) malloc (length * sizeof (int32_t));

    if (word == NULL)
    {
        printf ("Not allocated \n");
    }

    return word;
}

void freeWords (int32_t *src)
{
    free (src);
}

uint8_t myItoa (int32_t data, uint8_t *ptr, uint32_t base)
{

    int dataCopy = data;

    int base2 = 0;
    int base2One = 0;
    int base2Two = 0;
    int base2Three = 0;
    int base2Four = 0;
    int temp = 0;
    int count = 0;
/*
    if (base == 16)
    {
        int base16 = 0;
        int base16One = 0;
        int base16Two = 0;
        int base16Three = 0;
        int base16Four = 0;

        for (int i = 0; i < 255; i++)
        {
            temp = dataCopy % 16;
            dataCopy = dataCopy / 16;

            if (temp != 0)
            {
                //printf ("temp 16 = %d \n", temp);

                base16 += temp * pow (10, i);
            }
        }

        //printf ("base16 = %d \n", base16);

        int base10f16 = 0;

        for (int i = 0; i < 255; i++)
        {
            temp = base16 % 10;
            base16 = base16 / 10;

            if (temp != 0)
            {
                printf ("temp 16 convert = %d \n", temp);

                base10f16 += temp * pow (16, i);
            }
        }

        printf ("base10f16 = %d \n", base10f16);
    }*/

    for (int i = 0; i < 255; i++)
    {
        if (dataCopy != 0)
        {
            temp = dataCopy % 2;
            dataCopy = dataCopy / 2;

            printf ("temp = %d \n", temp);
            printf ("dataCopy = %d \n", dataCopy);

            if (temp != 0 || i == 7)
            {
                base2 += temp * pow (10, i);

                if (i == 7 || dataCopy == 0)
                {
                    i = -1;

                    count++;

                    if (count == 1)
                    {
                        base2One = base2;

                        base2 = 0;
                    }

                    else if (count == 2)
                    {
                        base2Two = base2;

                        base2 = 0;
                    }

                    else if (count == 3)
                    {
                        base2Three = base2;

                        base2 = 0;
                    }

                    else if (count = 4)
                    {
                        base2Four = base2;

                        base2 = 0;
                    }
                }
            }
        }
    }

    printf ("baseTwo1 = %d \n", base2One);
    printf ("baseTwo2 = %d \n", base2Two);
    printf ("baseTwo3 = %d \n", base2Three);
    printf ("baseTwo4 = %d \n", base2Four);

    int charZero = 0;
    int charOne = 0;
    int charTwo = 0;
    int charThree = 0;
    int remainder;

    for (int i = 0; i < 8; i++)
    {
        remainder = base2One % 10;
        base2One = base2One / 10;

        printf ("remainder Zero = %d \n", remainder);

        charZero += remainder * pow (2, i);

        printf ("charZero = %d \n", charZero);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base2Two % 10;
        base2Two = base2Two / 10;

        printf (" remainder One = %d \n", remainder);

        charOne += remainder * pow (2, i);

        printf ("CharOne = %d \n", charOne);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base2Three % 10;
        base2Three = base2Three /10;

        charTwo += remainder * pow (2, i);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base2Four % 10;
        base2Four = base2Four / 10;

        charThree += remainder * pow (2, i);
    }

    printf ("charzero = %d \n", charZero);
    ptr[sizeof (uint8_t) * 0] = charZero;
    ptr[sizeof (uint8_t) * 1] = charOne;
    ptr[sizeof (uint8_t) * 2] = charTwo;
    ptr[sizeof (uint8_t) * 3] = charThree;
    ptr[sizeof (uint8_t) * 4] = '\0';

    printf ("ptr[0] = %d , charZero = %d \n", ptr[sizeof (uint8_t) * 0], charZero);
    printf ("ptr[1] = %d , charOne = %d \n", ptr[sizeof (uint8_t) * 1], charOne);


    int count2 = 0;

    for (int8_t i = 0; i < 5; i++)
    {
        if (ptr[sizeof (uint8_t) * i] != 0)
        {
            count2++;

            //printf ("ptr[%d] = %d \n", i, ptr[sizeof (int) * i]);

            printf ("count = %d \n", count2);
        }
    }

    count2 = count2 + 1;

    return count2;

    
    
}

void swap (void *vp1, void *vp2, int size)
{
    uint8_t buffer[size];

    memcpy (buffer, vp1, size);
    memcpy (vp1, vp2, size);
    memcpy (vp2, buffer, size);
}


main ()
{
    uint8_t a[3] = {2, 3, 23};
    uint8_t s[3];
    uint8_t size = 3;

    uint8_t w[4] = {36, 34, 200, 255};
    uint8_t e[4];
    uint8_t size2 = 4;

    uint8_t we = 19;
    uint8_t rt;
    uint8_t size3 = 1;
    uint8_t y = 45;
    uint8_t u = 54;
    uint8_t j = 76;
    uint8_t k = 98;
    uint8_t m = 12;
    int df = 193232;
    char fg[] = "dw";
    int yu = 12345634;

    uint8_t *ptr = NULL;

    printf ("SIZE of ptr = %ld \n", sizeof (ptr));

    ptr = (uint64_t*) malloc (2 * sizeof (uint64_t));

    printf ("ptr address = %p \n", ptr);

    if (ptr == NULL)
    {
        printf ("Not allocated \n");
    }

    printf ("SIZE of ptr = %ld \n", sizeof (ptr));

    printf ("SIZE OF w = %ld \n", sizeof (w));

    for (int i = 0; i < size; i++)
    {
        printf ("s[%d] = %d \n", i, s[i]);
    }

    myMemmove (a, s, size);

    for (int i = 0; i < size; i++)
    {
        printf ("s[%d] = %d \n", i, s[i]);
    }

    for (int i = 0; i < size2; i++)
    {
        printf ("e = %d \n", e[i]);
    }

    myMemmove (w, e, size2);

    for (int i = 0; i < size2; i++)
    {
        printf ("e = %d \n", e[i]);
    }

    //myMemset (w, 1, we);

    printf ("w[0] = %d \n", w[0]);

    for (int i = 0; i < size2; i++)
    {
        printf ("w[%d] = %p \n", i, &w[i]);
    }

    printf ("Ptr = %d \n", ptr[sizeof (uint8_t) * 0] = 17);
    printf ("Ptr 17 = %p \n", &ptr[sizeof (uint8_t) * 0]);
    printf ("Ptr = %d \n", ptr[sizeof (uint8_t) * 1] = 23 );
    printf ("Ptr = %p \n", &ptr[sizeof (uint8_t) * 1]);
    (int)ptr[sizeof (uint8_t) * 2];
    printf ("Ptr = %d \n", ptr[sizeof (uint8_t) * 2] = 2344);
    printf ("Ptr = %p \n", &ptr[sizeof (uint8_t) * 2]);
    //myset (ptr, 1, 2344);

    uint8_t pett = 234;

    printf ("pett = %d \n", pett);

    for (int i = 0; i < 4; i++)
    {
        printf ("ptr = %d \n", ptr[i]);
    }
    printf ("TEST");

    uint8_t gh = 13;

    for (long long i = 0; i < sizeof (int); i++)
    {
        printf ("%02hhx ", ((unsigned char *)&gh)[i]);
    }

    puts ("\n");

    uint8_t firstNumber = 4;
    uint8_t copy = 0;
    uint8_t mask = 1;
    uint8_t final;

    size_t length = 8;

    for (int i = 0, j = length -1; i < length, j > -1; i++, j--)
    {
        copy = (firstNumber >> i) & (mask);
        final = (final) | (copy << j);

        printf ("i = %d, j = %d \n", i, j);
    }

    firstNumber = final;

    printf ("firstnumber = %d \n", firstNumber);

    for (int j = length - 1, i = 0; j > -1, i < length; j--, i++)
    {
        printf ("j = %d , i + %d \n", j, i);
    }

    printf ("firstnumber = %d \n", myReverse (&firstNumber, 8));

    reserveWords (8);

    freeWords (reserveWords (8));

    free (ptr);

    //size_t *str;

    //printf ("%s \n", myItoa (67, str, 4));

    int i = 44;
    short qe = 5;
    uint8_t fd = 5;

    //i = (i << 16);

    printf ("i = %d \n", i);

    swap (&i, &fd, sizeof (uint8_t));

    printf ("i = %d, qe = %d \n", i, fd);

    char *person1 = "John";
    char *person2 = "Matthew";

    swap (&person1, &person2, sizeof (char*));

    printf ("person1 = %s, person2 = %s \n", person1, person2);

    uint8_t *str = NULL;

    str = (uint64_t*) malloc (sizeof (uint64_t));
     if (str == NULL)
     {
        printf ("Memory not allocated \n");
     }
     
    str[sizeof (uint8_t) * 0] = 65;
    str[sizeof (uint8_t) * 1] = 66;
    str[sizeof (uint8_t) * 2] = 67;
    str[sizeof (uint8_t) * 3] = 68;
    str[sizeof (uint8_t) * 4] = '\0';

    for (int i = 0; i < 5; i++)
    {
        printf ("Str = %s \n", str);
    }

    int array[10] = {12, 23, 54, 143, 75, 35, 996, 233};
    int *pArray = NULL;

    pArray = (int*) malloc (sizeof (int) * 9);

    if (pArray == NULL)
    {
        printf ("Memory not allocated \n");
    }

    printf ("SIZE = %d \n", sizeof (pArray));

    for (int i = 0; i < 8;i++)
    {
        pArray[i] = array[i];

        printf ("pArray = %d \n", pArray[i]);
    }

    int bin = 0b01111101;
    int hex = 0x7D;
    int oct = 0175;
    int dec = 125;

    uint8_t *string = NULL;

    //string = (uint8_t*) malloc (sizeof (uint8_t) * 2);

    if (string == NULL)
    {
        printf ("Memory not allocated \n");
    }

    //string[sizeof (uint8_t) * 0] = 0x7D;
    //string[sizeof (uint8_t) * 1] = 0x7E;
    //string[sizeof (uint8_t) * 2] = '\0';

    /*for (int i = 0; i < 200; i++)
    {
        if (string[sizeof (uint8_t) * i] == '\0')
        {
            printf ("i = %d \n", i);

            return 0;
        }
    }*/


   // printf ("string %s \n", string); 

    //printf ("UUstring %d \n", myItoa (oct, string, 10)); //NB Why is this printing P since you have created the mem alloc in the function

    if (string == NULL)
    {
        printf ("Memory not allocated \n");
    }

    free (string);

    free (pArray);

    int hexJ = 0x4A;
    uint8_t *print = NULL;

    //myItoa (hex, print, 10);
    //printf ("print = %s \n", myItoa (hexJ, print, 10)); // NB Why is this not printing 

    char *howMany = "string";

    printf ("howMany = %d \n", *howMany);

    free (print);

    int tentotwo = 0b0100001001000001;

    int temp;
    int div = tentotwo;
    unsigned int base = 0;
    unsigned int base1 = 0;
    unsigned int base2 = 0;
    unsigned int base3 = 0;
    unsigned int base4 = 0;

    int count = 0;
    int index = 1;

    printf ("BASE2 = %d \n\n\n", div);

    for (int i = 0; i < 8; i++)
    {
        if (div != 0)
        {
            temp = div % 2;
            div = div / 2;

            printf ("temp = %d \n", temp);
            //printf ("div = %d \n", div);

            if (temp != 0 || i == 7)
            {
                base += temp * pow (10, i);

                printf ("base = %d \n", base);
                
                if (i == 7 || div == 0 )
                {
                    i = -1;

                    count++;

                    if (count == 1)
                    {
                        base1 = base;

                        base = 0;
                    }

                    else if (count == 2)
                    {
                        base2 = base;

                        base = 0;
                    }

                    else if (count == 3)
                    {
                        base3 = base;

                        base = 0;
                    }

                    else if (count = 4)
                    {
                        base4 = base;

                        base = 0;
                    }
                }
            }
        }
    }

    printf ("base1 = %d \n", base1);
    printf ("base2 = %d \n", base2);
    printf ("base3 = %d \n", base3);
    printf ("base4 = %d \n", base4);

    puts ("\n\n");

    int characterOne = 0;
    int characterTwo = 0;
    int characterThree = 0;
    int characterFour = 0;

    int division1 = 0;
    int remainder = 0;

    for (int i = 0; i < 8; i++)
    {
        remainder = base1 % 10;
        base1 = base1 / 10;

        characterOne += remainder * pow (2, i);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base2 % 10;
        base2 = base2 / 10;

        characterTwo += remainder * pow (2, i);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base3 % 10;
        base3 = base3 / 10;

        characterThree += remainder * pow (2, i);
    }

    for (int i = 0; i < 8; i++)
    {
        remainder = base4 % 10;
        base4 = base4 / 10;

        characterFour += remainder * pow (2, i);
    }

    int twen = 20;
    int divide;

    divide = twen % 10;

    printf ("divide = %d \n", divide);



    printf ("characterOne = %c \n", characterOne);
    printf ("characterTwo = %c \n", characterTwo);
    printf ("characterThree = %d \n", characterThree);
    printf ("characterFour = %d \n", characterFour);

    int stringInt = 0b10010000000010000000010000001000;
    int stringIntNeg = -1002;

    printf ("stringInt = %d \n", stringInt);

    uint8_t *ptrrr = NULL;

    ptrrr = (int32_t*) malloc (2 * sizeof (int32_t));

    if (ptrrr == NULL)
    {
        printf ("Memory not allocated PTRRR \n");
    }

    //myItoa (stringInt, ptrrr, 10);

    uint32_t num2 = 0b1010000011101011;
    printf ("num = %d \n", num2);

    printf ("i = %d \n", myItoa (-4096, ptrrr, 10));

    printf ("ptrrr = %s \n", ptrrr);

    /*
    int base16 = 0x4926;

    printf ("%u \n", base16);

    int8_t man = 208;

    printf ("man = %d \n", man);

    char *inpt = NULL;

    inpt = (char*) malloc (sizeof (char) * 2);

    if (inpt == NULL)
    {
        printf ("Memory not allocated \n");
    }

    inpt[sizeof (char) * 0] = -23;
    inpt[sizeof (char) * 1] = '\0';

    printf ("inpt = %s \n", inpt);

    free (inpt);

    int baseSixteen = 0b01111111111111111111111111111111U;
    unsigned int baseTest = 12;

    //printf ("base 10 = %d \n base 16 = 0x%x , baseTest = %d \n", baseSixteen, baseSixteen, baseTest);

    char charT = 'A';
    int charTin = 0xab;

    printf ("charTin = 0x%d \n", charTin);*/

    printf ("%d \n", PASTE (15, 15));

    return 0;
}