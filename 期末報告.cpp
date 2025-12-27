#include<iostream>
#include<conio.h>
#include<cstdlib> 
#include<unistd.h>
using namespace std;
int main(){
	int n,p;
	char key;
	int time = 0,counttime = 0;
	int rem[101],needed[11];
	cout<<"啟動程式"<<endl;
	cout<<endl;	
	sleep(3);
	cout<<"啟動中";
	for(int dasb = 0;dasb < 10 ; dasb++){
		cout<<".";
		sleep(1);
	} 
	cout<<"100%"<<endl;
	cout<<endl;
	sleep(3);
	cout<<"介面開啟" << endl;
	for(int dasb = 0;dasb < 5; dasb++){
		cout<<endl;
	} 
	do{
	
	cout<<"目前剩餘抽獎資源:%admin_lost%(離線模式)"<<endl;
	cout<<"請選擇內容:"<<endl;
	cout<<"按   1 "<<"10連抽"<<endl;
	cout<<"按   2 "<<"查詢歷史紀錄"<<endl;
	cout<<"按 ESC "<<"關閉視窗"<<endl;
	cout<<"*提醒，記得按esc關閉否則無法再開*"<<endl; 
	cout<<endl;
	
	//get key
	key = getch() ;
	time++;
	if(key !=27 && key !=49 && key !=50){
	if(time <= 3){cout<<"錯誤按鍵，2秒後再嘗試"<<endl;
	cout<<endl;
	cout<<endl;
	sleep(2);
	continue;
		} 
	else{
		cout<<"你來亂的，滾"<<endl;
		sleep(1);
		return 1; 
		}
	}
	
	//1
	if(key == 49){
		counttime +=10;
		int totalnum=0;
		
		cout<<"已消耗%admin_remove%的資源"<<endl;
		cout<<"抽取中";	
		
		srand(counttime);
		for(int load = 0;load <10;load++){
			int bruh = rand()%100;
			if(bruh == 0)bruh =100;
			needed[load]=bruh;
			totalnum +=bruh;
		}
		
		for(int dasb = 0;dasb < 5 ; dasb++){
		cout<<".";
		sleep(1);
	} 
		cout<<"抽取結果整理完畢,輸出中:"<<endl;
		for(int outp = 0;outp < 10;outp++)
		cout<<needed[outp] <<endl;
		cout<<endl;
		cout<<"總量為"<<totalnum;
		if(totalnum <= 250)cout<<"寄"<<endl;
		if(totalnum > 250 && totalnum <= 750)cout<<"還可接受"<<endl;
		if(totalnum > 750)cout<<"好運ㄟ" <<endl;
		
		//數據收納
		int loa =0;
		int remt = counttime;
		
			//大於平移 
		if(counttime >100){
			remt = 100;
			for(int move = 10;move < 100;move++){
				rem[move-10]=rem[move];	
			}
		}
		
			//收納 
			for(int i=remt-10;i< remt;i++){
			rem[i]=needed[loa];
			loa++;
			}
		}
	
	
	//2
	if(key == 50){
	while(1){
		cout<<"請輸入查詢區間:"<<endl;
		cin>>n>>p; 
		if(n > p)swap(n,p);
		if(n<=0 ||p>100){
		cout<<"輸入錯誤重新輸入"<<endl;
		continue; 
			}
		cout<<rem[n-1];
		for(int a = n+1;a<p+1;a++)
		cout<<","<<rem[a-1];
			
		cout<<endl;
		break;
		}  
	}
	
	//ESC
	if(key == 27)break;
	}while(key != 27);
	return 0;
}
