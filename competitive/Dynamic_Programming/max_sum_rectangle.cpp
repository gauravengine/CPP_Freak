#include<iostream>
#include<climits>
using namespace std;
int main(){

	int row,column;
	cin>>row>>column;
	int** grid= new int*[row];
	for(int i=0;i<row;i++){
		grid[i]= new int[column];
		for(int j=0;j<column;j++){
			cin>>grid[i][j];
		}
	}
	// taken all inputs;
	// now calculating sum from each element
	int ** sum_matrix= new int*[row];
	for(int i=0;i<row;i++){
		sum_matrix[i]= new int[column];
		for(int j=0;j<column;j++){
			 sum_matrix[i][j]=0;
			for(int x=i;x<row;x++){
				for(int y=j;y<column;y++){
					sum_matrix[i][j] += grid[x][y];
				}
			}
		}
	}
	// cout<<"i am here"; no prob till here
	cout<<endl;
	/*
	for(int i=0;i<row;i++){
		
		for(int j=0;j<column;j++){
			cout<<sum_matrix[i][j]<<" ";
		}
		cout<<endl;
	}    */ // working fine
 

// sum_matrix done !
// calculate area of all rectangles 
	int max=INT_MIN;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			// cout<<"i : "<<i<<" j : "<<j<<endl;

			for(int x=i;x<row;x++){
				for(int y=j;y<column;y++){
					int curr_sum ;//= sum_matrix[i][j] ; //- sum_matrix[x][y+1]-sum_matrix[x+1][y]+ sum_matrix[x+1][y+1]; // here this little shit is accessing extra memory
					if(x+1<row && y+1<column){
						curr_sum =sum_matrix[i][j]- sum_matrix[i][y+1]-sum_matrix[x+1][j]+ sum_matrix[x+1][y+1];
					}
					else if (x+1>=row && y+1<column)
					{	//cout<<"in 2 else if"<<endl;
						curr_sum=sum_matrix[i][j] -sum_matrix[i][y+1];
					}
					else if(y+1>=column && x+1<row){
						curr_sum=sum_matrix[i][j] - sum_matrix[x+1][j];
					}
					
					else
						curr_sum = sum_matrix[i][j] ; 
				//	cout<<" x+1 "<<x+1<< " y+1 "<<y+1<<endl;

					//cout<<"i am here too"<<endl;

					if(max < curr_sum) {
						max= curr_sum;
					}
					//cout<<max<<endl;
				}
			}



		}
	}

	cout<<max<<endl;


	return 0;
}