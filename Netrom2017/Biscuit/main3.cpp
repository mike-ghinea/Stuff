static int A[16][16],a,b,r,*p,q;
    string j="Jucatorul   mutare ";
    j[10] = g3+'A';
    if(!g1++)
        memset(A,0,1024),a = b =  0;
    r=d%2;
    p=&A[l=l*2+3+!r*d-!r][c=c*2+3+r*(2-d)];
    if(a+b<25)
        if(l<3|l>13|c<3|c>13|*p)
            cout<<j+"invalida\n";
        else
            *p = 1,
            p-=17,
            q=r?-15:15,
            (g3?b:a) += r = (*(p+q) & *p & *(p+17+q)) + (*(p+34-q) & *(p+17-q) & *(p+34)),
            g3 ^= !r,
            cout<<j+"valida ("<<a<<':'<<b<<")\n";

    if(a+b>24)
        cout<<"Jocul s-a terminat\n";
