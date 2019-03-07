#include"BigInteger.h"
void print(BigInt &p)//打印大整数
{
    if(p.sig == false)
        printf("-");
    for(int i = p.len-1 ; i >= 0; i--)
        printf("%d" ,p.num[i]);
    puts("");
}
int main()
{
    srand((unsigned)time(NULL));
    freopen("e:bigPrimes.txt" ,"w" ,stdout);
    BigInt ans;
    generate_prime(ans ,TEN_LEN_1024);
    print(ans);
 /*
    freopen("e:bigPrimes.txt" ,"r" ,stdin);
    srand((unsigned)time(NULL));
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

        add(a,b,ans);//加法
        printf("ADD:");
        print(ans);

        sub(a,b,ans);//加法
        printf("SUB:");
        print(ans);

        mul(a,b,ans);//乘法
        printf("MUL:");
        print(ans);

        div(a,b,ans,temp);//除法
        printf("DIV:");
        print(ans);

        mod(a,b,ans);//取模
        printf("MOD:");
        print(ans);

        gcd(a,b,ans);
        printf("GCD:");
        print(ans);

        sub(b,temp1,temp);//temp=b-1;
        pow_mod(a,temp,b,ans);//ans = a^(b-1)%b
        printf("POW_MOD:");//幂模
        print(ans);

        inverse(a,b,ans);
        printf("INVERSE:");//乘法逆
        print(ans);

        printf("%s",A);
        printf(Miller_Rabin(a) ? "\n有可能是素数\n" : "\n不是素数\n");
        printf("*******************\n");
        printf("%s",B);
        printf(Miller_Rabin(b) ? "\n有可能是素数\n" : "\n不是素数\n");

        printf("*******************\n");
    }*/

    return 0;
}
