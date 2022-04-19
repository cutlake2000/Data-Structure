#define MAX_b 101
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#include <stdio.h>

typedef struct{
    int degree;
    float coef[MAX_b];
} poly;

poly poly_add(poly a, poly b){
    poly c;
    int a_pos = 0, b_pos = 0, c_pos = 0;
    int degree_A = a.degree;
    int degree_B = b.degree;
    c.degree = MAX(a.degree, b.degree);

    while(a_pos <= a.degree && b_pos <= b.degree){
        if (degree_A > degree_B){
            c.coef[c_pos++] = a.coef[a_pos++];
            degree_A--;
        }
        else if(degree_A == degree_B){
            c.coef[c_pos++] = a.coef[a_pos++] + b.coef[b_pos++];
            degree_A--;
            degree_B--;
        }
        else{
            c.coef[c_pos++] = b.coef[b_pos++];
            degree_B--;
        }
    }

    return c;
}

void print_poly(poly p){
    for (int i = p.degree ; i > 0 ; i--){
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main(void){
	poly a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	poly b = { 4,{ 7, 0, 5, 0, 1 } };
	poly c;
	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}