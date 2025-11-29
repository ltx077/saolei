#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct area{
	bool b,t1,t2;
	string s;
	int u[2];
};
area p[32][32],a;
int e,sum;
string l;
void f1(){
	cout<<"\n\033[37m";
	cout<<"\t                  1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3"<<endl;//???
	cout<<"\t1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n"<<endl;
	for(int i=1;i<=30;i++){
		cout<<i<<"\t";
		for(int j=1;j<=30;j++){
			cout<<"\033[37m"<<p[i][j].s<<" ";
		}
		cout<<endl;
	}
}
void f2(){
	cout<<"\n\033[37m";
	cout<<"\t                  1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3"<<endl;
	cout<<"\t1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n"<<endl;
	for(int i=1;i<=30;i++){
		cout<<i<<"\t";
		for(int j=1;j<=30;j++){
			if(p[i][j].b==1)
				cout<<"\033[31m"<<p[i][j].s<<" \033[37m";
			else if(p[i][j].b==0)
				cout<<p[i][j].s<<" \033[37m";
		}
		cout<<endl;
	}
	cout<<"\033[37m";
}
char Test(int a,int b){
	int x;
	if(a!=1&&b!=1&&a!=30&&b!=30){
		x=p[a-1][b-1].b+p[a-1][b].b+p[a-1][b+1].b+p[a][b-1].b+p[a][b+1].b+p[a+1][b-1].b+p[a+1][b].b+p[a+1][b+1].b;
	}else if(a==1&&b!=1&&b!=30){
		x=p[a][b-1].b+p[a][b+1].b+p[a+1][b-1].b+p[a+1][b].b+p[a+1][b+1].b;
	}else if(a==30&&b!=1&&b!=30){
		x=p[a-1][b-1].b+p[a-1][b].b+p[a-1][b+1].b+p[a][b-1].b+p[a][b+1].b;
	}else if(b==1&&a!=1&&a!=30){
		x=p[a-1][b].b+p[a+1][b].b+p[a-1][b+1].b+p[a][b+1].b+p[a+1][b+1].b;
	}else if(b==30&&a!=1&&a!=30){
		x=p[a-1][b-1].b+p[a][b-1].b+p[a+1][b-1].b+p[a-1][b].b+p[a+1][b].b;
	}else if(a==1&&b==1){
		x=p[a][b+1].b+p[a+1][b].b+p[a+1][b+1].b;
	}else if(a==1&&b==30){
		x=p[a][b-1].b+p[a+1][b-1].b+p[a+1][b].b;
	}else if(a==30&&b==1){
		x=p[a-1][b].b+p[a-1][b+1].b+p[a][b+1].b;
	}else if(a==30&&b==30){
		x=p[a-1][b-1].b+p[a-1][b].b+p[a][b-1].b;
	}
	char num=x+48;
	return num;
}
string Looks(string w){
	if(w=="0")
		w="\033[37m0";
	else if(w=="1")
		w="\033[34m1";
	else if(w=="2")
		w="\033[32m2";
	else if(w=="3")
		w="\033[33m3";
	else if(w=="4")
		w="\033[31m4";
	else if(w=="5")
		w="\033[31m5";
	else if(w=="6")
		w="\033[31m6";
	else if(w=="7")
		w="\033[31m7";
	else if(w=="8")
		w="\033[31m8";
	return w;
}
int main(){
	cout<<"\033[32m扫雷游戏\n"<<endl;
	Sleep(2000);
	cout<<"您将要探索一片危险的地雷区"<<endl;
	Sleep(2000);
	cout<<"地雷区按行和列分成许多区域"<<endl;
	Sleep(2000);
	cout<<"游戏目标：破坏所有安全区域"<<endl;
	Sleep(2000);
	cout<<"您可以指定地雷数量(<900)\033[37m"<<endl;
	cin>>e;
	sum=900-e;
	cout<<"\n\033[32m祝您好运......"<<endl;
	Sleep(4000); 
	cout<<"\n\033[31m生成地图中......\n\033[37m"<<endl;
	Sleep(2000);
	for(int i=1;i<=30;i++){
		for(int j=1;j<=30;j++){
			p[i][j].b=0;
			p[i][j].t1=0;
			p[i][j].s="X";
			p[i][j].u[1]=i;
			p[i][j].u[2]=j;
		}
	}
	srand(time(0));
	while(e>0){
		int m=rand()%30+1;
		int n=rand()%30+1;
		if(p[m][n].b!=1){
			p[m][n].b=1;
			p[m][n].t1=0;
			e-=1;
		} 
	}
	f1();
	Sleep(2000);
	cout<<"\n\033[31m地雷示意图(作弊可用)"<<endl;
	Sleep(2000);
	f2();
	cout<<"\n地雷标注为红色."<<endl;
	Sleep(2000);
	cout<<"\n\033[32m指令：";
	Sleep(2000);
	cout<<"\n\033[32mg：破坏指定区域，若为安全，则会显示周围的地雷数量.";
	cout<<"\n\033[32mr：标记指定区域，被标记的区域将会显示为黄色.";
	cout<<"\n\033[32me：退出游戏."<<endl;
	Sleep(2000);
	cout<<"\n\033[31m游戏开始!\n"<<endl;
	Sleep(2000);
	f1();
	int m,n;
	char c;
	while(1){
		for(int i=1;i<=30;i++){
			for(int j=1;j<=30;j++){
				if(sum==0){
					cout<<"\n\033[31m你赢了！\033[37m"<<endl;
				}
				if(p[i][j].b==1&&p[i][j].t1==1)
					sum-=1;
			}
		}
		cout<<endl;
		m=0,n=0;
		cout<<"\033[31m操作指令：\033[37m"; 
		cin>>c;
		if(c=='e'){
			exit(0);
		}
		if(c=='g'){
			cin>>m>>n;
			if(p[m][n].b==0){
				int j=1;
				for(int i=0;n-i>=1;i++){
					if(p[m][n-i].t2==0&&p[m][n-i].b==0){
						a=p[m][n-i];
						l=Test(a.u[1],a.u[2]);
						a.s=Looks(l);
						a.t1=1;
						a.t2=1;
					}else{
						break;
					}
					do{
						if(p[m-j][n-i].t2==1)
							continue;
						if(p[m-j][n-i].t2==0&&p[m-j][n-i].b==0){
							a=p[m-j][n-i];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;n-i>=1;i++){
					do{
						if(p[m+j][n-i].t2==1)
							continue;
						if(p[m+j][n-i].t2==0&&p[m+j][n-i].b==0){
							a=p[m+j][n-i];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;n+i<=30;i++){
					if(p[m][n+i].t2==0&&p[m][n+i].b==0){
						a=p[m][n+i];
						l=Test(a.u[1],a.u[2]);
						a.s=Looks(l);
						a.t1=1;
						a.t2=1;
					}else{
						break;
					}
					do{
						if(p[m-j][n+i].t2==1)
							continue;
						if(p[m-j][n+i].t2==0&&p[m-j][n+i].b==0){
							a=p[m-j][n+i];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;n+i<=30;i++){
					do{
						if(p[m+j][n+i].t2==1)
							continue;
						if(p[m+j][n+i].t2==0&&p[m+j][n+i].b==0){
							a=p[m+j][n+i];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;m-i>=1;i++){
					if(p[m-i][n].t2==0&&p[m-i][n].b==0){
						a=p[m-i][n];
						l=Test(a.u[1],a.u[2]);
						a.s=Looks(l);
						a.t1=1;
						a.t2=1;
					}else{
						break;
					}
					do{
						if(p[m-i][n-j].t2==1)
							continue;
						if(p[m-i][n-j].t2==0&&p[m-i][n-j].b==0){
							a=p[m-i][n-j];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;m-i>=1;i++){
					do{
						if(p[m-i][n+j].t2==1)
							continue;
						if(p[m-i][n+j].t2==0&&p[m-i][n+j].b==0){
							a=p[m-i][n+j];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;m+i<=30;i++){
					if(p[m+i][n].t2==0&&p[m+i][n].b==0){
						a=p[m+i][n];
						l=Test(a.u[1],a.u[2]);
						a.s=Looks(l);
						a.t1=1;
						a.t2=1;
					}else{
						break;
					}
					do{
						if(p[m+i][n-j].t2==1)
							continue;
						if(p[m+i][n-j].t2==0&&p[m+i][n-j].b==0){
							a=p[m+i][n-j];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				j=1;
				for(int i=1;n+i<=30;i++){
					do{
						if(p[m+i][n+j].t2==1)
							continue;
						if(p[m+i][n+j].t2==0&&p[m+i][n+j].b==0){
							a=p[m+i][n+j];
							l=Test(a.u[1],a.u[2]);
							a.s=Looks(l);
							a.t1=1;
							a.t2=1;
							j++;
						}else{
							break;
						}
					}while(l=="0");
				}
				f1(); 
			}else{
				cout<<"\n\n\033[31m地雷爆炸了！\033[37m"<<endl;
				p[m][n].s="\033[34m!";
				break;
			}
		}
		if(c=='r'){
			cin>>m>>n;
			p[m][n].s="\033[33mX";
			Sleep(2000);
			f1();
		}
	}
	Sleep(2000);
	cout<<endl;
	f2();
	Sleep(4000);
	cout<<"\n\033[31mGame over.\033[37m"<<endl;
	Sleep(4000);
	return 0;
}
