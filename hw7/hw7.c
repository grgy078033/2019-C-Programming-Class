#include <stdio.h>
#include <stdlib.h>

double power(int x, int y)
{
    int i;
    double result = 1.0;
    if(y > 0)
    {
        for(i = 0; i < y; i++)
            result *= x;
    }
    else if(y < 0)
    {
        int z = 0 - y;
        for(i = 0; i < z; i++)
            result /= x;
    }
    return result;
}

union float_data1 {
    unsigned i;
    float fd;
};

struct float_data2 {
    unsigned i;
    float fd;
};

union double_data1 {
    unsigned long i;
    double dd;
};

struct double_data2 {
    unsigned long i;
    double dd;
};

union float_bits1 {
    struct {
	char Signed;
	char exp[8];
	char fraction[23];
    };
};

struct float_bits2 {
    char Signed;
    char exp[8];
    char fraction[23];
    float answer;
};

union double_bits1 {
    struct {
	char Signed;
	char exp[11];
	char fraction[52];
    };
};

struct double_bits2 {
    char Signed;
    char exp[11];
    char fraction[52];
    double answer;
};

int main(int argc, char *argv[])
{
    int z = atoi(argv[1]);
    if(z == 1)
    {
        union float_data1 x;
        x.fd = atof(argv[2]);
        x.i = *(int *)&x.fd;

	    struct float_data2 y;
        y.fd = atof(argv[2]);
        y.i = *(int *)&y.fd;

        int i;
        unsigned mask = 0x80000000;

	    printf("Union ");

        for(i = 0; i < 32; i++)
        {
            if(i == 0)
            {
                if(x.fd >= 0)
                    printf("0 ");
                else
                    printf("1 ");
            }
            if(i >= 1 && i < 9)
            {
                printf("%d", ((x.i&mask)>>(31 - i)));
                if(i == 8)
                    printf(" ");
            }
            if(i >= 9 && i < 32)
            {
                printf("%d", ((x.i&mask)>>(31 - i)));
                if(i == 31)
                    printf("\n");
            }
            mask >>= 1;
        }

	    mask = 0x80000000;
	    printf("Struct ");

        for(i = 0; i < 32; i++)
        {
            if(i == 0)
            {
                if(x.fd >= 0)
                    printf("0 ");
                else
                    printf("1 ");
            }
            if(i >= 1 && i < 9)
            {
                printf("%d", ((y.i&mask)>>(31 - i)));
                if(i == 8)
                    printf(" ");
            }
            if(i >= 9 && i < 32)
            {
                printf("%d", ((y.i&mask)>>(31 - i)));
                if(i == 31)
                    printf("\n");
            }
            mask >>= 1;
        }
    }
    
    else if(z == 2)
    {
        union double_data1 x;
        x.dd = atof(argv[2]);
        x.i = *(long int *)&x.dd;

        struct double_data2 y;
        y.dd = atof(argv[2]);
        y.i = *(long int *)&y.dd;

        int i;
        unsigned long mask = 0x8000000000000000;

	    printf("Union ");

        for(i = 0; i < 64; i++)
        {
            if(i == 0)
            {
                if(x.dd >= 0)
                    printf("0 ");
                else
                    printf("1 ");
            }
            if(i >= 1 && i < 12)
            {
                printf("%lld", ((x.i&mask)>>(63 - i)));
                if(i == 11)
                    printf(" ");
            }
            if(i >= 12 && i < 64)
            {
                printf("%lld", ((x.i&mask)>>(63 - i)));
                if(i == 63)
                    printf("\n");
            }
            mask >>= 1;
        }

        mask = 0x8000000000000000;
	    printf("Struct ");

        for(i = 0; i < 64; i++)
        {
            if(i == 0)
            {
                if(y.dd >= 0)
                    printf("0 ");
                else
                    printf("1 ");
            }
            if(i >= 1 && i < 12)
            {
                printf("%lld", ((y.i&mask)>>(63 - i)));
                if(i == 11)
                    printf(" ");
            }
            if(i >= 12 && i < 64)
            {
                printf("%lld", ((y.i&mask)>>(63 - i)));
                if(i == 63)
                    printf("\n");
            }
            mask >>= 1;
        }
    }
    
    else if(z == 3)
    {
        union float_bits1 x;
        sprintf(&x.Signed, "%c", argv[2]);
        sprintf(x.exp, "%8s", argv[3]);
        sprintf(x.fraction, "%23s", argv[4]);
	    float answer_x = 0.0;

        struct float_bits2 y;
        sprintf(&y.Signed, "%c", argv[2]);
        sprintf(y.exp, "%8s", argv[3]);
        sprintf(y.fraction, "%23s", argv[4]);
	    y.answer = 0.0;

        int i;
	    int z = atoi(argv[2]);

	    int binary_exp_x = 0;
        float binary_fra_x = 1.0;

        int binary_exp_y = 0;
        float binary_fra_y = 1.0;
        
        for(i = 7; i >= 0; i--)
            binary_exp_x += ( power(2, 7 - i) * (x.exp[i] - '0') );
        for(i = 0; i < 23; i++)
            binary_fra_x += ( power(2, -1 * (i + 1)  ) * (x.fraction[i] - '0') );
            
        answer_x = power(2, binary_exp_x - 127) * binary_fra_x;
        
        if(z == 0)
        {
            printf("");
            printf("Union %f\n", answer_x);
        }
        else if(z == 1)
        {
            printf("Union -");
            printf("%f\n", answer_x);
        }

	    for(i = 7; i >= 0; i--)
            binary_exp_y += ( power(2, 7 - i) * (y.exp[i] - '0') );
        for(i = 0; i < 23; i++)
            binary_fra_y += ( power(2, -1 * (i + 1)  ) * (y.fraction[i] - '0') );
            
        y.answer = power(2, binary_exp_y - 127) * binary_fra_y;
        
        if(z == 0)
        {
            printf("");
            printf("Struct %f\n", y.answer);
        }
        else if(z == 1)
        {
            printf("Struct -");
            printf("%f\n", y.answer);
        }
    }
    
    else if(z == 4)
    {
        union double_bits1 x;
        sprintf(&x.Signed, "%c", argv[2]);
        sprintf(x.exp, "%11s", argv[3]);
        sprintf(x.fraction, "%52s", argv[4]);
        float answer_x = 0.0;

        struct double_bits2 y;
        sprintf(&y.Signed, "%c", argv[2]);
        sprintf(y.exp, "%11s", argv[3]);
        sprintf(y.fraction, "%52s", argv[4]);
        y.answer = 0.0;

        int i;
	    int z = atoi(argv[2]);
	
	    int binary_exp_x = 0;
        float binary_fra_x = 1.0;

        int binary_exp_y = 0;
        float binary_fra_y = 1.0;
        
        for(i = 10; i >= 0; i--)
            binary_exp_x += ( power(2, 10 - i) * (x.exp[i] - '0') );
        for(i = 0; i < 52; i++)
            binary_fra_x += ( power(2, -1 * (i + 1)  ) * (x.fraction[i] - '0') );

        answer_x = power(2, binary_exp_x - 1023) * binary_fra_x;

        if(z == 0)
        {
            printf("");
            printf("Union %f\n", answer_x);
        }
        else if(z == 1)
        {
            printf("Union -");
            printf("%f\n", answer_x);
        }

        for(i = 10; i >= 0; i--)
            binary_exp_y += ( power(2, 10 - i) * (y.exp[i] - '0') );
        for(i = 0; i < 52; i++)
            binary_fra_y += ( power(2, -1 * (i + 1)  ) * (y.fraction[i] - '0') );

        y.answer = power(2, binary_exp_y - 1023) * binary_fra_y;

        if(z == 0)
        {
            printf("");
            printf("Struct %f\n", y.answer);
        }
        else if(z == 1)
        {
            printf("Struct -");
            printf("%f\n", y.answer);
        }
    }
    
    return 0;
}