#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int MAX_LEN =20005 ;
int seg_tree[MAX_LEN << 2];
int Lazy[MAX_LEN << 2];
int arr[MAX_LEN];
void push_up (int root) 
{
    seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //��Сֵ��min
}
//�������¸��£����Һ���
void push_down (int root, int L, int R) 
{
    if(Lazy[root])
	{
        Lazy[root << 1] += Lazy [root];
        Lazy[root << 1 | 1] += Lazy[root];
        int mid = (L + R) >> 1;
        seg_tree[root << 1] +=  Lazy[root] * (mid - L + 1);
        seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
        Lazy[root] = 0;
    }
}
//����
//[L,R]���Ƕ�Ӧarr�����������
void build (int root, int L, int R) 
{
    Lazy[root] = 0;
    if(L == R) 
	{
        seg_tree[root] = arr[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(root << 1, L, mid);
    build(root << 1 | 1, mid + 1, R);
    push_up(root);
}

//�����ѯ
//��������[LL,RR]�����/Сֵ
int query (int root, int L, int R, int LL, int RR) 
{
    if (LL <= L && R <= RR) 
	 return seg_tree[root];
    push_down(root, L, R);     //ÿ�η��ʶ�ȥ���Lazy ���
    int Ans = 0;
    int mid = (L + R) >> 1;
    if(LL <= mid) 
	 Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //��Сֵ��min
    if(RR > mid) 
	 Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //��Сֵ��min
    return Ans;
}
//�����޸� +-ĳֵ
//ʹ������[LL,RR]��ֵ������val
void update_Interval(int root, int L, int R, int LL, int RR, int val){
     if (LL <= L && R <= RR) 
	 {
         Lazy[root] += val;
         seg_tree[root] += val * (R - L + 1);
        return ;
     }
     push_down(root, L, R);
     int mid = (L + R) >> 1;
     if (LL <= mid) update_Interval(root << 1, L, mid, LL, RR, val);
     if (RR > mid) update_Interval(root << 1 | 1, mid + 1, R, LL , RR, val);
     push_up(root);
}
//�����޸� ���Ը�Ϊĳֵ������+-ĳֵ
//��posλ�õ�ֵ�ĳ�val
void update(int root, int L, int R, int pos, int val) 
{
    if(L == R)
	{
        seg_tree[root] = val;    //��ֱ�ӱ�Ϊĳֵ
        return ;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) update(root << 1, L, mid, pos, val);
    else update(root << 1 | 1, mid + 1, R, pos, val);
    push_up(root);
}
signed main()
{
	int t;
	jiasu;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
	    for(int i=1;i<=n;++i)
	     cin>>arr[i];
	    build(1,1,n);
	    int sum[MAX_LEN]={0};
	    int ans=0;
	    for(int i=1;i<=n-k;i++)
	    {
	    	if(sum[i]==0)
	    	{
		    	int pos=query(1,1,n,i,i+k);
		    	ans+=pos;
				for(int j=max((int)1,k-pos);j<=k+pos;j++)
				 sum[j]++;
				int pos1=query(1,1,n,i,pos-1),pos2=query(1,1,n,pos+1,i+k);
				if(seg_)	
			}
	    	else if(sum[i]==1)
	    	{
	    		
			}
	    	
		}
	} 
    
    return 0;
}
