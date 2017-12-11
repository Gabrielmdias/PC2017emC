/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabriel
 *
 * Created on 13 de Novembro de 2017, 13:40
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct classificacao{
    double distancia;
    char classe[20];
};


char *classificar(FILE *arqB, FILE *arqX, int k){ 
    classificacao c;
    c.distancia = 0;
    c.classe = "classe";
    
    char lineX[1024], lineB[1024];
    char *valorX, *valorB;
    
    fgets(lineX, sizeof(lineX), arqX);
    valorX = strtok(lineX,",");
    while(fgets(lineB, sizeof(lineB), arqB)){
        valorB = strtok(lineB, ",");
         
        double  numX = atof(valorX),
                numB = atof(valorB);
        
        if(numX)
            c.distancia += pow(numB - numX, 2);
        else
            c.classe = valorB;
    }
    //printf("valor = %s\n", valorX);
    while(valorX = strtok(NULL,",")){
        printf("valor = %s\n", valorX);
    }
    scanf("\n");
    
    return "qualquer coisa";
}

int main(int argc, char** argv) {
    
    char lineX[1024], lineB[1024];
    char *valorX, *valorB;
    char nomeArqB[] = "train_59.data";
    char nomeArqX[] = "test_59.data";
    
    FILE *arqB, *arqX;
    
    arqB = fopen(nomeArqB, "r");
    arqX = fopen(nomeArqX, "r");
    
    if(arqB == NULL || arqX == NULL){
        printf("Erro ao abrir o arquivo.");
        return 0;
    }else{
        while(fgets(lineX, sizeof(lineX), arqX)){
            valorX = strtok(lineX,",");
            printf("valor = %s\n", valorX);
            while(valorX = strtok(NULL,",")){
                printf("valor = %s\n", valorX);
            }
            scanf("\n");
        }
    }
    
    //printf(classificar(arqB, arqX, 10));
    
    fclose(arqB);
    fclose(arqX);
    
    return 0;
}

