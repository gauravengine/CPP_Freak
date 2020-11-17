#include<bits/stdc++.h>
using namespace std;

struct collision{
	int p1;
	int p2;
	float time;
};
bool covid[6];
bool comparator(collision a, collision b){
	if(a.time != b.time) return a.time < b.time ;
	else{
		if(covid[a.p1]== true || covid[a.p2] == true ) return true; // jinhe pehle covid h 
		else return false;
	}

}

void print_data(collision data[] , int size){
	for(int i=0;i<size ;i++){
		cout<<" player 1 : " <<data[i].p1<<endl;
		cout<<" player 2 : " <<data[i].p2<<endl;
		cout<<"time they collided : "<<data[i].time<<endl;

	}


}

void print_collision_time(float **collision_time , int size){
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++){
			cout<<collision_time[i][j]<<"  ";
		}
		cout<<endl;
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--){
		int n; cin>>n;
		float *velocity= new float[n+1];
		for(int i=1;i<=n;i++){
			cin>>velocity[i];
		}
		

		int temp[n+1];   // to store values of final covid patients if ith runner had covid
		int positive_time=0;
		float** collision_time = new float*[n+1];
			for(int i=1;i<=n;i++){
				collision_time[i] = new float[n+1];
			}
			// filling collision times
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) collision_time[i][j]= 0;
					else if(i>j) continue;
					else{
						if(velocity[i] == velocity[j] ){
							collision_time[i][j] = -1;
							collision_time[j][i] = -1;	
						}
						else{
							collision_time[i][j]= ((float)j-(float)i)/(velocity[i]-velocity[j]) ;
							collision_time[j][i]= collision_time[i][j] ;
							if(collision_time[i][j] > 0) positive_time++;


						} 

					}



				}
			}  // collision times filled
			//print_collision_time(collision_time, n+1);

			collision data[positive_time];
			int data_pointer=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i>=j) continue;
					
					if(collision_time[i][j] > 0){
						data[data_pointer].p1= i;
						data[data_pointer].p2=j;
						data[data_pointer].time = collision_time[i][j];
						data_pointer++;
					}



				}
			}
			// data filled now sorting
			//sort(data,data+data_pointer,comparator); // will sort while calculating true bc there can be possibility of 3 or more collisions at same time and i can miss some positives so have to sort them like if any positive at that time it should be first in  data array 

		for(int i=1;i<=n;i++){
			
			
			
			
			for(int i=1;i<=n;i++){
				covid[i]= false;
			}

			covid[i]= true; 

			sort(data,data+data_pointer,comparator);
			
			// iterate on  asceding time and mark true and store in temp
			for(int j=0; j< positive_time;j++){
				if(covid[data[j].p1]== true || covid[data[j].p2] == true ){
					covid[data[j].p1]= true;
					covid[data[j].p2] = true;
				}


			}

			// marked all true now count and store in temp;
			int current_positive =0;
			for(int i=1 ;i<= n;i++){
				if(covid[i]) current_positive++;
			}

			temp[i]= current_positive;

			//print_data(data , data_pointer);	
			
		}
		// finding minimum and maximum in temp 

		int min= 5, max=1;
		for(int i=1;i<=n;i++){
			if(temp[i] > max) max= temp[i];
			if(temp[i] < min ) min = temp[i]; 
		}

		cout<<min<<" "<<max<<"\n";

	}

	return 0;
}