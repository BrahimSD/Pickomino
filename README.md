# Pickomino
Règles du jeu
Les règles du jeu sont disponibles ici.

Le jeu est composé de :

16 pickominos
8 dés
Pickominos
Les Pickominos ont une valeur et un nombre de point. Les Pickominos sont les suivant (la valeur en haut, le nombre de points en bas) :
```
┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐┌──┐
│21││22││23││24││25││26││27││28││29││30││31││32││33││34││35││36│
├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤├──┤
│ 1││ 1││ 1││ 1││ 2││ 2││ 2││ 2││ 3││ 3││ 3││ 3││ 4││ 4││ 4││ 4│
└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘└──┘
```
Les valeurs sont le total des dés qu'il faut effectuer pour récupérer le Pickomino.
Chaque joueur a une pile de Pickominos devant lui. Au début de la partie les piles des joueurs sont vides et les pickominos sont placés faces visibles au milieu de la table.

Lors de la partie quand un joueur récupère un Pickomino, il l'empile sur sa pile de Pickominos, ainsi seul le dernier Pickomino récupéré est visible.

Dés
Les dés sont des dés à 6 faces, avec les faces de 1 à 5 et une face spéciale 'V' (de valeur 5).

Un tour de jeu
À son tour de jeu, un joueur lance autant de fois les dés tant qu'il le souhaite et qu'il peut mettre de côté au moins un dé de valeur différente à ceux déjà conservés.

1er Exemple
1er lancer des 8 dés : 
[1] [5] [V] [1] [4] [2] [V] [V]
Le joueur décide de garder les dés affichant la valeur V, il met donc ces 3 dés de côté et décide si oui ou non il souhaite relancer les dés.
Il choisit de relancer les dés.
2ème lancer des 5 dés restants : 
[4] [5] [V] [4] [V]
Le joueur ne peut pas garder les dés affichant la valeur V car il a déjà gardé cette valeur au lancer précédent.
Il décide de garder les dés affichant la valeur 4, il met donc ces 2 dés de côté et décide si oui ou non il souhaite relancer les dés.
Il choisit de relancer les dés.
3ème lancer des 3 dés restants : 
[1] [5] [3]
Le joueur décide de garder le dé affichant la valeur 5, il met donc ce dé de côté et décide si oui ou non il souhaite relancer les dés.
Il choisit de s'arrêter.
Le joueur a donc gardé 3 dés de valeur V (au 1er lancer), 2 dés de valeur 4 (au 2ème lancer) et un dé de valeur 5 (au 3ème lancer).
Il a donc une valeur totale de 3×V+2×4+1×5=3×5+2×4+1×5=15+8+5=28
.

2ème Exemple
1er lancer des 8 dés : 
[2] [5] [V] [2] [4] [2] [5] [V]
Le joueur décide de garder les dés affichant la valeur V, il met donc ces 2 dés de côté et décide si oui ou non il souhaite relancer les dés.
Il choisit de relancer les dés.
2ème lancer des 6 dés restants : 
[3] [5] [V] [1] [V] [5]
Le joueur ne peut pas garder les dés affichant la valeur V car il a déjà gardé cette valeur au lancer précédent.
Il décide de garder les dés affichant la valeur 5, il met donc ces 2 dés de côté et décide si oui ou non il souhaite relancer les dés.
Il choisit de relancer les dés.
3ème lancer des 4 dés restants : 
[V] [5] [V] [V]
Le joueur ne peut pas garder les dés affichant la valeur V car il a déjà gardé cette valeur au 1er lancer. Il ne peut pas non plus garder les dés affichant la valeur 5 car il a déjà gardé cette valeur au 2ème lancer.
Le tour de jeu de ce joueur est donc un tour raté.

Tour raté
Un tour est dit raté dans les 3 cas suivants :

Le joueur ne peut pas mettre des dés de côté (comme dans le 2ème exemple) ;
Le joueur n'a pas mis de dés avec la valeur V de côté ;
La valeur totale des dés du joueur est inférieure à la plus petite valeur des Pickominos visibles.
Si le tour est raté, alors le joueur doit rendre un Pickomino. Il remet au centre de la table le Pickomino au sommet de sa pile. De plus, il doit retourner le Pickomino de plus grande valeur parmi ceux au centre de la table, sauf si c'est celui qu'il vient de remettre à l'instant.

Récupérer un Pickomino
Pour récupérer un Pickomino, il faut que parmi les dés conservés lors des lancers il y ait au moins un dé avec la valeur V, comme dans le 1er Exemple. Prenons le 1er Exemple, le joueur avait obtenu une valeur totale de 28.

Si le Pickomino 28 est visible au centre de la table, le joueur le récupère et le place au sommet de sa pile
Sinon si le Pickomino 28 est au sommet de la pile d'un autre joueur, le joueur le récupère et le place au sommet de sa pile
Sinon si il existe un Pickomino de valeur inférieure à 28 au centre de la table, le joueur récupère le Pickomino de plus grande valeur inférieure à 28 et le place au sommet de sa pile
Bien que le joueur ait eu un V parmis ses dés conservés s'il n'a pas pu récupérer de dés alors son tour est raté (il doit donc rendre un Pickomino et potentiellement en retourner un autre).

Fin de partie
Quand il n'y a plus de Pickominos face visible au centre de la table la partie est finie. On compte le nombre de points de chacun des joueurs, comme la somme des points (nombre du bas) des Pickominos de sa pile.
Le gagnant est le joueur avec le plus grand nombre de points.
