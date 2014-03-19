#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_R 4
#define MAX_C 4
#define WIN_SCORE 2048


int gen_table( int table[MAX_R][MAX_C] );
int numb_generator();
void print_table( int table[MAX_R][MAX_C] );
void numb_on_table( int table[MAX_R][MAX_C]);
int check_win ( int table[MAX_R][MAX_C] );
int check_lose ( int table[MAX_R][MAX_C] );
void move_numb ( int table[MAX_R][MAX_C] );
void cls();



int main() {


	srand(time(NULL)); 
	
	int table[MAX_R][MAX_C];
	int gen_numb;
	int i, j;
	int pos_x, pos_y;


	for ( i = 0; i< MAX_R ; i++ ) {					// genero la tabella vuota
		for ( j = 0; j<MAX_C; j++ ) {
			table[i][j] = 0;		
		}
	}

	if (rand() % 3 < 2) {
		gen_numb = 2;
	} else {
		gen_numb = 4;
	}

	pos_x = rand() % MAX_R;					// genero le coordinate del numero iniziale
	pos_y = rand() % MAX_C;

	table[pos_x][pos_y] = gen_numb;

	do {
		print_table(table);
		move_numb(table);
		numb_on_table(table);
	}

	while (check_win(table) != 1 || check_lose(table) != 1);




}

void move_numb(int table[MAX_R][MAX_C]) {

	char movement[1];
	int i, j, r, c;

	scanf("%c", &movement[0]);


	if (strcmp(&movement[0], "w") == 0) {

		for (i = 1; i < MAX_R ; i++) {						
			for ( j = 0; j < MAX_C; j++ ) {				
				if (table[i][j] != 0) {
					r = i;
					c = j;
					while ( r != 0) {
						if (table[r-1][c] == table[r][c]) {
							table[r-1][c] *= 2;
							table[r][c] = 0;

						} else {
							table[r-1][c] = table[r][c];
							table[r][c] = 0;
							
						}
						r--;
					}
				}
			}
		}

	} else if (strcmp(&movement[0], "a") == 0) {

		for (i = 0; i < MAX_R ; i++) {						
			for ( j = 1; j < MAX_C; j++) {				
				if (table[i][j] != 0) {
					r = i;
					c = j;

					while ( c != 0) {
						if (table[r][c-1] == table[r][c]) {
							table[r][c-1] *= 2;
							table[r][c] = 0;

						} else {
							table[r][c-1] = table[r][c];
							table[r][c] = 0;
						}
						c--;
					}
				}
			}
		}

	} else if (strcmp(&movement[0], "s") == 0) {

		for (i = 0; i < MAX_R ; i++) {						
			for ( j = 0; j < MAX_C; j++ ) {				
				if (table[i][j] != 0) {
					r = i;
					c = j;

					while ( r != 3) {
						if (table[r+1][c] == table[r][c]) {
							table[r+1][c] *= 2;
							table[r][c] = 0;

						} else {
							table[r+1][c] = table[r][c];
							table[r][c] = 0;
							print_table(table);
						}
						r++;
						printf("%d", r);
					}
				}
			}
		}

	} else if (strcmp(&movement[0], "d") == 0) { 

		for (i = 0; i < MAX_R ; i++) {						
			for ( j = 0; j < MAX_C; j++) {				
				if (table[i][j] != 0) {
					r = i;
					c = j;

					while ( c != 3) {
						if (table[r][c+1] == table[r][c]) {
							table[r][c+1] *= 2;
							table[r][c] = 0;

						} else {
							table[r][c+1] = table[r][c];
							table[r][c] = 0;
						}
						c++;
					}
				}
			}
		}
	}


}

int check_win(int table[MAX_R][MAX_C]) {

	int i, j;

	for (i = 0; i < MAX_R; i++) {
		for ( j = 0; j < MAX_C; j++ ) {
			if (table[i][j] == WIN_SCORE) 

				printf("\n\nComplimenti!! Hai vinto!\n\n");
				return 1;
		}
	}
	return 0;

}

int check_lose(int table[MAX_R][MAX_C]) {

	int i, j, flag = 0;

	for (i = 0; i < MAX_R; i++) {
		for ( j = 0; j < MAX_C; j++ ) {
			if (table[i][j] != 0) 
				flag++;
		}
	}
	
	if (flag == (MAX_C * MAX_R)) {
		for (i = 0; i < MAX_R; i++) {
			for ( j = 0; j < MAX_C; j++ ) {
				if (table[i+1][j] != table[i][j] &&
					table[i][j+1] != table[i][j] &&
					table[i+1][j+1] != table[i][j] &&
					table[i-1][j] != table[i][j] &&
					table[i][j-1] != table[i][j] &&
					table[i-1][j-1] != table[i][j]) {

					printf("\n\nMi dispiace ma hai perso!\n\n");
					return 1;
				}
			}
		}
	}

	return 0;

}


void print_table( int table[MAX_R][MAX_C] ) {

	int i, j;

	cls();

	printf("\n-----------------\n");
	for ( i = 0; i< MAX_R ; i++ ) {
		for ( j = 0; j<MAX_C; j++ ) {
			printf("|");
			if (table[i][j] == 0) {
				printf("   ");
			} else {
				printf(" %d ", table[i][j]);
			}
		}
		printf("|");
		printf("\n-----------------\n");
	}

}


int numb_generator() {

	int gen_numb = 0;


	if (rand() % 3 < 2) {
		gen_numb = 2;
	} else {
		gen_numb = 4;
	}

	return gen_numb;
}

void numb_on_table ( int table[MAX_R][MAX_C] ) {

	srand(time(NULL)); 


	int pos_x = 0;
	int pos_y = 0;
	int gen_numb;

	do {
		pos_x = rand() % MAX_R;
		pos_y = rand() % MAX_C;
	}
	while ((table[pos_x][pos_y]) != 0);

	gen_numb = numb_generator();

	table[pos_x][pos_y] = gen_numb;

}

void cls()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}