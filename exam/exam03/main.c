#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

# define SUCCESS 0
# define ERROR 1

typedef struct table_s {
	char back;
	float x;
	float y;
	float radius;
	char fill;
	char *str;
	int w;
	int h;
	char cs;
} table_t;

float calc(table_t t, float i, float j) {
	return (t.radius - sqrtf(powf(t.x - i, 2) + powf(t.y - j, 2)));
}

int r_opener(FILE *fd, char *filename, table_t *t) {
	fd = fopen(filename, "r");
	if (!fd) return(ERROR);
	if (fscanf(fd, "%d %d %c\n", &t->w, &t->h, &t->back) != 3 || t->w <= 0 || t->w > 300 || t->h <= 0 || t->h > 300) return(ERROR);
	t->str = malloc(t->w * t->h + 1);
	memset(t->str, t->back, t->w * t->h);
	t->str[t->w * t->h] = '\0';
	int count = fscanf(fd, "%c %f %f %f %c\n", &t->cs, &t->x, &t->y, &t->radius, &t->fill);
	int i, j = 0;
	while (count == 5) {
		if (t->radius <= 0) return (ERROR);
		j = 0;
		while (j < t->w) {
			i = 0;
			while (i < t->h) {
				if ((calc(*t, i, j) < 1 && calc(*t, i, j) >= 0) || (t->cs == 'C' && calc(*t, i, j) >= 0)) {
					t->str[t->w * j + i] = t->fill;
				}
				i++;
			}
			j++;
		}
		count = fscanf(fd, "%c %f %f %f %c\n", &t->cs, &t->x, &t->y, &t->radius, &t->fill);
	}
	if (count != -1) return (ERROR);
	return (SUCCESS);
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		FILE *fd = NULL;
		table_t t;
		if (r_opener(fd, argv[1], &t))
			return ((void)write(1, "Error: Operation file corrupted\n", 32), ERROR);
		for (int j = 0; j < t.w; j++) {
			for (int i = 0; i < t.h; i++) {
				printf("%c", t.str[j*t.w + i]);
			}
			printf("\n");
		}
		printf("\n");
		return (SUCCESS);
	}
	else
		return ((void)write(1, "Error: argument\n", 16), ERROR);
}
