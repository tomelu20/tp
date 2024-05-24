#include <stdio.h>
int n;
int v[100];

int valid(int p)//daca e permutare
{
    int i;
    for (i=1;i<p;i++)
    {
        if (v[i]==v[p])
        {
            return 0;
        }
    }
    return 1;
}
int solutie(int p)
{
    int mijloc, i, j;
    if (p==n)
    {
        mijloc = n/2 + n%2;
        for (i=1;i<mijloc;i++)
        {
            for (j=i+1;j<=mijloc;j++)
            {
                if (v[i]<v[j])
                {
                    return 0;
                }
            }
        }
        for (i=mijloc;i<n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (v[i]>v[j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void back(int p)
{
    int i;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                afisare();
            }
            else
            {
                back(p+1);
            }
        }
    }
}


int main() {
    printf("Introduceti n ");
    scanf("%d", &n);

    back(1);

    return 0;
}
---------------------
//12.3
#include <stdio.h>

int nr,k,n;
int v[100];
int maxi=-999;
int cifre[20];

void pune_cifre(int nr)
{
    int aux;
    n=0;
    aux=nr;
    while(aux)
    {
        n++;
        aux=aux/10;
    }
    printf("n este %d \n",n);

    int i;
    aux=nr;
    for(i=0;i<n;i++)
    {

        cifre[n-i]=aux%10;
        aux=aux/10;
    }
}

int valid(int p)//daca e permutare
{
    int i;
    for (i=1;i<p;i++)
    {
        if (v[i]>=v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    int i;
    if(p==n-k)
    {
       return 1;
    }
    return 0;
}

int numar(void)
{
    int i, nou=0;
    for (i=1; i<=(n-k);i++)
    {
        nou = nou * 10 + cifre[v[i]];
    }
    return nou;
}

void afisare(void)
{
    int i;
    for (i=1;i<=k;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void back(int p)
{
    int i,aux;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                afisare();
                aux= numar();
                printf("nr %d\n",aux);
                if(aux>maxi)
                    maxi=aux;
            }
            else
            {
                back(p+1);
            }
        }
    }
}

int main() {
    printf("nr si k ");
    scanf("%d %d",&nr,&k);

    pune_cifre(nr);

    back(1);

    printf("maxi este %d \n",maxi);

    return 0;
}
----------------
//12.4
#include <stdio.h>
int n=3;
int v[10];
char culori[7][30] = {" ", "alb", "galben", "rosu", "verde", "albastru", "negru"};
//alb, galben, rosu, verde, albastru si negru.
//1    2       3     4       5           6

int valid(int p)
{
    for (int i = 1; i < p; ++i)
    {
        if (v[i] == v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    if(p==3)
    {
        if(v[2]==2 || v[2]==4)
            return 1;
        return 0;
    }
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d",v[i]);
        printf("%s ",culori[v[i]]);
    }
    printf("\n");
}

void back(int k)
{
    for(int i=1;i<=6;i++)
    {
     v[k]=i;
     if (valid(k))
        if(solutie(k))
            afisare();
        else
            back(k+1);
    }
}

int main(void)
{
    back(1);

}
------------
//12.5
#include <stdio.h>
int n,v[100];
float vvolum[100];
float volum;

int valid(int p)
{
    for (int i=1;i<p;++i)
    {
        if (v[i]==v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    int i;
    float suma=0.0;
    for(i=1;i<=p;i++)
        suma=suma+vvolum[v[i]];
    if(suma<=volum)
        return 1;
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d",vvolum[v[i]]);
    }
    printf("\n");
}

void back(int p)
{
    int i;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                afisare();
            }
            else
            {
                back(p+1);
            }
        }
    }
}
int main(void)
{
    printf("Introduceti n si volum cutie ");
    scanf("%d %.2f", &n, &volum);

    int i;
    for(i=1;i<=n;i++)
        scanf("%.2f",&vvolum[i]);

    back(1);
}
----------------
//12.6
#include <stdio.h>
int n;
int v[100];
int c,b,g,a;
char cladiri[5][30] = {" ", "case", "bloc", "gradina", "atelier"};
//casa bloc gradina atelier
//1    2       3     4

int valid(int p)
{
    if(p!=1)
    {
        if(v[p]==1)//casa
        {
            if(v[p-1]==1 || v[p-1]==2 || v[p-1]==3)
                return 1;
        }

        if(v[p]==2)//bloc
        {
            if(v[p-1]==1|| v[p-1]==2)
                return 1;
        }

        if(v[p]==3)//gradina
        {
            if(v[p-1]==1 || v[p-1]==4 || v[p-1]==3)
                return 1;
        }

        if(v[p]==4)//atelier
        {
            if(v[p-1]==3 || v[p-1]==4 )
                return 1;
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

int solutie(int p)
{
    int cntc=0;
    int cntb=0;
    int cntg=0;
    int cnta=0;
    if(p==n)
    {
        int i;
        for(i=1;i<=p;i++)
        {
            if(v[i]==1)
                cntc++;
            if(v[i]==2)
                cntb++;
            if(v[i]==3)
                cntg++;
            if(v[i]==4)
                cnta++;
        }
        if(cntc==c && cntb==b && cntg==g && cnta==a)
            return 1;
        else
            return 0;
    }
    return 0;
}

void afisare(void)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("%d",v[i]);
        printf("%s ",cladiri[v[i]]);
    }
    printf("\n");
}

void back(int k)
{
    if(k>n)
        return;

    for(int i=1;i<=4;i++)
    {
     v[k]=i;
     if (valid(k))
        if(solutie(k))
            afisare();
        else
            back(k+1);
    }
}

int main(void)
{
     printf("Introduceti c ");
    scanf("%d", &c);
     printf("Introduceti b ");
    scanf("%d", &b);
     printf("Introduceti g ");
    scanf("%d", &g);
     printf("Introduceti  a");
    scanf("%d", &a);

    n=c+b+g+a;

    back(1);

}
--------------
//12.7
#include <stdio.h>
int n,latura;
int v[100];
int laturi[100];

int valid(int p)//daca e permutare
{
    int i;
    for (i=1;i<p;i++)
    {
        if (v[i]==v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie(int p)
{
    int am=0,as=0,i;
    am=latura*latura;
    for(i=1;i<=p;i++)
        as=as+v[i]*v[i];
    if(as <= am && p==n)
        return 1;
    return 0;
}
int ok=0;
int back(int p)
{
    int i;
    for (i=1;i<=n;i++)
    {
        v[p]=i;
        if (valid(p))
        {
            if (solutie(p))
            {
                ok=1;
                return ok;
            }
            else
            {
                back(p+1);
            }
        }
    }
}


int main() {
    printf("Introduceti numarul de patrate si latura patratului mare: ");
    scanf("%d %d", &n, &latura);

    printf("Introduceti laturile patratelor mici:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &laturi[i]);
    }

    if (back(1)) {
        printf("Da, este posibil sa se aranjeze toate patratele in interiorul patratului mare.\n");
    } else {
        printf("Nu, nu este posibil sa se aranjeze toate patratele in interiorul patratului mare.\n");
    }

    return 0;
}
