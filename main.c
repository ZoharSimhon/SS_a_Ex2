#include <stdio.h>
#include "my_mat.h"

int main(){
    
    char choise_function;
    int i,j;

    do
    {
        scanf("%c", &choise_function);
        if(choise_function == 'A'){
                get_matrix_values();
            }
            else if(choise_function == 'B'){
                scanf("%d %d", &i, &j);  
                int answer = is_there_path(i, j);
                if(answer == 0){
                    printf("False\n");
                }
                else
                printf("True\n");  
            }
            else if (choise_function == 'C'){
                scanf("%d%d \n", &i, &j);            
                int answer = shortest_path(i,j);
                printf("%d\n", answer);
            }    
    } while(choise_function != 'D');

    return 0;
}
