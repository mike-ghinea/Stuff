#include <stdio.h>
int n, v[100003], best[100003], p[100003], maxim, k, L[100003], nr;

void afis(int i)
{
    if (p[i] > 0)  afis(p[i]);
    printf("%d ",v[i]);
}

int caut(int x)
{
    int p, u, m;
    p = 0;
    u = nr;
    m = (p+u)/2;
    while (p <= u)
    {
        if (v[L[m]] < x &&  v[L[m+1]] >= x)
            return m;
        else if (v[L[m+1]] < x)
        {
            p = m + 1;
            m = (p + u)/2;
        }
        else
        {
            u = m - 1;
            m = (p + u)/2;
        }
    }
    return nr;
}

int main()
{
    freopen("scmax.in","r",stdin);
    freopen("scmax.out","w",stdout);
    int i, j, poz;
    nr = 1;

    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d", v + i);
    best[1] = L[1] = 1;
    L[0] =  0;

    for (i = 2; i <= n; i++)
    {
        poz = caut(v[i]);
        p[i] = L[poz];
        best[i] = poz + 1;
        L[poz + 1] = i;
        if (nr < poz + 1)   nr = poz + 1;
    }
    maxim = 0;
    poz = 0;
    for (i = 1; i <= n; i++)
        if (maxim < best[i])
        {
            maxim = best[i];
            poz = i;
        }
    printf("%d\n",maxim);
    afis(poz);
    return 0;
}
