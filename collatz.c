#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main(){

    mpz_t n;
    mpz_t x;
    mpz_init(n);
    mpz_init(x);

    unsigned long int base;
    unsigned long int exponent;
    clock_t start, end;
    double cpu_time_used;

    printf("Please enter base of the starting number: ");
    scanf(" %lu", &base);

    printf("\nPlease enter exponent of the starting number: ");
    scanf(" %lu", &exponent);

    mpz_ui_pow_ui(x, base, exponent);

label:
    mpz_set(n, x);
    mpz_sub_ui(n, n, 1);
    printf("Checking (%lu^%lu)-1 ...", base, exponent);
    //mpz_out_str(stdout,10,n);
    //usleep(10000);
    fflush(stdout);
    start = clock();

    while(mpz_cmp_ui(n, 1) != 0){
        if(mpz_even_p(n) != 0){
            mpz_divexact_ui(n, n, 2);
            }
        else{
        mpz_mul_ui(n, n, 3);
        mpz_add_ui(n, n, 1);
        };
        //usleep(10000);
        //mpz_out_str(stdout, 10, n);
        //printf("\n");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("ENDS IN LOOP! time taken to calculate: %lf seconds\n",cpu_time_used);
    exponent++;
    mpz_mul_ui(x, x, base);
    goto label; //Can be made into a while(1) loop, but one goto in small code is fine

return 0;
}