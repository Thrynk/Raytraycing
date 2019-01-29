typedef struct material_ {
	Color SpecularColor; 	// La couleur Specular (rattach� � la brillance de l'objet).
	Color DiffuseColor; 	// La couleur Diffuse (�clairage diffus).
	Color AmbientColor; 	// La couleur Ambient (�clairage ambient).
	Color SelfIllumColor; 	// La couleur de Self Illum (objets �m�ttant eux m�me de la lumi�re).
	float Shininess; 	// La "brillance" du material (utilis� pour la r�fl�xion et coupl� avec la couleur Specular).
	float Shinestrength; 	// La puissance de brillance (coefficient coupl� avec la valeur pr�c�dente).
	float Transmittivity; 	// Le coefficient de  transmission (utilis� pour la r�fraction).
	float Reflectivity; 	// Le coefficient de r�fl�xion (utilis� pour la r�fl�xion).
} Material;
