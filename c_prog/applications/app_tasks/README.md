# APP_TASKS

$ gcc -g3 -main.c my_functions.c -o prog_task

$ ./prog_task

#include "header.h" (dans les fichiers.c).

## Pourquoi utilise-t-on l'adresse de count pour les fonctions ajouterTache et supprimerTache ?

R: Cela permet à la fonction de localiser où est stockée la variable count dans la mémoire et de modifier sa valeur directement.

## Pourquoi (*count)++; ?

Si pas de parenthèse => *(count)++ ce qui changerait l'adresse avant la valeur.

R: Les parenthèses dans (*count)++ sont utilisées pour indiquer au compilateur que l'opération d'incrémentation doit d'abord être appliquée `à la valeur pointée par count`, puis seulement après, le résultat sera incrémenté.

Sans les parenthèses, l'expression *count++ serait interprétée différemment en raison de la précédence des opérateurs. Dans cette expression, `++ aurait une priorité plus élevée que *`. Cela signifierait que count serait d'abord incrémenté (c'est-à-dire que l'adresse mémoire pointée par count serait modifiée) avant que la valeur pointée par count ne soit utilisée.

---

INTERMEDIATE

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    sizeof(arr) renvoie la taille totale en octets du tableau arr.
    sizeof(arr[0]) renvoie la taille en octets d'un seul élément du tableau, c'est-à-dire la taille du premier élément de arr.
    En divisant la taille totale du tableau par la taille d'un élément, on obtient le nombre d'éléments dans le tableau.

    On obtient la taille du tableau indépendamment du nombre d'éléments
