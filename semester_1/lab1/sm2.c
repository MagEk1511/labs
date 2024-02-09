#include <stdio.h>



int main(){
    int d, m, y;
    int last_count = 0;
    int last_countf = 0;

    scanf("%d %d %d", &d, &m, &y);
    
    // Обработка на uncorrect date


    if (d<1 || m<1 || y<1 || m>12)
    {
        printf("uncorrect date\n");
        return 0;
    }


    switch (m)
    {
    case 2:
        if (y<1582 && y%4==0)
        {
            if(d>29) {
            printf("uncorrect date\n");
            return 0;
            }
        }
        else if (y>1582 && ((y%4==0 && y%100 != 0) || (y%400==0)) )
        {
            if(d>29) {
            printf("uncorrect date\n");
            return 0;
            }
        }
        else
        {
            if (d>28) {
            printf("uncorrect date\n");
            return 0;
            }
        }
    


    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(d>31) {printf("uncorrect date\n");
            return 0;
            }
        break;
    
    default:
        if(d>30) {
            printf("uncorrect date\n");
            return 0;
            }
            // printf("-1");
        break;
    }

    if(y==1582 && m==10 && d>=5 && d<=14){
        printf("uncorrect date\n");
        return 0;
    }

    int counter = 0;

    if (y<=4)
    {
        counter+= (y-1)*365;

        
    }
    else if (y<=1581)
    {
        counter += (y-5.0)*365.25 + 4*365;
    }
    else if (y==1582)
    {
        counter += (y-5)*365.25 + 4*365;
        switch (m-1)
        {
        case 11:
            counter+=30;
        case 10:
            counter+=21;
        case 9:
            counter+=30;
        case 8:
            counter+=31;
        case 7:
            counter+=31;
        case 6:
            counter+=30;
        case 5:
            counter+=31;
        case 4:
            counter+=30;
        case 3:
            counter+=31;
        case 2:
            counter+=28;
        case 1:
            counter+=31;
            
        default:
            if (m==10 && d>4)
            {
                counter-=10;
            }
            
            counter+=d;
            break;
        }
        last_count = counter;
    }
    else if (y<=1584)
    {
        counter += 577814 + (y-1583)*365;
    }
    
    else
    {
        counter+=578545+(y-1584)*365.2425-365;
    }
    
    
    switch (m-1)
        {
        case 11:
            counter+=30;        
        case 10:
            counter+=31;
        case 9:
            counter+=30;
        case 8:
            counter+=31;
        case 7:
            counter+=31;
        case 6:
            counter+=30;
        case 5:
            counter+=31;
        case 4:
            counter+=30;
        case 3:
            counter+=31;
        case 2:
            counter+=28;
        case 1:
            counter+=31;
            
        
        default:
            counter+=d;
            break;
        }
    
    if (last_count == 0) {
        last_count = counter;
    }

    if (y>4 && y<1582 && y%4==0 && m>2)
    {
        counter+=1;
    }
    else if (y==1584 && m>2)
    {
        counter+=1;
    }
    else if (y>1584 && m>2 && ((y%4==0 && y%100!=0) || y%400==0))
    {
        counter+=1;
    }

    

    scanf("%d %d %d", &d, &m, &y);

    
    // Обработка на uncorrect date


    if (d<1 || m<1 || y<1 || m>12)
    {
        printf("uncorrect date\n");
        return 0;
    }


    switch (m)
    {
    case 2:
        if (y<1582 && y%4==0)
        {
            if(d>29) {
            printf("uncorrect date\n");
            return 0;
            }
        }
        else if (y>1582 && ((y%4==0 && y%100 != 0) || (y%400==0)) )
        {
            if(d>29) {
            printf("uncorrect date\n");
            return 0;
            }
        }
        else
        {
            if (d>28) {
            printf("uncorrect date\n");
            return 0;
            }
        }
    


    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(d>31) {printf("uncorrect date\n");
            return 0;
            }
        break;
    
    default:
        if(d>30) {
            printf("uncorrect date\n");
            return 0;
            }
            // printf("-1");
        break;
    }

    if(y==1582 && m==10 && d>=5 && d<=14){
        printf("uncorrect date\n");
        return 0;
    }

    counter = 0;

    if (y<=4)
    {
        counter+= (y-1)*365;

        
    }
    else if (y<=1581)
    {
        counter += (y-5.0)*365.25 + 4*365;
    }
    else if (y==1582)
    {
        counter += (y-5)*365.25 + 4*365;
        switch (m-1)
        {
        case 11:
            counter+=30;
        case 10:
            counter+=21;
        case 9:
            counter+=30;
        case 8:
            counter+=31;
        case 7:
            counter+=31;
        case 6:
            counter+=30;
        case 5:
            counter+=31;
        case 4:
            counter+=30;
        case 3:
            counter+=31;
        case 2:
            counter+=28;
        case 1:
            counter+=31;
            
        default:
            if (m==10 && d>4)
            {
                counter-=10;
            }
            
            counter+=d;
            break;
        }
        last_countf = counter;
    }
    else if (y<=1584)
    {
        counter += 577814 + (y-1583)*365;
    }
    
    else
    {
        counter+=578545+(y-1584)*365.2425-365;
    }
    
    
    switch (m-1)
        {
        case 11:
            counter+=30;        
        case 10:
            counter+=31;
        case 9:
            counter+=30;
        case 8:
            counter+=31;
        case 7:
            counter+=31;
        case 6:
            counter+=30;
        case 5:
            counter+=31;
        case 4:
            counter+=30;
        case 3:
            counter+=31;
        case 2:
            counter+=28;
        case 1:
            counter+=31;
            
        
        default:
            counter+=d;
            break;
        }
    
    if (last_countf == 0) {
        last_countf = counter;
    }

    if (y>4 && y<1582 && y%4==0 && m>2)
    {
        counter+=1;
    }
    else if (y==1584 && m>2)
    {
        counter+=1;
    }
    else if (y>1584 && m>2 && ((y%4==0 && y%100!=0) || y%400==0))
    {
        counter+=1;
    }
    printf("%d\n", last_countf - last_count + 1);
    return 0;
}
