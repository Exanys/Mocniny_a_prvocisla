/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vojta
 *
 * Created on September 19, 2020, 9:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "cisla.txt"
#define VYSTUP "vystup.txt"

int mocnina(int z, int m){
    int nasobeni = 1;
    for(;m > 0; m--){
        nasobeni *= z;
    }
    return nasobeni;
}
int prvocislo(int z){
    int del = 2;
    if(z == 1)
        return 1;
    while(del < z){
        if(z % del == 0){
            return 0;
        }
        else
            del++;
    }
    return 1;
}



int main(int argc, char** argv) {

    FILE * vstup;
    FILE * vystup;
    int z, m;
    int poradi = 0, poradiS = 0;
    
    
    if((vstup = fopen(VSTUP, "r"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VSTUP);
    if((vystup = fopen(VYSTUP, "w"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VYSTUP);
    
    printf("Vypis cisel ze souboru %s.\n", VSTUP);
    printf("---------------------------------\n");
    printf("poradi zaklad exponent    mocnina\n");
    fprintf(vystup,"Vypis cisel s prvociselnym zakladem ze souboru %s.\n", VSTUP);
    fprintf(vystup,"---------------------------------------------------------\n");
    while((fscanf(vstup, "%d %d", &z, &m))!= EOF){
        poradi++;
        printf("%5d. %6d %8d %10d\n", poradi, z, m, mocnina(z, m));
        if(prvocislo(z)){
            poradiS++;
            fprintf(vystup,"%5d. %6d %8d %10d\n", poradiS, z, m, mocnina(z, m));
        }
    }
    
    fprintf(vystup,"Soubor %s obsahuje %d dvojic cisel.\n", VYSTUP, poradiS);
    
    
    
    
    if((fclose(vstup))==EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VSTUP);
    if((fclose(vystup))==EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VYSTUP);
    else
        printf("Byl vytvoren soubor cisel %s s poctem dvojic cisel rovnym %d.\n", VYSTUP, poradiS);
    
    return (EXIT_SUCCESS);
}

