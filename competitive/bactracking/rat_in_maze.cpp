// needs debugging
// solved XD 

#include<bits/stdc++.h>
using namespace std;
int maze[20][20];
int helpermaze[20][20];
int n;

bool left_movement_possible(int maze[][20],int row,int column){
	if(column<0) return false;
	if(helpermaze[row][column]==1) return false;
	if(maze[row][column]==0) return false;
	return true;
}


bool right_movement_possible(int maze[][20],int row, int column){
	if(column>=n) return false;
	if(helpermaze[row][column]==1) return false;
	if(maze[row][column]==0) return false;
	return true;
}

bool upper_movement_possible(int maze[][20],int row,int column){
	if(row<0) return false;
	if(helpermaze[row][column]==1) return false;
	if(maze[row][column]==0) return false;
	return true;
}

bool down_movement_possible(int maze[][20],int row,int column){
	if(row>=n) return false;
	if(helpermaze[row][column]==1) return false;
	if(maze[row][column]==0)  return false;
	return true;
}

void helper_rat(int maze[][20],int row,int column){
	if(row==n-1 && column == n-1){
		//cout<<"row is :"<<row<<endl;
		//cout<<"column is : "<<column<<endl;
		 //cout<<" last element : "<<helpermaze[row][column]<<endl; 
		 //cout<<" n is :" << n<<endl;
		 //cout<<"helpermaze[1][1] is :"<<helpermaze[1][1]<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<helpermaze[i][j]<<" ";
			}
		}

		cout<<endl;
		return;
	}
	helpermaze[row][column]=1;
	// if control comes here it means we are in a middle position
	// if left movement is possible i am going to break that problem after moving to left
	if(left_movement_possible(maze,row,column-1)){
		
		helpermaze[row][column-1]=1;
		helper_rat(maze,row,column-1);
		helpermaze[row][column-1]=0;
	}
	// if right movement is possible i am going to break that problem after moving to right
	if(right_movement_possible(maze,row,column+1)){
		//cout<<"right movement happening : row,column are :"<<row<<" "<<column<<endl;
		helpermaze[row][column+1]=1;
		//cout<<" this row "<<row<<" and column are passed to helper_rat "<<column<<endl;
		helper_rat(maze,row,column+1);
		helpermaze[row][column+1]=0;
	}
	// if down movement is possible i am going to break that problem in small after moving down
	if(down_movement_possible(maze,row+1,column)){
		//cout<<"down movement happening : row,column are :"<<row<<" "<<column<<endl;
		helpermaze[row+1][column]=1;
		//cout<<" this row "<<row+1<<" and column are passed to helper_rat"<<column<<endl;
		helper_rat(maze,row+1,column);
		helpermaze[row+1][column]=0;
	}
	// if upper movement is possible i am going to break that problem in small after moving up
	if(upper_movement_possible(maze,row-1,column)){
		helpermaze[row-1][column]=1;
		helper_rat(maze,row-1,column);
		helpermaze[row-1][column]=0;
	}
	helpermaze[row][column]=0;
return ;

}



void ratInAMaze(int maze[][20], int n){
memset(helpermaze,0,n*n*sizeof(int));
helpermaze[0][0]=1;
//helpermaze[n-1][n-1]=1;
helper_rat(maze,0,0);

}

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}

ratInAMaze(maze,n);

	return 0;
}