

void process_row(int X[S][S], int r, int f[P]) {
	int found_value = 0;
	int new_value = 0;
	for (int c = 0 ; c < S ; c++) found_value += place_value[c]*X[r][c];
	new_value = f[found_value];
	for (int c = 0 ; c < S ; c++) {
		X[r][c] = new_value/place_value[c];
		new_value -= X[r][c]*place_value[c];
	}
}
void process_rows(int X[S][S],int f[P]) {
	for (int r = 0; r < S; r++) process_row(X, r, f);
}
void process_col(int X[S][S], int c, int f[P]) {
	int found_value = 0;
	int new_value = 0;
	for (int r = 0 ; r < S ; r++) found_value += place_value[r]*X[r][c];
	new_value = f[found_value];
	for (int r = 0 ; r < S ; r++) {
		X[r][c] = new_value/place_value[r];
		new_value -= X[r][c]*place_value[r];
	}
}
void process_cols(int X[S][S],int f[P]) {
	for (int c = 0; c < S; c++) process_col(X, c, f);
}


void copy_matrix_src_tar(int src[S][S],int tar[S][S]) {
	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) tar[i][j] = src[i][j];
}




