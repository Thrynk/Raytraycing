#include <math.h>

typedef struct colorRGB_ {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} ColorRGB;

typedef struct Image
{
	int w, h;
	ColorRGB * dat;
} Image;

#pragma pack(1)  // desative l'alignement m�moire
typedef int int32;
typedef short int16;

struct BMPImHead
{
	int32 size_imhead;
	int32 width;
	int32 height;
	int16 nbplans;
	int16 bpp;
	int32 compression;
	int32 sizeim;
	int32 hres;
	int32 vres;
	int32 cpalette;
	int32 cIpalette;
};

struct BMPHead
{
	char signature[2];
	int32 taille;
	int32 rsv;
	int32 offsetim;
	struct BMPImHead imhead;
};

int Sauver(Image*, const char* fichier);

Image* NouvelleImage(int w, int h);

ColorRGB GetPixel(Image*, int i, int j);

void DelImage(Image*);

void SetPixel(Image*, int i, int j, ColorRGB p);

ColorRGB convertColorInRgbFormat(float r, float g, float b);
