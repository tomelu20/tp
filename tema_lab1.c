#include <stdio.h>

int main(void)
{
    int i,j,n,m,p,v=1,a[20][20],b,ok=0,c,i1,i2,v1[20]= {},v2[20]= {},min=999999999,k,a1[20][20],a2[20][20];
    scanf("%d",&n);
    scanf("%d",&m);
    //pb8.3
    /**for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            {
                *(*(a+i)+j)=v;
                v++;
                printf("%d ", *(*(a+i)+j));
            }
        printf("\n");
    }*/

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d",&a1[i][j]);
        }
    }

    for (i=0; i<m; i++)
    {
        for (j=0; j<m; j++)
        {
            scanf("%d",&a2[i][j]);
        }
    }

    //pb8.4
    /**for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i<j)
            {
                c=a[i][j];
                b=a[j][i];
                a[i][j]=b;
                a[j][i]=c;
            }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    */
    //pb8.5
    /**for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            *(v1+j)=*(v1+j)+(*(*(a+i)+j));
        }
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
                *(v2+j)=*(v2+j)+(*(*(a+j)+i));
        }
    }
    for (i=0; i<n; i++)
    {
        printf("%d ",*(v1+i));
    }
    printf("\n");
    for (i=0; i<n; i++)
    {
        printf("%d ",*(v2+i));
    }
    printf("\n");*/

    //pb8.6
    /**for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (a[i][j]==1 && i!=j)
                v1[i]++;
        }
    }
    for (i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    */

    //pb8.7
    /**for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if(i!=j)
            {
                if (a[i][j]<min)
                    min=a[i][j];
            }
        }
    }
    printf("%d",min);
    printf("\n");
    */
    //pb8.9
    /**
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i==j)
                a[i][j]=1;
            else
                a[i][j]=0;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    //pb8.10
    /**
    for (i=0; i<n; i++)
    {
        k=1;
        for (j=0; j<3; j++)
        {
            if (a[i][j]<a[i][j+1])
                k=0;
        }
        if (k=0)
            printf("%d ",i);
    }
    printf("\n");
    */
    //pb8.1
    /**for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (a1[i][j]==a2[i][j])
            {
                for (i1=i; i1<m+i; i1++)
                {
                    for (i2=j; i2<m+j; i2++)
                        if (a2[i1][i2]!=a1[i1][i2])
                    {
                        ok=1;
                        break;
                    }
                }
                if (ok==0)
                {
                    printf("(%d",i);
                    printf(",%d",j);
                    printf(") ");
                }
            }
        }
    }
    */
    return 0;
}
