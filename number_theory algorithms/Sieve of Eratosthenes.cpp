int countPrimes(int n)
{
int p[n+1]={0};
int c=0;
for(int i=2;i*i<=n;i++)//O(nlog(log(n)))
{
if(p[i]==0)
{
for(int j=2*i;j<=n;j+=i)
{
p[j]=1;
}
}
}
for(int i=2;i<n;i++)
{
if(p[i]==0)
{
c++;
}
}
return c;
}