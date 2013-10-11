#include<stdio.h>
#include<stdlib.h>

int compare_function(const void *a,const void *b) {
    return *(int *)a - *(int *)b;
}

void solver(){
    int N,K,res = 0,i,j;
    scanf("%d%d",&N,&K);
    int v[100000];
    for( i=0; i < N; i++){
      scanf("%d",&v[i]);
    }
    qsort(v,N,sizeof(int),compare_function);
    for(i=1; i < N; i++){
      if(v[i] - v[j] == K) { j++; res++; }
    }
    printf("%d\n",res);
}

int main() {
    solver();
    return 0;
}
