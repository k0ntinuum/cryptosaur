#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "shuffle.c"
#include "compute.c"
#include "text.c"
#include "print.c"

int main() {
    int M[S][S];int M_orig[S][S];
    int row_f[P], row_f_inv[P];
    int col_f[P], col_f_inv[P];
    randomize(M);
    copy_matrix_src_tar(M, M_orig);
    permutize(row_f,P);permutize(col_f,P);
    invert(row_f,row_f_inv,P);invert(col_f,col_f_inv,P);
    int delay = 200000;
    int T = 2000;
    hide_cursor();
    cls();
    for (int i = 0; i < T ; i++) {
        cursor_to(0,0);
        print_matrix(M);
        process_rows(M, row_f);
        process_cols(M, col_f);
        usleep(delay);
    }
    for (int i = 0; i < T ; i++) { 
        process_cols(M, col_f_inv);
        process_rows(M, row_f_inv);
        cursor_to(0,0);
        print_matrix(M);
        usleep(delay);
    }
    printf("\n%d decoding errors \n", h_dist(M,M_orig));
    show_cursor();
    //print_matrix(M_orig);
}
      