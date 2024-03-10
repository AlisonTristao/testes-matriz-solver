#include <cstdio>
#include <cmath>
#include <vector>
#include <random>
#include <thread>  
#include <iostream>
#include <Matrix.hpp>
#include <Vector.hpp>
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

Vector linear_system(Matrix pontos, int linhas){
    Matrix A(linhas, 3);
    Matrix At(3, linhas);
    Matrix r(linhas, 1);

    for(int i = 1; i <= linhas; i++){
        A.set_val(i, 1, 1);
        A.set_val(i, 2, -2*pontos.get_row(i).get_val(1));
        A.set_val(i, 3, -2*pontos.get_row(i).get_val(2));

        At.set_val(1, i, 1);
        At.set_val(2, i, -2*pontos.get_row(i).get_val(1));
        At.set_val(3, i, -2*pontos.get_row(i).get_val(2));

        r.set_val(i, 1,-(pontos.get_row(i).get_val(1)*pontos.get_row(i).get_val(1)) - (pontos.get_row(i).get_val(2)*pontos.get_row(i).get_val(2)));
    }

    Matrix AtA = operator*(At, A);
    Matrix Atr = operator*(At, r);
    Vector p = Atr.get_col(1);

    return LUsolve(AtA, p);
}

int main() {
    // variaveis de cada experimento
    double inicio_pontos    = 03,   final_pontos    = 15,   degraus_pontos      = 12;  // ciudado tem q dar numero inteiro
    double inicio_radianos  = pi/4, final_radianos  = 2*pi, degraus_radianos    = 07;  
    double inicio_raio      = 05,   final_raio      = 20,   degraus_raio        = 03;  
    double inicio_xy0       = 00,   final_xy0       = 12,   degraus_xy0         = 01;  
    double inicio_ruido     = 00,   final_ruido     = 0.5,   degraus_ruido      = 02;

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
    //for(double desloc_xy = inicio_xy0; desloc_xy <= final_xy0; desloc_xy += ((final_xy0-inicio_xy0)/degraus_xy0)){
        double desloc_xy = 0.0;
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
                        Matrix pontos(n_pontos, 2);
                        for(int j = 1; j <= n_pontos; j++){
                            double px = cos(rad*j/n_pontos)*r+desloc_xy+ruido[j-1];
                            double py = sin(rad*j/n_pontos)*r+desloc_xy+ruido[j-1+int(n_pontos)];
                            pontos.set_val(j, 1, px);
                            pontos.set_val(j, 2, py);
                            printf("(%.1f,", pontos.get_row(j).get_val(1));
                            printf("%.1f);", pontos.get_row(j).get_val(2));
                        }

                        Vector result = linear_system(pontos, n_pontos);
                        printf("(%.1f,%.1f,%.1f);", sqrt(-result.get_val(1)+result.get_val(2)*result.get_val(2)+result.get_val(3)*result.get_val(3)), result.get_val(2), result.get_val(3));
                        printf("(%.1f,%.1f,%.1f)", r, desloc_xy, desloc_xy);

                        //printf("%.2f/%.2f\txy0: %.2f\traio: %.2f\trad: %.2f\tn pontos: %.2f\truido: %.2f\t", ++contador, linhas, desloc_xy, r, rad, n_pontos, prop);              
                        delete[] ruido;
                        printf("\n");
                    }
                }
            }
            this_thread::sleep_for(chrono::seconds(5));
        }
    //}
    //}

    printf("aqui\n");

    return 0;
}
