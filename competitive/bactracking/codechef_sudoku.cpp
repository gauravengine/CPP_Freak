#include<bits/stdc++.h>
using namespace std;
#define N 9  
bool cool_in_row(int grid[][N],int row,int i){
	for(int j=0;j<N;j++){
		if(grid[row][j]==i)
		{
			return false;
		}
	}
	return true;
}

bool cool_in_column(int grid[][N],int column,int i){
	for(int j=0;j<N;j++){
		if(grid[j][column]==i){
			return false;
		}
	}
	return true;
}
bool cool_in_smallgrid(int grid[][N],int row,int column,int i){
	int row_factor=row-(row%3);
	int column_factor=column-(column%3);
	for(int k=row_factor;k<row_factor+3;k++){
		for(int j=column_factor;j<column_factor+3;j++){
			if(grid[k][j]==i){
				return false;
			}
		}
	}
	return true;
}



bool smart_guess(int grid[][N],int row,int column,int i){
	if( cool_in_row(grid,row,i) &&cool_in_column(grid,column,i) &&cool_in_smallgrid(grid,row,column,i)   )
 	{return true; }
 	else
 		return false;
}
bool find_next_pos(int grid[N][N],int &row,int &column){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j]==0){
				row=i;
				column=j;
				return true;
			}
		}
	}
	return false;
}

bool solveSudoku(int grid[N][N]){
	int row,column;
	if(!find_next_pos(grid,row,column)){
		return true;
	}

	for(int i=1;i<=N;i++){
		if(smart_guess(grid,row,column,i)){
			grid[row][column]=i;
			if(solveSudoku(grid)){
				return true;
			}
			/*else{
				grid[row][column]=0;
			}*/
			else grid[row][column]=0;


			}

		}
		
	return false;		
		
}



int main(){
int grid[N][N];


for(int i=0;i<N;i++){
	string s;
	cin>>s;
	for(int j=0;j<s.length();j++){
		grid[i][j]=s[j]-'0';
	}
}
cout<<solveSudoku(grid)<<endl;
// now printing 
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
		cout<<grid[i][j];
	}
	cout<<endl;
}




	return 0;
}