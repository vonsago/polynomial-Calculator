#include<stdio.h>
struct body{
    double number;
    int index;
    struct body * next;
};
body * oper_add(body *Start,double n,int m){
    struct body *l, *r;
    l=r=Start;
    struct body *a=(body*)malloc(sizeof(body));
    a->number=n,a->index=m,a->next=NULL;
    if(r==NULL){
        return a;
    }
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
    return Start;
}
int main()
{
    struct body *Start=NULL,*now=NULL;
    char oper;
    double n;int m;
    printf("Input the first number and index(if number =0 ,end)\n");
    while(scanf("%lf",&n)!=EOF&&n!=0){
        scanf("%d",&m);
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
    printf("Input the operator:\n");
    cin>>oper;
    printf("Input the second number and index(if number =0 ,end)\n");

    //operator "+"||"-"
    if(oper=='+'||oper=='-'){
        while(scanf("%lf",&n)!=EOF&&n!=0){
            scanf("%d",&m);
            if(oper=='-') n=0-n;
            Start = oper_add(Start,n,m);
        }
        struct body *h=Start;
        while(h!=NULL){
            if(h->number>0&&h!=Start)
                printf("+");
            if(h->number==0)
                ;
            else if(h->index==0)
                printf("%.1f",h->number);
            else{
                printf("%.1f",h->number);printf("x\^");printf("%d",h->index);
            }
            h=h->next;
        }
    }
    else if(oper=='*'||oper=='/'){
        struct body *ansStart=NULL,*ansnow;
        while(scanf("%lf",&n)!=EOF&&n!=0){
            scanf("%d",&m);
            //operator: "*"
            struct body *h=Start;
            while(h!=NULL){
                struct body* g=(body*)malloc(sizeof(body));
                if(oper=='*'){
                    g->number=n*h->number;g->index=m+h->index;g->next=NULL;}
                else{
                    g->number=h->number/n;g->index=h->index-m;g->next=NULL;}
                ansStart=oper_add(ansStart,g->number,g->index);
                h=h->next;
            }
            if(oper=='/' ) break;
        }
        struct body *h=ansStart;
        while(h!=NULL){
            if(h->number>0&&h!=ansStart)
                printf("+");
            if(h->number==0)
                ;
            else if(h->index==0)
                printf("%.1f",h->number);
            else{
                printf("%.1f",h->number);printf("x\^");printf("%d",h->index);
            }
            h=h->next;
        }
    }
    return 0;
}


/*
//test1:

Input the first number and index(if number =0 ,end)
5 3
-2 1
0
Input the operator:
+
Input the second number and index(if number =0 ,end)
6 6
-5 5
-2 3
2 2
1 1
10 0
0
6.0x^6.0-5.0x^5.0+3.0x^3.0+2.0x^2.0-1.0x^1.0+10.0

//test2:

Input the first number and index(if number =0 ,end)
5 3
-2 1
0
Input the operator:
-
Input the second number and index(if number =0 ,end)
6 6
-5 5
-2 3
2 2
1 1
10 0
0
-6.0x^6+5.0x^5+7.0x^3-2.0x^2-3.0x^1-10.0

//test3:

Input the first number and index(if number =0 ,end)
5 4 2 2 0
Input the operator:
*
Input the second number and index(if number =0 ,end)
3 3 1 1 0
15.0x^7+11.0x^5+2.0x^3

//test 4:
Input the first number and index(if number =0 ,end)
5 4 -2 3 2 2 1 0 0
Input the operator:
/
Input the second number and index(if number =0 ,end)
2 1
2.5x^3-1.0x^2+1.0x^1+0.5x^-1

*/