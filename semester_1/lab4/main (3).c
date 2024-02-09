#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RANDOM(int a, int b){
    return (rand()%(b))+a;
}

int main()
{
    int a,i;
    int count =0;
    int sum=0;
    int max=0;
    int m[40];
    {/*
        long int ltime;
        int stime, b,c;
        ltime=time(NULL);
        stime=(unsigned) ltime/2;
        srand(stime);
        scanf("%d %d",&b,&c);
        for (i=0; i<40; i++){
            *(m+i)=RANDOM(b,c);
            printf("%d   %d\n", i, *(m+i));
        }*/
    }
    for (i=0; i<40; i++){
        scanf("%d", &m[i]);
    }
    scanf("%d", &a);
    for (i=0; i<40; i++){
        if(m[i]>a) {
            count++;
            sum+=m[i];
        }
    }
    float k=(float)sum/(float)count;
    count=0;
    sum=1;
    int fl=1;
    for(i=0; i<40; i++){
        if(m[i]<k) {
            count++;
            if(fl || m[i]>max){
                max=m[i];
                sum=1;
                fl=0;
            }
            else if(m[i]==max){
                sum++;
            }
        }
    }
    printf("%.4f\n", k);
    printf("%d\n", count);
    printf("%d %d\n", max, sum);

    return 0;
}
