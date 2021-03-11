# ProjectUnreal

exo :

-deplacement souris et/ou clavier
-animation idle / course / Competence 
-HUD point de vie
-système compétence au moins 3 (une corps a corp/une distance/ et une au choix )

IA
-deplacement pathfinding
-animation idle / course / attack
-point de vie sur HUD
-system compétence
-utilisation behavior tree simuler une IA
	->en attente par default
	->si joueur entre dans champ de vision(AI perception Component)
	->elle ce dirige vers le joueur 
	->attack si elle et a portée
	->si le perd de vue va a la derniére position connue du joueur 
	->attend 2 seconde et retourne a sa position initial
	
	
-system combat fonctionnel
	->competences infligent des degats aux cible
	->si IA meurt feed back visuelle
	
-un niveaux jouable avec des obstacles pour testé les champs de vision

PARTIE LIBRE:
ajout de ce que l'on veut.


Contrôle Du personnage :

->Deplacement uniquement sourie clic droit clic gauche

->competences :
	(sur target)
	-> clic Gauche attack monocible
	->clic droit attack zone 
	-> "A" boule de feux dans la direction du curseur
	-> "z" invocation(une IA allié)
	->"Action loot" clic droit

IA allié :
	->cible : si le joueur passe la sourie sur un ennemi
	->attack de base comme pour les IA ennemi
	


PARTIE LIBRE:
-sytem de generation de loot aleatoire 

-inventaire style diablo(drag n drop) (clic gauche pour swith inventaire equipement)
	->avec drop de l'item
	
-system de stat basique (n'influe pas sur le gameplay)

-highLihting (via mesh et non post process)


PS: 
ceci et un projet pour implementer certaines features et non créé une boucle de gameplay 
il n'y a pas de mort du joueur il peut perdre des pv mais pas mourir.

pour ma part je me suis bien amuser et cherché c'est un micro projet interessant.