#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define ERROR 1
#define SUCCESS 0
#define CHECK(x) ((x > 0) && (x <= 300)) ? (x) : (0)

typedef struct s_base {
	int w;
	int h;
	char back;
	char *canvas;
}				t_base;

typedef struct shape {
	char cs;
	float x;
	float y;
	float w;
	float h;
	char fill;
}				t_shape;

int back_fill(FILE *fp, t_base *t);
int read_draw(FILE *fp, t_base *t, t_shape *s);
void draw(t_base *t, t_shape *s);
int ft_check(float i, float j, t_shape *s);
void print(t_base *t);

int back_fill(FILE *fp, t_base *t) {
	int count = 0;
	count = fscanf(fp, "%d %d %c\n", &t->w, &t->h, &t->back);
	if (count != 3 || !CHECK(t->w) || !CHECK(t->h)) return ((void)write(1, "000\n", 4), ERROR);
	t->canvas = malloc(t->w * t->h + 1);
	memset(t->canvas, t->back, t->w * t->h);
	t->canvas[t->w * t->h] = '\0';
	return (SUCCESS);
}

int read_draw(FILE *fp, t_base *t, t_shape *s) {
	int count = 0;
	count = fscanf(fp, "%c %f %f %f %f %c\n", &s->cs, &s->x, &s->y, &s->w, &s->h, &s->fill);
	if (count != 6 || (s->cs != 'R' && s->cs != 'r') || s->w <= 0 || s->h <= 0) return ((void)write(1, "111\n", 4), ERROR);
	while (count == 6) {
		draw(t, s);
		count = fscanf(fp, "%c %f %f %f %f %c\n", &s->cs, &s->x, &s->y, &s->w, &s->h, &s->fill);
		if ((s->cs != 'R' && s->cs != 'r') || s->w <= 0 || s->h <= 0) return ((void)write(1, "222\n", 4), ERROR);
	}
	if (count != -1) return ((void)write(1, "333\n", 4), ERROR);
	return (SUCCESS);
}

void draw(t_base *t, t_shape *s) {
	int i = 0, j = 0;
	for (; i < t->h; i++) {
		for (j = 0; j < t->w; j++) {
			if (ft_check(i, j, s)) t->canvas[i * t->w + j] = s->fill;
		}
	}
}

int ft_check(float i, float j, t_shape *s) {
	if (j >= s->x && j <= s->x + s->w && i >= s->y && i <= s->y + s->h) {
		if (s->cs == 'r') {
			if ((j - s->x) < 1 || (s->x + s->w) - j < 1 ||
			 (i - s->y) < 1 || (s->y + s->h) - i < 1) return (1);
			else return (0);
		} else return 1;
	}
	return 0;
}

void print(t_base *t) {
	for (int i = 0; i < t->h; i++) {
		for (int j = 0; j < t->w; j++) {
			write(1, &t->canvas[i * t->w + j], 1);
		}
		write(1, "\n", 1);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) return ((void)write(1, "Error: argument\n", 16), ERROR);

	FILE *fp;
	t_base t;
	t_shape s;

	fp = fopen(argv[1], "r");

	if (back_fill(fp, &t)) return (ERROR);
	if (read_draw(fp, &t, &s)) return (ERROR);
	print(&t);
	return (SUCCESS);
}
