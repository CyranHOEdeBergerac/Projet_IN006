/*--- Préambule ---*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"tests_primalite.h"
#include"gestion_cryptage.h"


/*Main fourni par l'énoncé*/
int main (){
    //Generation de cle :
    long p = random_prime_number (15 ,16 , 5000) ;
    long q = random_prime_number (15 ,16 , 5000) ;
    long n , s , u ;
    generate_key_values (p ,q ,&n ,&s ,&u ) ;
    printf("n : %ld\n",n);
    printf ( " cle publique = (% ld , %ld ) \n" ,s , n ) ;
    printf ( " cle prive = (% ld , %ld ) \n" ,u , n ) ;

    char message [999] = "Hello";
    int len = strlen ( message ) ;
    //Chiffrement:
    long * crypted = encrypt ( message , s , n ) ;

    printf ("Initial message : %s \n" , message ) ;
    printf ( "Encoded representation : \n" ) ;
    print_long_vector ( crypted , len ) ;
    //Dechiffrement
    char * decoded = decrypt ( crypted , len , u , n ) ;
    printf ( " Decoded : %s \n" , decoded ) ;

    free(crypted);
    free(decoded);

    return 0;
}