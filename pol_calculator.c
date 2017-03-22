//

//only ‘+’and‘-’ come true

#include<stdio.h>
struct body{
    double number,index;
    struct body * next;
};

int main()
{
    struct body *Start=NULL,*now=NULL;
    double n,m;
    printf("Input the first number and index(if number =0 ,end)\n");
    while(scanf("%lf",&n)!=EOF&&n!=0){
        scanf("%lf",&m);
        struct body *a=(struct body*)malloc(sizeof(struct body));
        a->number=n,a->index=m,a->next=NULL;
        if(Start==NULL){
            Start=a;
            now=Start;
        }
        else{
            now->next=a;
            now=now->next;
        }
    }
    printf("Input the second number and index(if number =0 ,end)\n");
    while(scanf("%lf",&n)!=EOF&&n!=0){
        scanf("%lf",&m);
        struct body *l, *r;
        l=r=Start;
        struct body *a=(body*)malloc(sizeof(body));
                a->number=n,a->index=m,a->next=NULL;
        while(r!=NULL){
            if(r->index==m){
                r->number+=n;
                break;
            }
            else if(r->index<m){

                if(r==Start){
                    Start=a;
                    a->next=r;
                }
                else{
                    l->next=a;
                    a->next=r;
                }
                break;
            }
            else if(r->index>m){
                if(r->next==NULL){
                    r->next=a;break;
                }
                l=r;
                r=r->next;
            }
        }
    }
    struct body *h=Start;
    while(h!=NULL){
        if(h->number>0&&h!=Start)
            printf("+");
        if(h->index==0)
            printf("%.1f",h->number);
        else{
            printf("%.1f",h->number);printf("x\^");printf("%.1f",h->index);
        }
        h=h->next;
    }
    return 0;
}
/*
test:

Input the first number and index(if number =0 ,end)
5 3
-2 1
0
Input the second number and index(if number =0 ,end)
6 6
-5 5
-2 3
2 2
1 1
10 0
0
6.0x^6.0-5.0x^5.0+3.0x^3.0+2.0x^2.0-1.0x^1.0+10.0
*/
