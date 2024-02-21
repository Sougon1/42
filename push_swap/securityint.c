
#include "ps.h"

// // Fonction pour vérifier les doublons dans la liste chaînée
// int hasDuplicates(stack *myStack) {
//     t_list* current = myStack->top;

//     // Créer une liste chaînée temporaire pour stocker les valeurs rencontrées
//     stack tempStack;
//     tempStack.top = NULL;

//     // Parcourir la liste chaînée
//     while (current != NULL) {
//         int value = current->value;

//         // Vérifier si la valeur est déjà présente dans la liste temporaire
//         t_list* tempCurrent = tempStack.top;
//         while (tempCurrent != NULL)
//         {
//             if (tempCurrent->value == value) {
//                 ft_printf("Error\n"); // Un doublon a été trouvé
//                 exit(EXIT_FAILURE); 
//             }
//             tempCurrent = tempCurrent->next;
//         }

//         // Ajouter la valeur à la liste temporaire
//      //   pushtab(&tempStack, value);

//         // Passer à l'élément suivant dans la liste
//         current = current->next;
//     }

//     return 0; // Aucun doublon n'a été trouvé
// }


// int duplicate(char *argv)
// {

// }

int securityint(char *argv)
{
    long long   i;

    i = ft_atoll(argv);
    if (i >= INT_MAX || i <= INT_MIN)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return (i);
}
