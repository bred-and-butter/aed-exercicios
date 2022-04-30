# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define pi 3.14

void calc_esfera(float r, float *area, float *volume){
    *area = 4 * pi * pow(r, 2);
    *volume = (4/3) * pi * pow(r, 3);

    return;
}

int main(){
    float area, volume;
    float r;

    printf("Insira valor do raio:\n");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);

    printf("%f\n%f", area, volume);

    return 0;
}