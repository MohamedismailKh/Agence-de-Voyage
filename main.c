#include <stdio.h>
#include <stdlib.h>
#include"mes_fcts.h"
int main()
{
FILE*fp;
AGENCE agc;
creeFichierAgence(&fp);
remplirFichierAgence(fp);
afficherFichierAgence(fp);
fclose(fp);

    return 0;
}
