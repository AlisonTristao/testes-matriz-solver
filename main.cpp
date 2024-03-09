#include <cstdio>
#include <cmath>
#include <vector>
#include <random>
#include <iostream>
#include "matriz_solver\Matrix.hpp"
#include "matriz_solver\Vector.hpp"
using namespace std;

#define pi 3.1415926

void noise(double * ruido, int tamanho, double prop){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<float> distribuicao(0.0f, 1.0f); // Distribuição normal com média 0 e desvio padrão 1
    
    for(int i = 0; i < tamanho; ++i) {
        ruido[i] = distribuicao(gen)*prop;
    }
}

int main() {
    // variaveis de cada experimento
    double inicio_pontos    = 03,   final_pontos    = 15,   degraus_pontos      = 02;  // ciudado tem q dar numero inteiro
    double inicio_radianos  = pi/4, final_radianos  = 2*pi, degraus_radianos    = 03;  
    double inicio_raio      = 01,   final_raio      = 20,   degraus_raio        = 03;  
    double inicio_xy0       = 00,   final_xy0       = 12,   degraus_xy0         = 03;  
    double inicio_ruido     = 00,   final_ruido     = 01,   degraus_ruido      = 02;

    // col: teste, raio, x0, y0, n_pontos, radianos, tempo, ruido, metodo // 9 elementos
    double linhas = (degraus_pontos+1)*(degraus_radianos+1)*(degraus_raio+1)*(degraus_xy0+1)*(degraus_ruido+1);
    Matrix all(linhas, 9);

    // repete o mesmo experimento para redundancias
    double contador = 0;

    // o ruido é igual, então n faz diferença isso 
    /*for(double teste = inicio; teste <= final; teste += ((final-inicio)/degraus)){   
    // dados de cada experimento
    int media, max, min, desv_padrao; */

    // dados do circulo
    int raio, x0, y0;

    // desloca o centro
    for(double desloc_xy = inicio_xy0; desloc_xy <= final_xy0; desloc_xy += ((final_xy0-inicio_xy0)/degraus_xy0)){
        // aumenta o raio
        for(double r = inicio_raio; r <= final_raio; r += ((final_raio-inicio_raio)/(degraus_raio))){
            // aumenta a circunferencia
            for(double rad = inicio_radianos; rad <= final_radianos; rad += ((final_radianos-inicio_radianos)/degraus_radianos)){
                // aumenta a quantidade de pontos
                for(double n_pontos = inicio_pontos; n_pontos <= final_pontos; n_pontos += ((final_pontos-inicio_pontos)/degraus_pontos)){
                    // aumenta o ruido
                    for(double prop = inicio_ruido; prop <= final_ruido; prop += ((final_ruido-inicio_ruido)/degraus_ruido)){
                        // array de ruido
                        double * ruido = new double[int(n_pontos*2)];
                        noise(ruido, int(n_pontos*2), prop);

                        printf("%.1f;", contador++);

                        // gera os pontos em coord polar e converte
                        //double pontos[int(n_pontos)][2];
                        Matrix pontos(final_pontos, 2);
                        for(int j = 1; j <= final_pontos; j++){
                            if(j <= n_pontos){
                                double px = cos(rad*j/n_pontos)*r+desloc_xy+ruido[j-1];
                                double py = sin(rad*j/n_pontos)*r+desloc_xy+ruido[j-1+int(n_pontos)];
                                pontos.set_val(j, 1, px);
                                pontos.set_val(j, 2, py);
                                printf("(%.1f,", pontos.get_row(j).get_val(1));
                                printf("%.1f);", pontos.get_row(j).get_val(2));
                            }else{
                                pontos.set_val(j, 1, 0);
                                pontos.set_val(j, 2, 0);
                                printf("(%.1f,", pontos.get_row(j).get_val(1));
                                printf("%.1f);", pontos.get_row(j).get_val(2));
                            }
                        }
                        //printf("%.2f/%.2f\txy0: %.2f\traio: %.2f\trad: %.2f\tn pontos: %.2f\truido: %.2f\t", ++contador, linhas, desloc_xy, r, rad, n_pontos, prop);              
                        delete[] ruido;
                        printf("\n");
                    }
                }
            }
        }
    }
    //}

    printf("aqui\n");

    return 0;
}
