#include <stdio.h>

double calculate_pressure_on_block(int row, int column, double block_weight);
void printer(int firstr,int firstc,int row, int column,double weight);


double calculate_pressure_on_block(int row, int column, double block_weight){

if (row == 0){return 0.00000000; }
else if (column == 0){
    return block_weight/2 + 15*calculate_pressure_on_block(row-1 , 0, block_weight)/100;
}
else if (row == column){
    return block_weight/2 + 15*calculate_pressure_on_block(row-1 , column-1, block_weight)/100;
}
else{
    return block_weight + 15*calculate_pressure_on_block(row-1 , column-1, block_weight)/100 + 15*calculate_pressure_on_block(row-1 , column, block_weight)/100 ;
}

}

void printer(int firstr,int firstc,int row, int column,double weight){

    printf("(%d,%d) %.8f\n",firstr,firstc,calculate_pressure_on_block(firstr,firstc,weight));

    if (firstr == row && firstc == column){return;}

    else if (firstr == firstc && firstr+1 <= row){
        printer(firstr+1, 0, row, column, weight);
    }
    else{
        printer(firstr, firstc+1, row, column, weight);
    }
}

int main(){
    
    int layers;
    double weight;
    
    scanf("%d %lf", &layers, &weight);
    printer(0,0,layers-1,layers-1,weight);
    
    return 0;
}