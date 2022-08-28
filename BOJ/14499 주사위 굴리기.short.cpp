#include<cstdio>
struct p14499_short
{
int n,m,x,y,k,i,g[400],q[2][4],p[2],d[8]{0,0,-1,1,1,-1,0,0},o,u,v,*a,*b;int main(){scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);for(i=0;i<n*m;++i)scanf("%d",&g[i]);while(k--){scanf("%d",&o);--o;u=x+d[o];v=y+d[o+4];if(u>=0&&v>=0&&u<n&&v<m){x=u;y=v;u=(o/2+1)%2;v=o/2;a=q[u],b=q[v];int&e=p[u],&w=p[v];if(o==0||o==3)e=(e+1)%4;else e=(e-1+4)%4;i=x*m+y;if(g[i]==0)g[i]=a[e];else{a[e]=g[i];g[i]=0;}b[w]=a[e];b[(w+2)%4]=a[(e+2)%4];printf("%d\n",a[(e+2)%4]);}}}
};