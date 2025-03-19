//code for knapsack algorithm 
#include<iostream>
using namespace std;
int main(){
    float weight[50],profit[50],ratio[50],total_value,temp,capacity,amount;
    int n,i,j;
    cout<<"Enter the number of items : ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Enter the weight and profit of item "<<i+1<<" : ";
        cin>>weight[i]>>profit[i];
    }
    cout<<"Enter the capacity of knapasack:\n";
    cin>>capacity;

    for ( i = 0; i < n; i++){
        ratio[i] = profit[i] / weight[i];
    }
    for ( i = 0; i < n - 1; i++){
        for ( j = i+1; j<n; j++){
            if (ratio[i] < ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    cout<<"Knapsack problem using greedy algorithm ";
    for ( i = 0; i <n; i++){
        if (weight[i]==capacity){
            break;
        }else{
            total_value=total_value+profit[i];
            capacity=capacity-weight[i];
        }
        if (i<n){
        total_value =total_value+(ratio[i]*capacity);
        cout<<"Total value is: "<<total_value<<endl;
        }
    }
  return 0;
}