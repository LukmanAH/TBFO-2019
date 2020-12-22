#include<iostream>
#include<stack>
using namespace std;
typedef struct type{
	char tanda;      //untuk menyimpan operator +,*,-,/
	float angka;	// untuk menyimpan nilai
};

int kiri(string x,int i,int y){     //Fungsi rekursiv untuk menelusuri satu per satu ke kiri operator dan mengubah karakter menjadi angka 
	if(x[i]>='0' && x[i]<='9'){
		return (x[i]-'0')*y+kiri(x,i-1,y*10);
	} else return 0;
}		

int kanan(string x,int i,int y){   //Fungsi rekursiv untuk menelusuri satu per satu ke kanan operator dan mengubah karakter menjadi angka
	while(x[i] <='9' && x[i]>='0') {
		i++;
	}	
	return kiri(x,i-1,y);
}

void bb(type data[],int i, float &b,int &x){  //rekursiv untuk menelusuri satu persatu ke kanan operator mencari nilai dan disimpan pada register b
	if(data[i+1].angka !=-999 ) {
		b=data[i+1].angka;
		x=i+1;
	}
	else bb(data,i+1,b,x);
}

void aa(type data[],int i, float&a,int &x){	//rekursiv untuk menelusuri satu persatu ke kiri operator mencari nilai dan disimpan pada register a
	if(data[i-1].angka !=-999 ) {
		a=data[i-1].angka;
		x=i-1;
	}
	else aa(data,i-1,a,x);
}

float cek(string x){  
	stack <char> S;    //Stack of char untuk menampung operator *,/,+,-
	float a,b;         // Register
	int jumOp=0, idx=0,  xx, yy;  //jumOp menghitung jumlah operator, idk menandai index array yg akan di isi, xx dan yy penampung index / i
	for(int i=x.length()-1; i>=0; i--) if(x[i]=='+'||x[i]=='-'||x[i]=='/'||x[i]=='*')	jumOp++;
	
	int Angka[jumOp+1]; //arrar of char menampung angka		
	for(int i=0; i<x.length(); i++){
		if(x[i]=='+'||x[i]=='-'||x[i]=='/'||x[i]=='*'){ //penelusuran mencari operator
			Angka[idx]=kiri(x,i-1,1);   //mengisi array dengan hasil penerusuran angka ke kiri operator
				idx+=1;			
		} 
		if(idx==jumOp) Angka[idx]=kanan(x,i+1,1);  //mengisi array dengan hasil penerusuran angka ke kiri operator
	}
	
	S.push('Z');  //isi awal stack;
	for(int i=x.length()-1; i>=0; i--) if(x[i]=='+'||x[i]=='-'||x[i]=='/'||x[i]=='*') 	S.push(x[i]); //mengisi stack dengan perator
	
	idx=0;
	type data[jumOp*2+1];  //array of struct menampung operator dan angka
	for(int i=0; i<jumOp*2+1; i++){
		if(i%2==0){
			data[i].angka=Angka[idx]; //menginputkan angka
			data[i].tanda='B';
			idx++;
		}else{
			data[i].angka=-999;
			data[i].tanda=S.top(); //menginputkan operator
			S.pop();
		}
	}


		//Touring Machine
		for(int i=0; i<jumOp*2+1; i++){
			if(data[i].tanda=='*' ||data[i].tanda=='/' ){ //penelusuran mencari '*' atau '/'
				aa(data,i,a,xx);						//	penelusuran ke kiri dari operator
				bb(data,i,b,yy);						//	penelusuran ke kanan dari operator
					if(data[i].tanda=='*') data[yy].angka*=data[xx].angka; //memproses nilai
					else  data[yy].angka=data[xx].angka/data[yy].angka;		//memproses nilai
					data[xx].angka=-999;	//menandai angka yang sudah diproses
					data[i].tanda='B';     //Menandai Operator yang sudah diproses
					S.pop();
				} 
			}
			
		
		for(int i=0; i<jumOp*2+1; i++){
			if(data[i].tanda=='+' ||data[i].tanda=='-' ){ //penelusuran mencari '+' atau '-'
				aa(data,i,a,xx);							//	penelusuran ke kiri dari operator
				bb(data,i,b,yy);							//	penelusuran ke kanan dari operator
					if(data[i].tanda=='+') data[yy].angka+=data[xx].angka; //memproses nilai
					else  data[yy].angka=data[xx].angka-data[yy].angka;    //memproses nilai
					data[xx].angka=-999;  	//menandai angka yang sudah diproses
					data[i].tanda='B';		 //Menandai Operator yang sudah diproses
					S.pop();
				} 
			}

	return data[jumOp*2].angka;  //mengembalikan nilai hasil pemrosesan touring machine 
}
