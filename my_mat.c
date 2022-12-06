#include <stdio.h>
#include <math.h>
#include "my_mat.h"

int mat [size_mat][size_mat]; 

void get_matrix_values (){
	for (int row= 0; row<size_mat; row++){
		for(int col= 0; col<size_mat; col++){
			scanf("%d", &mat[row][col]);
		}
	}

	//make the shortest path matrix
	floyd_warshall_algorithm();
}

int is_there_path (int i, int j){
	if (mat[i][j] == 0){
		return 0;
	}
	return 1;
}

int shortest_path (int i, int j){
	if (mat[i][j] == 0){
		return -1;
	}
	return mat[i][j];
} 

void floyd_warshall_algorithm (){
	for (int k=0; k < size_mat; k++){
		for (int row= 0; row<size_mat; row++){
			for(int col= 0; col<size_mat; col++){
				//the main diagonal is always 0
				if(row != col){
					//chek another path only if the edges (row,k) and (k,col) are exist
					if(mat[row][k] != 0 && mat[k][col] != 0){
						//calc the path from row to col by k
						int sum_of_path_by_k = mat[row][k] + mat[k][col];
						//there isn't a path from row to col without k, so - calc the path with k anyway
						if(mat[row][col]== 0){
							mat[row][col] = sum_of_path_by_k;
						}
						else //mat[row][k] != 0 && mat[k][col] != 0 && mat[row][col] != 0
							mat[row][col] = min(mat[row][col], sum_of_path_by_k);
					}
				}
			}
		}
	}
}

//return the minimum value between two integer numbers
int min (int firstNum, int secondNum){
	if (firstNum < secondNum){
		return firstNum;
	}
	return secondNum;
}



 
