#include<iostream>
#include<climits>
using namespace std;

int min_cost_2(int** grid,int ei,int ej){
	int** dp= new int*[ei+1];
	for (int i = 0; i < ei+1; ++i)
	{
		dp[i]= new int[ej+1];

	}
	dp[ei][ej]= grid[ei][ej];
	// initialializing last column
	for(int i=ei-1;i>=0;i--){
		dp[i][ej]= grid[i][ej] + dp[i+1][ej];
	}
	// intializing last row
	for(int j= ej-1;j>=0;j--){
		dp[ei][j]= grid[ei][j] + dp[ei][j+1];
	}
	for(int i= ei-1;i>=0;i--){
		for(int j=ej-1;j>=0;j--){
			int option_1= grid[i][j]+ dp[i][j+1]; // right wala
			int option_2= grid[i][j]+ dp[i+1][j+1]; //diagonaly next
			int option_3= grid[i][j]+ dp[i+1][j];   // bottom wala
			dp[i][j]= min(option_1,min(option_3,option_2));
		}
	}
	int ANS= dp[0][0];
	delete [] dp;
	return ANS;

}

int min_cost(int** grid,int si,int sj,int ei,int ej,int** min_cost_array){
	if(si==ei && sj== ej){
		min_cost_array[ei][ej]= grid[ei][ej];
		return grid[ei][ej];
	}

	if(si>ei || sj> ej){
		return INT_MAX;
	}

	if(min_cost_array[si][sj]>-1){
		return min_cost_array[si][sj];
	}

	int option_1= min_cost(grid,si,sj+1,ei,ej,min_cost_array);
	int option_3= min_cost(grid,si+1,sj+1,ei,ej,min_cost_array);
	int option_2= min_cost(grid,si+1,sj,ei,ej,min_cost_array);
	min_cost_array[si][sj] = grid[si][sj] + min(option_2,min(option_3,option_1));
	return grid[si][sj] + min(option_2,min(option_3,option_1));


}
int main(){
	int row,col;
	cin>>row>>col;
	int** grid= new int*[row];
	for(int i=0;i<row;i++){
		grid[i]= new int[col];
		for(int j=0;j<col;j++){
			cin>>grid[i][j];
		}
	}
	int** min_cost_array= new int*[row];
	for (int i = 0; i < row; ++i)
	{
		min_cost_array[i]= new int[col];
		for(int j=0;j<col;j++){
			min_cost_array[i][j]=-1;
		}
	}
	cout<<min_cost(grid,0,0,row-1,col-1,min_cost_array)<<endl;
	cout<<min_cost_2(grid,row-1,col-1);

	return 0;
}