   class Solution{
	public:
vector<int>AllPrimeFactors(int n) {
int p[n+1]={0};
int hp[n+1]={0};
vector<int>v;
for(int i=2;i*i<=n;i++)
{
if(p[i]==0)
{
hp[i]=i;
for(int j=2*i;j<=n;j+=i)
{
p[j]=1;
hp[j]=i;
}
}
}
while(n>1)
{
int pf=hp[n];
while(n%pf==0)//O(logn)
{
n/=pf;
v.push_back(pf);
}
}
return v;

	}
};