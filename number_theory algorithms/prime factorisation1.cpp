class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	   vector<int>primef;
	 for(int i=2;i*i<=n;i++) //O(root N)
	 {
	  while(n%i==0)
	  {
	   primef.push_back(i);
	   n=n/i;
	  }
	 }
	 if(n>1)
	 {
	  primef.push_back(n);
	 }
	 return primef;
	}
};