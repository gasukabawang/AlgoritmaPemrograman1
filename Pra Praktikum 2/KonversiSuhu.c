// #include <stdio.h>
// #include <math.h>

// double CelciusToFahrenheit(double celcius){
//     return celcius*9/5+32;
// }
// double CelciusToKelvin(double celcius){
//     return celcius+273.15;
// }
// double FahrenheitToCelcius(double fahrenheit){
//     return (fahrenheit-32)*(5/9);
// }
// double FahrenheitToKelvin(double fahrenheit){
//     return (fahrenheit-32)*(5/9)+273.15;
// }
// double KelvinToCelcius(double kelvin){
//     return kelvin-273.15;
// }
// double KelvinToFahrenheit(double kelvin){
//     return (kelvin-273.15)*(9/5)+32;
// }

// void KonversiSuhu(double x, char a, char b, double final[], int i){
//     if(a=='C'){
//         if(b=='F'){
//             final[i] = CelciusToFahrenheit(x);
//         } else if(b=='K'){
//             final[i] = CelciusToKelvin(x);
//         }
//     } else if(a=='F'){
//         if(b=='C'){
//             final[i] = FahrenheitToCelcius(x);
//         } else if(b=='K'){
//             final[i] = FahrenheitToKelvin(x);
//         } 
//     } else{
//         if(b=='C'){
//             final[i] = KelvinToCelcius(x);
//         } else if(b=='F'){
//             final[i] = KelvinToFahrenheit(x);
//         } 
//     }
// }

// int main(){
//     int N;
//     double x;
//     char a, b;
//     scanf("%d", &N);
//     double final[N];
//     for(int i=0; i<N; i++){
//         scanf("%lf %c %c", &x, &a, &b);
//         KonversiSuhu(x, a, b, final, i);
//     }
//     for(int i=0; i<N; i++){
//         printf("%.2lf\n", floor(final[i]));
//     }
//     return 0;
// }

#include <stdio.h>
#include <math.h>

double KonversiSuhu(double x, char a, char b){
    double final;
    if (a =='C' && b == 'F'){
        final = x *9/5+32;
    }
    else if (a == 'C' && b == 'K'){
        final = x + 273.15;
    }
    else if (a == 'F' && b == 'C'){
        final = (x-32)*5/9;
    }
    else if (a == 'F' && b == 'K'){
        final = (x-32)*5/9+273.15;
    }
    else if (a == 'K' && b == 'C'){
        final = x-273.15;
    }
    else if (a == 'K' && b == 'F'){
        final = (x-273.15)*9/5+32;
    }
    return final;
}
int main (){
    double N;
    scanf("%lf", &N);
    
    double x;
    char a,b;
    double final;
    for (int i=0; i<N; i++){
        scanf("%lf %c %c", &x, &a, &b);
        final= KonversiSuhu(x,a,b);
        printf("%.2lf\n", floor(final));
    }
    return 0;
}