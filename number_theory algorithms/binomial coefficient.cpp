        #include<bits/stdc++.h>
        typedef long long ll;
        #define cin(arr,n) for(long long i=0;i<n;i++){cin>>arr[i];}
        #define vl vector<long long>
        #define vs vector<string>
        #define vc vector<char>
        #define pb push_back
        using namespace std;
        #define vps vector<pair<long long,string>>
        #define vp vector<pair<long long,long long>>
        const int m=1e9+7;
        const int N=1e6+1;
        vector<ll>f(N);
        ll binexp(ll a,ll b,ll m1)
        {
        if(b==0)
        {
        return 1;
        }
        ll x=binexp(a,b/2,m1);
        if(b%2==1)
        {
        return (a*((x%m1*x%m1)%m1))%m1;
        }
        else
        {
        return (x%m1*x%m1)%m1;
        }
        }
        
        
        void solve()
        {
        ll a,b;
        cin>>a>>b;
        f[0]=f[1]=1;
         for(ll i=2;i<=1e6;i++)
        {
        f[i]=(f[i-1]*i)%m;
        }
        ll p=binexp(f[b],m-2,m);
        ll q=binexp(f[a-b],m-2,m);
        ll r=(f[a]*((p*q)%m))%m;
        cout<<r<<endl;
        }
        int main()
        {
        solve();
        }