
void print_perm(int* f, int l) {
	for (int i = 0; i < l; i++)  {
        if (i % 16 == 0 ) printf("\n");
        printf("%03d ", f[i]);
        
    }
    printf("\n");
}
void print_matrix(int X[S][S]) {
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++)
            switch (X[i][j]) {
                case 0 : rgb(255,255,255);printf("O ");break;
                case 1 : rgb(255,255,255);printf("| ");break;
                case 2 : rgb(255,255,255);printf("  ");break;
                default : printf("%2d", X[i][j]);break;
        }
        printf("\n");
    }
    printf("\n");
}

int h_dist(int X[S][S], int Y[S][S]) {
    int e = 0;
    for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) if (X[i][j] != Y[i][j]) e++;
    return e;
    
}
