#include<bits/stdc++.h>
#define inf 99999
#define v 31
using namespace std;

class node{//details of a person
      public:
            string name,password;
            int cash;
};
class details{//class details to entry the data 
      string repassword;
      node person[500];
      int otp,count,index;
//      fstream fin;
   //   transport t;
public:
      details(){
            count=0;          
            for(int i=0;i<500;i++){
                  person[i].cash=0;
            }
      }
      void genotp(){
            otp=rand()%9999;
            cout<<otp<<endl;
      }
      //----------------login ------------------------------
      bool login(){
    	      cout<<"enter the choice:\n 1.log in\n2. sign in\n";
    	      int x;
    	      cin>>x;
    	    //  read();
    	      switch(x){
    	            case 1:cout<<"enter the name: ";
    	                  cin>>person[count].name;
    	                  cout<<"enter the password: ";
    	                  cin>>person[count].password;
    	                  cout<<"re-enter the password: ";
    	                  cin>>repassword;
    	                  if(repassword!=person[count].password){
    	                        cout<<"Password are not same. "<<endl;
    	                        return false;
    	                  }
    	                  genotp();
    	                  cout<<"enter the otp: ";
    	                  int y;
    	                  cin>>y;
    	                  if(otp!=y){
    	                        cout<<"entered otp is wrong. "<<endl;
    	                        return false;
    	                  }
    	                  system("clear");
    	                  cout<<"enter the cash you want to deposit: "<<endl;
    	                  cin>>person[count].cash;
    	                  index=count;
    	             //     write();
    	                  count++;
    	                  break;
                  case 2:cout<<"enter the name: ";
                        string name,pass;
                        cin>>name;
                        cout<<"enter the password: ";
                        cin>>pass;
                   //     read();
                        index=check(name,pass);
                        if(index!=0){
                              return true;
                        }else{
                              cout<<"Wrong password."<<endl;
                              return false;
                        }
                        break;
    	      }
    	}
    	//---------------check if username exits------------------------
    	int check(string s,string pass){
    	      for(int i=0;i<count;i++){
    	            if(person[i].name==s && person[i].password==pass){
    	                  return i;    	            
    	            }      
    	      }
    	      return 0;
    	}
    	//----------------------addcash----------------
      void addcash(){
            cout<<"enter the cash to be added: ";
            int x;
            cin>>x;
            person[index].cash+=x;
      }
    	//--------------------updatecash------------------------
    	void updatecash(int x){
    	      person[index].cash-=x;
    	   //   write();
    	}
    	//-------------------------update password----------------------
    	void updatepassword(){
            string pass;
            cout<<"enter the new password: ";
            cin>>pass;
            person[index].password=pass;
         //   write();    	
    	}
    	
    	
    	void printperson(){
    	for(int i=0;i<count;i++){
          	      cout<<person[i].name<<" "<<person[i].password<<" "<<person[i].cash<<endl;
    	      }
    	}
    	
    	
    	//--------------writefile--------------------------------------------------------------
  /*  	void write(){
    	      fin.open("data.txt",ios::trunc|ios::in|ios::out);
    	      for(int i=0;i<=count;i++)
                  fin<<person[i].name<<" "<<person[i].password<<" "<<person[i].cash<<endl;
            fin.close();      
    	}
//    	--------------read file-----------------------------------------------
    	void read(){
    	      fin.open("data.txt",ios::in|ios::out);
    	      string name,pass;
    	      int cash;
    	      int i=0;
    	      while(fin){
          	      fin>>name>>pass>>cash;
          	      person[i].name=name;
          	      person[i].password=pass;
          	      person[i].cash=cash;
          	      i++;
    	      }
    	      count=i;
    	      fin.close();
    	      for(int i=0;i<count;i++){
          	      cout<<person[i].name<<" "<<person[i].password<<" "<<person[i].cash<<endl;
    	      }
    	}*/
    	//friend class ------------------------------------------
    	friend class transport;          
};
class transport{
      int map[v][v],dist[v][v],path[v][v],parent[v],cost[v];
      int src,dest,emg,km;
      details d;
public:
      void func(){
                  readfile("matrix.txt");
                  warshall();
                  shortestpath();    
    	}
    	void menu(){   	  
          	      if(d.login()){
                       update(); 
          	      }
          	  
    	}
    	//--------------------functions to perform---------------------
    	void update(){
    	      system("clear");
    	      while(1){
          	      cout<<"enter the choice: 1.edit password\n2. add cash\n3. travel\n4. logout\n5. show all users"<<endl;
          	      int x;
          	      cin>>x;
          	      switch(x){
          	            case 1:d.updatepassword();
          	                  break;
          	            case 2:d.addcash();
          	                  break;
          	            case 3:travel();
          	                  break;
          	            case 4:return;
          	                   break;
          	            case 5:d.printperson();             
    	            }
    	      }
    	}
    	
