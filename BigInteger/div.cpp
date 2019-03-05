#include"BigInteger.h"
void div(const BigInt &A ,const BigInt &B ,BigInt &shang ,BigInt &yushu)
{
    if(B.len==1 && B.num[0]==0)
        throw std::runtime_error("Divided can't be zero...");
    BigInt a=A ,b=B ,temp;
    a.sig = b.sig = true;//a，b取绝对值
    if(compare(a,b) < 0)//若a的绝对值小于b的绝对值
    {
        fuzhi0(shang);//shang=0
        yushu = A;//余数等于a
        return ;
    }
    int len_cha = a.len-b.len;
    //先乘以len_cha*10倍，即左移len_cha
    for(int i = b.len-1, j=a.len-1 ; i >= 0 ; i--,j--)
        b.num[j] = b.num[i];
    for(int i = 0; i < len_cha ; i++)
        b.num[i] = 0;
    b.len = a.len;
    if(compare(a,b) < 0)
    {
        int i = 1 ,j = 0;
        for(; i < b.len ;i++ ,j++)
            b.num[j] = b.num[i];
        b.len--;
        len_cha--;
    }
    shang.len = len_cha+1;
    int j ,i;
    while(len_cha >= 0)
    {
        if(compare(a,b) >= 0)
        {
            int k = 0;
            while(compare(a,b) >= 0)
            {
                k++;
                sub(a,b,temp);
                a = temp;
            }
            shang.num[len_cha] = k;
        }else shang.num[len_cha] = 0;
        for(i = 1 , j = 0; i < b.len ;i++ ,j++)
            b.num[j] = b.num[i];
        b.len--;
        len_cha--;
    }
    shang.sig = !(A.sig^B.sig);
    yushu = a;
    yushu.sig = A.sig;//余数的符号和被除数的符号一致
}
