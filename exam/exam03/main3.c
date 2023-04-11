#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define ERROR 1
#define SUCCESS 0

typedef struct s_shape {
	char cs;
	float x;
	float y;
	float rad;
	char fill;
}				t_shape;
typedef struct s_base {
	FILE *fp;
	int w;
	int h;
	char back;
	char *canvas;
	t_shape s;
}				t_base;


static int base_check(t_base *t) {
	return (t->w <= 0 || t->w > 300 || t->h <= 0 || t->h > 300);
}

static int base_fill(t_base *t) {
	int count = fscanf(t->fp, "%d %d %c\n", &t->w, &t->h, &t->back);
	if (count != 3 || base_check(t)) return (ERROR);
	t->canvas = malloc(t->w * t->h + 1);
	memset(t->canvas, t->back, t->w * t->h);
	t->canvas[t->w * t->h] = '\0';
	return (SUCCESS);
}

static int shape_check(t_base *t) {
	return (!(t->s.cs == 'c' || t->s.cs == 'C') || t->s.rad <= 0);
}

static float calc(float x, float y) {
	return (sqrtf(powf(x, 2) + powf(y, 2)));
}

static int shape_fill_check(float i, float j, t_base *t) {
	if (calc(i - t->s.y, j - t->s.x) <= t->s.rad) {
		if (t->s.cs == 'c') {
			if (t->s.rad - calc(i - t->s.y, j - t->s.x) < 1) return (1);
			else return (0);
		}
		else return (1);
	} else return (0);
}

static int shape_fill(t_base *t) {
	int count = fscanf(t->fp, "%c %f %f %f %c\n", &t->s.cs, &t->s.x, &t->s.y, &t->s.rad, &t->s.fill);
	if (count != 5 || shape_check(t)) return ((void)printf("1\n"), ERROR);
	for (; count == 5; count = fscanf(t->fp, "%c %f %f %f %c\n", &t->s.cs, &t->s.x, &t->s.y, &t->s.rad, &t->s.fill)) {
		if (shape_check(t)) return ((void)printf("2\n"), ERROR);
		for (int i = 0; i < t->h; i++) {
			for (int j = 0; j < t->w; j++) {
				if (shape_fill_check(i, j, t)) t->canvas[i * t->w + j] = t->s.fill;
			}
		}
	}
	if (count != -1) return ((void)printf("3\n"), ERROR);
	return (SUCCESS);
}

static void print(t_base *t) {
	for (int i = 0; i < t->h; i++) {
		for (int j = 0; j < t->w; j++) {
			write(1, &t->canvas[i * t->w + j], 1);
		}
		write(1, "\n", 1);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) return ((void)write(1, "Error: argument\n", 16), ERROR);

	t_base t;

	t.fp = fopen(argv[1], "r");
	if (!t.fp) return ((void)write(1, "Error: Operation file corrupted\n", 32), ERROR);
	if (base_fill(&t) || shape_fill(&t)) return ((void)write(1, "Error: Operation file corrupted\n", 32), ERROR);
	return (print(&t), free(t.canvas), fclose(t.fp), SUCCESS);
}
