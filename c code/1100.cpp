#include <stdio.h>
int gcd(int a,int b){
    if(a<b)
        return gcd(b,a);
    else if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main(){
    int n,i,count;
    while(scanf("%d",&n)!=EOF){
        count=0;
        for(i=1;i<=n;i++){
            if(gcd(n,i)==1)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
