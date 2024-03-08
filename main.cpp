#include <cstdio>
#include "matriz_solver\Matrix.hpp"
using namespace std;

#define pi 3.1415926

// quantidade de vezes q repete o experimento
double inicio = 0, final = 5, degraus = 5;

int main() {
    // variaveis de cada experimento
    /*double inicio_pontos    = 03,   final_pontos    = 31,   degraus_pontos      = 14;  
    double inicio_radianos  = pi/4, final_radianos  = 2*pi, degraus_radianos    = 07;  
    double inicio_raio      = 01,   final_raio      = 20,   degraus_raio        = 10;  
    double inicio_xy0       = 00,   final_xy0       = 10,   degraus_xy0         = 10;  
    double inicio_ruido     = 00,   final_ruido     = 10,   degraus_ruido      = 10;

    // col: teste, raio, x0, y0, n_pontos, radianos, tempo, ruido, metodo // 9 elementos
    double linhas = (degraus+1)*(degraus_pontos+1)*(degraus_radianos+1)*(degraus_raio+1)*(degraus_xy0+1);
    Matrix all(linhas, 9);

    // repete o mesmo experimento para redundancias
    double contador = 0;
    for(double teste = inicio; teste <= final; teste += ((final-inicio)/(degraus))){   
        // dados de cada experimento
        int media, max, min, desv_padrao; 
        // dados do circulo
        int raio, x0, y0;

        // desloca o centro
        for(double desloc_xy = inicio_xy0; desloc_xy <= final_xy0; desloc_xy += ((final_xy0-inicio_xy0)/(degraus_xy0))){
            // aumenta o raio
            for(double r = inicio_raio; r <= final_raio; r += ((final_raio-inicio_raio)/(degraus_raio))){
                // aumenta a circunferencia
                for(double rad = inicio_radianos; rad <= final_radianos; rad += ((final_radianos-inicio_radianos)/(degraus_radianos))){
                    // aumenta a quantidade de pontos
                    for(double n_pontos = inicio_pontos; n_pontos <= final_pontos; n_pontos += ((final_pontos-inicio_pontos)/(degraus_pontos))){
                        // debug printf("%.2f/%.2f\tteste: %.2f\txy0: %.2f\traio: %.2f\trad: %.2f\tn pontos: %.2f\n", ++contador, linhas, teste, desloc_xy, r, rad, n_pontos);
                    

                    }
                }
            }
        }
    }*/

    printf("aqui\n");

    return 0;
}
