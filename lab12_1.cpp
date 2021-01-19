#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double data[],int num,double ans[]){
    int i=0;
    double sum=0;
	double mean=0;
    double SD,GM=1.00;
    double harmonic;
    double min= data[0];
    double max=data[0];
    while (i!=num){
        sum+=data[i];
        i++;
    }
    mean=sum/num;
    ans[0]=mean;
    for(int j=0;j<num;j++){
        SD+= (data[j]-mean)*(data[j]-mean);
    }
    SD /=num;
    ans[1]= sqrt(SD);

    for (int k=0;k<num;k++){
        GM*=data[k];
    }
    ans[2]= pow(GM,(double)1/num);

    for (int l=0;l<num;l++){
        harmonic += 1/data[l];
    }
    ans[3] =num/harmonic;

    for (int m=0;m<num;m++){
        if(min>data[m]) min =data[m];
        if(max<data[m]) max =data[m];
    }
    ans[4] = max;
    ans[5] =min;
}
