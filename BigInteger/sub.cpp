#include"BigInteger.h"
void sub(const BigInt &a ,const BigInt &b ,BigInt &ans)
{
    if(a.sig != b.sig)//��a��b���Ų�һ��,b�෴����Ȼ��ִ�мӷ�
    {
        BigInt temp = b;
        temp.sig = !b.sig; //bȡ�෴��
        add(a ,temp ,ans);
    }else{//a,b�����������a<b����Ϊ������֮Ϊ��
        bool sig = compare(a,b)>=0 ? true : false;
        const BigInt *pmax=&a ,*pmin=&b;//�ȶ������ֵ�����a
        if(a.sig != sig)
        {
            pmax = &b;
            pmin = &a;
        }
        char borrow = 0;
        int i = 0;
        for(; i < pmin->len; i++)
        {
            ans.num[i] = pmax->num[i]-pmin->num[i]-borrow;
            if(ans.num[i] < 0)
            {
                borrow = 1;
                ans.num[i] += 10;
            }else borrow = 0;
            //printf("num[i]=%d , borrow=%d\n" ,ans.num[i] ,borrow);
        }
        for( ; i < pmax->len ; i++)
        {
            ans.num[i] = pmax->num[i] - borrow;
            if(ans.num[i] < 0)
            {
                borrow=1;
                ans.num[i] += 10;
            }else borrow = 0;
            //printf("num[i]=%d , borrow=%d\n" ,ans.num[i] ,borrow);
        }
        ans.sig = sig;
        ans.len = pmax->len;
        for(int i = ans.len-1 ; i > 0; i--)
            if(ans.num[i] == 0)
                ans.len--;
            else break;
    }
}
