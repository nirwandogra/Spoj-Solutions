#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //generatetests(1000);
    freopen("in.txt","r",stdin);
#endif
    int T,n;
    cin>>T;
    for (int j=0; j<T; j++)
    {
        double ansdist,anst,xx,yy,zz,vxx,vyy,vzz,den,time,x,y,z,vx,vy,vz;
        xx=0;
        yy=0;
        zz=0;
        vxx=0;
        vyy=0;
        vzz=0;
        {
            cin>>n;
            for (int i=0; i<n; i++)
            {
                cin>>x>>y>>z>>vx>>vy>>vz;
                xx+=x;
                yy+=y;
                zz+=z;
                vxx+=vx;
                vyy+=vy;
                vzz+=vz;
            }
            xx=xx/n;
            yy=yy/n;
            zz=zz/n;
            vxx=vxx/n;
            vyy=vyy/n;
            vzz=vzz/n;
            time=((xx*vxx)+(yy*vyy)+(zz*vzz));
            den=(vxx*vxx)+(vyy*vyy)+(vzz*vzz);
            if(den< 1e-09)
            {
                anst=0;
                ansdist=sqrt(xx*xx + yy*yy + zz*zz);;
            }
            else
            {
                anst=time/den;
                anst=anst*(-1);
                if(anst<0)
                {
                    anst=0;
                    ansdist=sqrt(pow(xx+(vxx*anst),2) +pow((yy+(vyy*anst)),2)+pow((zz+(vzz*anst)),2));;
                }
                else
                {
                    ansdist=sqrt(pow(xx+(vxx*anst),2) +pow((yy+(vyy*anst)),2)+pow((zz+(vzz*anst)),2));;
                }
            }
            cout << "Case #" << (j+1) << ": ";
            printf("%0.6lf %0.6lf\n",ansdist,anst);
        }
    }
}

