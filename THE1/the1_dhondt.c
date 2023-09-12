
#include <stdio.h>
    
int main(){

int party, deputy, i, k, j, index, maxs;
float maxq;
float votes[26];
char parties[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int seats[26] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
float quotinents[26];

scanf("%d %d", &party, &deputy);

for(i=0; i<party; i++){
    scanf(" %f", &votes[i]);
}

for(k=0; k<deputy; k++){

    for(i=0; i<party; i++){
        quotinents[i] = votes[i]/seats[i];
    }

    maxq = quotinents[0];
    index = 0;

    for (j=1; j<party; j++){
            if (quotinents[j] > maxq){
                maxq = quotinents[j];
                index = j;
            }
            if (quotinents[j] == maxq){
                if (votes[j] > votes[index]){
                    maxq = quotinents[j];
                    index = j;
                }
            }
    }

    seats[index] += 1;
    
}

for(i=0; i<party; i++){
    maxs = seats[0];
    index = 0;
    for(j=1; j<party; j++){
        if (seats[j] > maxs){
                    maxs = seats[j];
                    index = j;
        }
    }   
    if (maxs != 1){
        printf("%c: %d\n",parties[index],maxs-1);
    }
        seats[index] = 0;

}

    return 0;
}