#include "../headers/image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Image * NouvelleImage(int w, int h)
{
	Image * I = (Image *) malloc(sizeof(Image));
	I->w = w;
	I->h = h;
	I->dat = calloc(1, w*h * sizeof(ColorRGB*));
	return I;
}

void DelImage(Image* I){
	if (I){
		free(I->dat);
		free(I);
	}
}

ColorRGB convertColorInRgbFormat(float r, float g, float b){
  ColorRGB c;
  c.r = (r >= 1.0 ? 255 : (r <= 0.0 ? 0 : (int)floor(r * 256.0)));
  c.g = (g >= 1.0 ? 255 : (g <= 0.0 ? 0 : (int)floor(g * 256.0)));
  c.b = (b >= 1.0 ? 255 : (b <= 0.0 ? 0 : (int)floor(b * 256.0)));
  return c;
}

ColorRGB GetPixel(Image* I, int i, int j){
	assert(I && i >= 0 && i<I->w && j >= 0 && j<I->h);
	return I->dat[I->w*j + i];
}

void SetPixel(Image* I, int i, int j, ColorRGB p)
{
	assert(I && i >= 0 && i<I->w && j >= 0 && j<I->h);
	I->dat[I->w*j + i] = p;
}

int Sauver(Image* I, const char* fichier)
{
	struct BMPHead head;
	ColorRGB p;
	int i, j, tailledata, pitch;
	unsigned char bgrpix[3];
	char corrpitch[4] = { 0,3,2,1 };
	FILE* F = fopen(fichier, "wb");
	if (!F)
		return -1;
	memset(&head, 0, sizeof(struct BMPHead));
	head.signature[0] = 'B';
	head.signature[1] = 'M';
	head.offsetim = sizeof(struct BMPHead);
	head.imhead.size_imhead = sizeof(struct BMPImHead);
	head.imhead.width = I->w;
	head.imhead.height = I->h;
	head.imhead.nbplans = 1;
	head.imhead.bpp = 24;
	pitch = corrpitch[(3 * head.imhead.width) % 4];
	tailledata = 3 * head.imhead.height*head.imhead.width + head.imhead.height*pitch;
	head.imhead.sizeim = tailledata;
	head.taille = head.offsetim + head.imhead.sizeim;
	fwrite(&head, sizeof(struct BMPHead), 1, F);
	for (j = 0; j<I->h; j++)
	{
		for (i = 0; i<I->w; i++)
		{
			p = GetPixel(I, i, I->h - j - 1); // h - j - 1 : lire de haut en bas
			bgrpix[0] = p.b;
			bgrpix[1] = p.g;
			bgrpix[2] = p.r;
			fwrite(&bgrpix, 1, 3, F);
		}
		bgrpix[0] = bgrpix[1] = bgrpix[2] = 0;
		fwrite(&bgrpix, 1, pitch, F);
	}
	fclose(F);
	return 0;
}
