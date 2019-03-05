#include"BigInteger.h"
void print(BigInt &p)//��ӡ������
{
    if(p.sig == false)
        printf("-");
    for(int i = p.len-1 ; i >= 0; i--)
        printf("%d" ,p.num[i]);
    puts("");
}
int main()
{
    freopen("E:3.txt" ,"r" ,stdin);
    BigInt a ,b ,ans ,temp ,temp1;
    fuzhi1(temp1);//temp1 = 1
    char A[NUM_LEN] ,B[NUM_LEN];
    while(~scanf("%s%s" ,A ,B))
    {
        ten_to_bi(A ,a);
        ten_to_bi(B ,b);

        printf("A:");
        print(a);
        printf("B:");
        print(b);

        add(a,b,ans);//�ӷ�
        printf("ADD:");
        print(ans);

        sub(a,b,ans);//�ӷ�
        printf("SUB:");
        print(ans);

        mul(a,b,ans);//�˷�
        printf("MUL:");
        print(ans);

        div(a,b,ans,temp);//����
        printf("DIV:");
        print(ans);

        mod(a,b,ans);//ȡģ
        printf("MOD:");
        print(ans);

        gcd(a,b,ans);
        printf("GCD:");
        print(ans);

        sub(b,temp1,temp);//temp=b-1;
        pow_mod(a,temp,b,ans);//ans = a^(b-1)%b
        printf("POW_MOD:");//��ģ
        print(ans);

        inverse(a,b,ans);
        printf("INVERSE:");//�˷���
        print(ans);

        printf("*******************\n");
    }

    return 0;
}