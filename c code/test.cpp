#include <iostream>
#include <algorithm>
using namespace std;
struct station{
    double price,dis;                //每个加油站的价格与起点距离
}s[510];
bool cmp(station a,station b){
    return a.dis<b.dis;             //将加油站按距离从小到大排序
}
const long long MIN=100000000;

int main(){
    int n;double cmax,distance,davg;  //除了加油站个数外其他数据都可能不是整数，用浮点型
    cin>>cmax>>distance>>davg>>n;
    for(int i=0;i<n;i++)
        cin>>s[i].price>>s[i].dis;
    sort(s,s+n,cmp);
    s[n].price=0;
    s[n].dis=distance;  //设置一个终点站

    if(s[0].dis!=0) printf("The maximum travel distance = 0.00\n");  //起点没有加油站，无法出发
    else{
        int now=0;
        double max=cmax*davg,sum=0,nowc=0;  //now为当前加油站编号，max为一箱油能跑多远，sum为累积油钱，nowc为当前油箱油量
        while(now<n){
            int k=-1;double minprice=MIN;   //k为最低油价的加油站编号
            for(int i=now+1;i<=n&&s[i].dis-s[now].dis<=max;i++){  //选择从当前加油站出发能到达的范围内第一个低于当前油价的加油站，没有的话就选范围内最低的一个
                if(s[i].price<minprice){
                    minprice=s[i].price;
                    k=i;
                    if(minprice<s[now].price) break;  //找到第一个低于当前油价的加油站，直接退出循环
                }
            }
            if(k==-1) break;  //范围内没有加油站
            double need=(s[k].dis-s[now].dis)/davg;  //need为从当前出发到达目标加油站所需油量
            if(minprice<s[now].price){    //若目标加油站油钱低于当前加油站
                if(need>nowc){            //若当前油量不够直接跑到目标加油站
                    sum+=(need-nowc)*s[now].price;
                    nowc=0;                        //加到可到目标加油站的油量，到达后油箱刚好用完
                }
                else
                    nowc-=need;                   //若当前油量超过所需油量，不加油直接跑到下个加油站
            }
            else{
                sum+=(cmax-nowc)*s[now].price;    //若目标加油站油价高于当前加油站，则在当前油站先加满油更划算
                nowc=cmax-need;
            }
            now=k;  //到达目标油站，更新当前油站编号
        }
        if(now==n) printf("%.2f\n",sum);  //能到终点，输出总油钱
        else printf("The maximum travel distance = %.2f\n",s[now].dis+max);  //不能到达终点，输出最远距离
    }
    return 0;
}
        
