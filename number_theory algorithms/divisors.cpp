vector<int> printDivisors(int n) {
vector<int>v;
for(int i=1;i*i<=n;i++)//O(root N)
{
if(n%i==0)
{
if(n/i!=i)
{
v.push_back(i);
int x=n/i;
v.push_back(x);
} else {
  v.push_back(i);
}
}
}
sort(v.begin(),v.end());
return v;
} 