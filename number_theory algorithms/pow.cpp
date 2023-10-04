int binexp(int a,int b,long long m)
{
if(b==0)
{
return 1;
}
int x=binexp(a,b/2,m);//O(logb)
if(b%2==1)
{
return ((x%m*x%m)%m*a)%m;
}
else
{
return (x%m*x%m)%m;
}
}
int power(int a, int b){
return binexp(a,b,1e9+7);
}