    	//------------------------travel func-----------------------
    	void travel(){
    	     func();
    	     if(d.person[d.index].cash<0){
    	            cout<<"Insufficient balance.Please entercash in your account: "<<endl;
    	            d.addcash();
    	            return;
    	     }       
    	     cout<<"enter the emergency level (0/1/2): ";
    	     cin>>emg;
    	     int kmcost;
    	     if(km<=3){
    	            if(emg==0){
    	                  cout<<"Bicycle is the best option for you to travel."<<endl;
    	                  kmcost=km*10;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	            }      
    	            else if(emg==1){
    	                  cout<<"Bike is the best option for you to travel."<<endl;
    	                  kmcost=20*km;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	            }      
    	            else if(emg==2){
    	                  cout<<"Car is the best option for you to travel."<<endl;
    	                  kmcost=30*km;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	            }      
    	     }else if(km>3 && km <=20){
    	            if(emg==0){
    	                  cout<<"Bike is the best option for you to travel."<<endl;
    	                  kmcost=20*km;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	            }      
    	            else if (emg>=1){
    	                  cout<<"Car is the best option for you to travel."<<endl;
    	                  kmcost=30*km;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	            }      
    	     }else {
    	                  cout<<"Car is the best option for you to travel."<<endl;
    	                  kmcost=30*km;
    	                  d.updatecash(kmcost);
    	                  cout<<"Total cost: "<<kmcost<<endl;
    	     } 
    	}
      transport(){
            emg=0;
           for(int i=0;i<v;i++){
                  for(int j=0;j<v;j++){
                        if(i==j){
                              map[i][j]=0;
                              continue;
                        }
                        map[i][j]=inf;
                  }
            }
            for(int i=0;i<v;i++){
                  for(int j=0;j<v;j++)
                        path[i][j]=0;
            }
      }
      void print(){
            for(int i=0;i<v;i++){
                  for(int j=0;j<v;j++){
                        if(dist[i][j]==inf)
                              cout<<"inf ";
                        else      
                              cout<<dist[i][j]<<" ";
                  }
                  cout<<endl;
            }
            cout<<endl;
      }
      void readfile(string s){
            ifstream f;
            f.open(s);
            if(!f){
                  cout<<"File cannot be opened.."<<endl;
                  return;
            }
            int x,i,j;
            while(!f.eof()){
                 f>>i>>j>>x;
                 map[i][j]=map[j][i]=x;             
            }
            f.close();
            copy();
        //    print();
         //   printpathmatrix();
      }
      void copy(){
            for(int i=0;i<v;i++)
                  for(int j=0;j<v;j++)
                        dist[i][j]=map[i][j]; 
            for(int i=0;i<v;i++)
                  for(int j=0;j<v;j++)
                        if(map[i][j]!=inf)
                              path[i][j]=map[i][j];
      }
      int minimum(int a,int b){
            return a<b?a:b;
      }
      //-----------------------------------------------------warshall------------------------------------------
      void warshall(){
            int i,j,k;
            for (k = 0; k < v; k++){ // Pick all vertices as source one by one 
                  for (i = 0; i < v; i++) { // Pick all vertices as destination for the above picked source 
                        for (j = 0; j < v; j++){ // If vertex k is on the shortest path from i to j, then update the value of dist[i][j] 
				      if (dist[i][k] + dist[k][j] < dist[i][j]) 
					      dist[i][j] = dist[i][k] + dist[k][j]; 
			      } 
		      } 
	      }
           // print();
      } //---------------------path-----------------------------   
      int min_distance(bool visited[])
    	{
       		int min = 99999, min_index;
       		for (int i = 0; i < v; i++)
       		{
         		if (visited[i] == false && cost[i] <= min)
             		{
             			min = cost[i];
             			min_index = i;
             		}
             	}
        	if(cost[dest]==min)
            		min_index=dest;
       		return min_index;
    	}
    	//function to find shortest path
      void shortestpath()
    	{
    	      system("clear");
    	      int src,dest;
            cout<<"enter the source: ";
            cin>>src;
            cout<<"enter the destination: ";
            cin>>dest;
         	bool visited[v];
         	for (int i = 0; i < v; i++)
         	{
                  parent[i] = -1;
                	cost[i] = 99999;
                	visited[i] = false;
         	}
         	cost[src] = 0;
         	for (int i = 0; i < v; i++)
         	{
           		int u = min_distance(visited);
           		visited[u] = true;
           		
           		for (int V = 0; V < v; V++)
           		{	
               			if (!visited[V] && path[u][V]!=0  && cost[u]+path[u][V] < cost[V])
               			{
                   			cost[V] = cost[u] + path[u][V];
                   			parent[V] = u;
               			}
 			}
             		if(u==dest)
                		break;
         	}
         	printPath(dest);
         	km=dist[src][dest]*2;
         	cout<<"\nDistance of path is: "<<km<<endl;
    	}
    	//function to print path matrix
    	void printPath(int j)
    	{
        	if (parent[j] == - 1)
        	{
       			cout<<" - > "<<j;
       			return;
        	}	
        	printPath(parent[j]);
       		cout<<" - > "<<j;
    	}  
    	void printpathmatrix(){
    	      for(int i=0;i<v;i++){
    	            for(int j=0;j<v;j++){
    	                  cout<<path[i][j]<<" ";
    	            }
    	            cout<<endl;
            }           
    	}
    	
   	friend class details;
};

int main(){
      transport t;
      while(true){
            system("clear");
            t.menu();
            cout<<"Press 1 to exit: ";
            int x;
            cin>>x;
            if(x==1)
                  break;      
      }

 return 0;
}
