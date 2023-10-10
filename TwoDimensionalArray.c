#include<stdio.h>
#include <stdlib.h>
#include<math.h>

void quicksort(int number[], int first, int last){
int pivot, i, j, temp;
if(first < last){
    pivot = first;
    i=first;
    j=last;
    while(i < j){
        while(number[i] <= number[pivot] && i < last)
            i++;
            while(number[j] > number[pivot])
            j--;
            if(i < j){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
    }
    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    quicksort(number, first, j-1);
    quicksort(number, j+1, last);
}
}

int main(){


    int n,m;
    printf("insert the size of the matrix in n rows and m columns:");
    scanf("%d%d",&n,&m);


    int matrix[n][m];
    int x,y;

    printf("enter the elements of the matrix:");
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            scanf("%d", &matrix[x][y]);
        }
    }

    int k = n*m;
    int a[k];

    int f = 0;
        for(x = 0; x < n; x++){
            for(y = 0; y < m; y++){
            a[f] = matrix[x][y];
            f = f + 1;
        }
    }

    quicksort(a, 0, k-1);


    int digits;
    if (a[k-1] > 1000){
        digits = 4;
    }else if(a[k-1] > 100){
        digits = 3;
    }else if(a[k-1] > 10){
        digits = 2;
    }else{
        digits = 1;
    }

    int nl = 0;
    int nr = n - 1;
    int ml = 0;
    int mr = m - 1;
    int o = 0;
printf("\n\n");
    while (o < k){

        for (x = nr; x >= nl; x--){
            matrix[x][mr] = a[o];
            o = o + 1;
        }
        if(o >= k){break;};
               mr = mr - 1;
        for (y = mr; y >= ml; y--){
            matrix[nl][y] = a[o];
            o = o + 1;
        }
        if(o >= k){break;};
                    nl = nl + 1;
        for (x = nl; x <= nr; x++){
            matrix[x][ml] = a[o];
            o = o + 1;
        }
        if(o >= k){break;};
                    ml = ml + 1;
        for (y = ml; y <= mr; y++){
            matrix[nr][y] = a[o];
            o = o + 1;
        }
            nr = nr - 1;


    }





    printf(" \n \n");


            printf("here is the array after it has been sorted \n");
    for(x = 0; x < n; x++){
        for(y = 0; y < m; y++){
            printf(" %0*d", digits, matrix[x][y]);
        }
        printf("\n");
    }

return 0;
}
