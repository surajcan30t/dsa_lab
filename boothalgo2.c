#include<stdio.h>
#include<conio.h>
void disp_binary(int x)
{
    char a[16];
    int masks[16] = {0x8000,0x4000,0x2000,0x1000,0x0800,0x0400,0x0200,0x0100,0x0080,0x8040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001};
    int i;
    for(i = 0; i < 16; i++){
        if((x &masks[i])==0)
            printf("0");
        else
            printf("1");
    }
}

int main()
{
    int acq,m,q_1,i,q_0;
    printf("\nEnter multiplicand(-128 to 127) : ");
    scanf("%d",&m);
    disp_binary(m);
    printf("\nEnter multiplier (-128 to 127) :");
    scanf("%d",&acq);
    acq = (acq & 0x00ff);
    q_1 = 0;
    printf("\n");
    disp_binary(acq);
    printf("%d",q_1);
    for(i = 0; i < 8; i++)
    {
        q_0 = acq & 0x0001;
        if(q_0 == 1 && q_1 == 0){
            acq = acq - (m << 8);

        }
        else
        {
            if(q_0 == 0 && q_1 == 1)
            {

                acq = acq + (m<<8);
            }
        }
        q_1 = (acq & 0x0001);
        acq = (acq >> 1);
        printf("\n");
        disp_binary(acq);
        printf("%d",q_1);
    }
    printf("\n Product = ");
    disp_binary(acq);
    getch();
    return 0;
}
