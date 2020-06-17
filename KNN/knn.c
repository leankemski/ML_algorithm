/*
knn��c����ʵ��
knn����Ҫѵ��ģ�ͣ��������ģ��
author: Lean
version: 0.1
last edit: 2020.06.17
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 4000
#define N 100

//����һ���ַ��Ľṹ��
typedef struct
{
    char c;
    int array[16];
    float distance;
}letter;

letter mletters[M];
letter nletters[N];
float t;

void Get_from_mletters()
{
    FILE *fp;
    int i,j;
    fp = fopen("letter.txt", "r");
    for(i=0; i<M; i++)
    {
        fscanf(fp, "%c ", &mletters[i].c);
        for(j=0; j<16; j++)
            fscanf(fp, "%d ", &mletters[i].array[j]);
    }
    fclose(fp);
}

void Get_from_nletters()
{
    FILE *fp;
    int i,j;
    fp = fopen("sum.txt", "r");
    for(i=0; i<N; i++)
    {
        fscanf(fp, "%c ", &nletters[i].c);
        for(j=0; j<16; j++)
            fscanf(fp, "%d ", &nletters[i].array[j]);
    }
    fclose(fp);
}

void Distance(letter *p)
{
    int i,j;
    float s = 0;
    for(i=0; i<M; i++)
    {
        for(j=0; j<16; j++)
        {
            s += ((mletters[i].array[j]-(*p).array[j]) * (mletters[i].array[j]-(*p).array[j]));
        }
        mletters[i].distance = sqrt(s);
        s = 0;
    }
}

void Sort()
{
    int i,j;
    letter t;
    for(i=0; i<M; i++)
    {
        for(j=i+1; j<M; j++)
        {
            if(mletters[i].distance > mletters[j].distance)
            {
                t = mletters[i];
                mletters[i] = mletters[j];
                mletters[j] = t;
            }
        }
    }
}

char Knn(int k)
{
    int i,j,max;
    int array[26];
    for(i=0; i<26; i++)
    {
        array[i]=0;
    }

    for(i=0; i<k; i++)
    {
        switch(mletters[i].c)
        {
        case'A':
            array[0]++;
            break;
        case'B':
            array[1]++;
            break;
        case'C':
            array[2]++;
            break;
        case'D':
            array[3]++;
            break;
        case'E':
            array[4]++;
            break;
        case'F':
            array[5]++;
            break;
        case'G':
            array[6]++;
            break;
        case'H':
            array[7]++;
            break;
        case'I':
            array[8]++;
            break;
        case'J':
            array[9]++;
            break;
        case'K':
            array[10]++;
            break;
        case'L':
            array[11]++;
            break;
        case'M':
            array[12]++;
            break;
        case'N':
            array[13]++;
            break;
        case'O':
            array[14]++;
            break;
        case'P':
            array[15]++;
            break;
        case'Q':
            array[16]++;
            break;
        case'R':
            array[17]++;
            break;
        case'S':
            array[18]++;
            break;
        case'T':
            array[19]++;
            break;
        case'U':
            array[20]++;
            break;
        case'V':
            array[21]++;
            break;
        case'W':
            array[22]++;
            break;
        case'X':
            array[23]++;
            break;
        case'Y':
            array[24]++;
            break;
        case'Z':
            array[25]++;
            break;
        default:
            break;
        }
    }

    max=array[0];
    j=0;
    for(i=0; i<26; i++)
    {
        if(array[i]>max)
        {
            max=array[i];
            j=i;
        }
    }
    return (char)(j+65);
}

int main()
{
    int i, j, k=0;
    int m=0, n=0;
    letter *p;
    char c;
    printf("ѵ������Ϊ%d\n",M);
    Get_from_mletters();
    printf("��������Ϊ%d\n",N);
    Get_from_nletters();
    printf("������Kֵ��\n");
    scanf("%d",&k);
    for(i=0; i<N; i++)
    {
        p = &nletters[i];
        Distance(p);
        Sort();;
        c = Knn(k);
        if(nletters[i].c == c)
        {
            printf("���ַ�����%c��,ʶ����ȷ\n",nletters[i].c);
            m++;
        }
        else
        {
            printf("���ַ�����%c�࣬ʶ�����\n",nletters[i].c);
            n++;
        }
        //printf("%f", mletters[0].distance);
    }
    printf("��ȷ����Ϊ%d",m);
    printf("�������Ϊ%d",n);
    printf("��ȷ��Ϊ%f",(float)(m)/N);
    return 0;
}