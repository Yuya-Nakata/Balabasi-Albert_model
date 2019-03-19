using namespace std;

void makelink(int d[t_num][t_num],int s,int e){
    d[s][e] = d[e][s] = 1;
    
    return ;
}
