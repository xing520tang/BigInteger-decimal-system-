#ifndef BIGINTEGER_H_INCLUDED
#define BIGINTEGER_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;
#define NUM_LEN 2050

typedef struct BI
{
    char num[NUM_LEN];
    int len;//��������ֵλ����
    bool sig;//����
}BigInt ,*pBigInt;

void add(const BigInt &a ,const BigInt &b ,BigInt &ans);
void sub(const BigInt &a ,const BigInt &b ,BigInt &ans);
void mul(const BigInt &a ,const BigInt &b ,BigInt &ans);
void div(const BigInt &A ,const BigInt &B ,BigInt &shang ,BigInt &yushu);
void mod(const BigInt &a , const BigInt &b ,BigInt &ans);
void gcd(const BigInt &a ,const BigInt &b ,BigInt &ans);
void pow_mod(const BigInt &A ,const BigInt &B ,const BigInt &M ,BigInt &ans);
void inverse(const BigInt &a ,const BigInt &b ,BigInt &ans);
bool Miller_Rabin(const BigInt n);//���n�Ƿ�Ϊ����������miller��rabin���Լ�⣩

bool is_zero(const BigInt &a);
void ten_to_bi(const char *s ,BigInt &p);
void print(BigInt &p);//��ӡ������
int compare(const BigInt &a ,const BigInt &b);//a��b�����Ƚϴ�С
void fuzhi0(BigInt &a);//��a��ֵΪ0
void fuzhi1(BigInt &a);//��a��ֵλ1

#endif // BIGINTEGER_H_INCLUDED
