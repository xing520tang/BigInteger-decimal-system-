#include"BigInteger.h"
int compare(const BigInt &a ,const BigInt &b)//a>b,return 1; a=b,return 0; a<b,return -1;
{
    if(a.sig != b.sig)
    {
        if(a.sig)
            return 1;
        else return -1;
    }else {//����λ��ͬ
        int maxlen ,pmax;
        maxlen = a.len>b.len ? a.len : b.len;
        if(a.len == b.len)
        {
            pmax = 0;//��ʾa�ľ���ֵ����b�ľ���ֵ
            for(int i = a.len-1 ; i >= 0; i--)
            {
                if(a.num[i] > b.num[i])
                {
                    pmax = 1;//a����ֵλ����b
                    break;
                }
                else if(a.num[i] < b.num[i])
                {
                    pmax = -1;//a����ֵλС��b
                    break;
                }
            }
            if(! pmax)
                return 0;//a=b
            if(a.sig)//��a��b�ķ��Ŷ�Ϊ��
                return pmax;
            return -pmax;
        }else {
            if(a.len > b.len)
            {
                if(a.sig)
                    return 1;
                return -1;
            }else {
                if(a.sig)
                    return -1;
                return 1;
            }
        }
    }
}
