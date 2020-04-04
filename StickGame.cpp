#include<bits/stdc++.h>
using namespace std;
int result=0;
int minmax(int n,int max){
	int x,i=0;
	if(max==1){
		x=0;
		if(n==1) return 0;
		if(n==2) return 1;
		for(i=n-1;i>=n-3&&i>=1;i--){
			x=minmax(i,0);
			if(x==1){
				result=(n-i);
				break;
			}
		}
		return x;
	}
	else {
		x =1;
		if(n==1) return 1;
		if(n==2) return 0;
		for(i=n-1;i>=n-3&&i>=1;i--){
			x=minmax(i,1);
			if(x==0){
				break;
			}
		}
		return x;
	}
}

int main(){
	srand(time(0));
	int t=1,y=0;
	while(t!=0){
		cout<<"select:\n1.single player.\n2.AI vs AI\n";
		cin>>y;
		int n=0,toss=0,turn=0,v=0;
		cout<<"select number of sticks:";
		cin>>n;
		if(y==1){
			toss=(rand()%2);
			if(toss) cout<<"you won the toss"<<endl;
			else cout<<"AI won the toss"<<endl;
			turn=toss;
			while(1){
				cout<<"Number of sticks left:"<<n<<endl;
				int v=0;
				if(turn){
					cout<<"select the number of sticks(1-3):";
					cin>>v;
					n=(n-v);
					turn=0;
				}
				else {
					result=0;
					minmax(n,1);
					if(result!=0){
						n=n-result;
						cout<<"AI picked "<<result<<" sticks\n";
					}
					else{
						cout<<"AI picked 1 stick\n";
						n--;
					}
					turn=1;
				}
				if(n==1){
					if(turn) cout<<"AI won\n"<<endl;
					else cout<<"You won"<<endl;
					cout<<"press 1 to play again 0 to exit:";
					cin>>t;
					break;
				}
			}
		}
		if(y==2){
			cout<<"AI VS AI"<<endl;
			toss=(rand()%2);
			turn=toss;
			while(1){
				cout<<"Number of sticks left: "<<n<<endl;
				if(turn==0){
					minmax(n,1);
					n=n-result;
					cout<<"AI"<<turn+1<<"picked "<<result<<" sticks"<<endl;
					turn=1;
				}
				else{
					minmax(n,1);
					n=n-result;
					cout<<"AI"<<turn+1<<"picked "<<result<<" sticks"<<endl;
					turn=0;
				}
				if(n==1){
					if(turn) cout<<"AI 1 won the game\n";
					else cout<<"AI 2 won the game\n";
					cout<<"press 1 to play again or zero to exit!:";
					cin>>t;
					break;
				}
			}	
		}
	}
	return 0;
}
