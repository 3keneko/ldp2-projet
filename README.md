# Fiche de trucs à faire et à défaire pour le projet LDP 2.
- [X] MAIN <br />
Le code suivant dans le main.cpp est horrible, il devrait être changé

```cpp
  std::cout << "1" << std::endl;
  std::srand(static_cast<unsigned>(time(nullptr)));
  Frog frog { 1, 10 };
  auto frg_ptr = std::make_shared<Frog>(frog);
  auto fv = std::make_shared<FrogView>(frg_ptr);
  auto c = std::make_shared<Car>(1, 40, 40, 7);
  auto d = std::make_shared<Car>(-1, 500, 40, 8);
  auto e = std::make_shared<Log>(2, 20, 100, 9);
  std::vector<std::shared_ptr<MovingObject>> cs { c, d, e };
  auto b = std::make_shared<BoardModel>(cs);
  auto cv = std::make_shared<CarView>(c);
  auto dv = std::make_shared<CarView>(d);
  auto lv = std::make_shared<LogView>(e);
  std::vector<std::shared_ptr<MovingObjectView>> cars { cv, dv, lv };
  auto bv = std::make_shared<BoardView>(cars, b);
  auto ml = std::make_unique<MainLoop>(b, bv, fv, frg_ptr);
  MainWindow window(std::move(ml));
  window.show(argc, argv);
  return Fl::run();
```
#### Choses qui pourraient marcher
- Une factory class ?
- Être plus intelligent lors de l'initialisation ?
- Une classe d'initialisation ?

- [x] Les lanes sont inversées <br/>
Lors de l'affichage des objets sur le plateau, mettre une lane plus grande qu'une autre fait que l'on a les objets affichés dans l'ordre inverse que ce que l'on voudrait
ça aussi c'est fait!

- [X] TurtleView <br/>
Il manque une classe view pour turtle

- [x] LANES dans l'initialisation <br/>
Ce serait bien qu'on initialise directment avec des lanes quand même :sob:, dans l'état actuel, 
on initialise à chaque fois de manière brute.

- [X] Le contrôle de la grenouille est bugué <br/>
Parfois, la grenouille avec de 2 ou 3 cases au lieu d'une.

- [x] Gérer la mort <br/>
Parce que c'est important de mourir

- [x] Faire avancer la grenouille quand elle est sur une buche <br/>
Je pensais à faire avancer la grenouille case par case dans le modèle de manière à ce que ce soit un minimum coordonné avec les buches.
Il est important qu'on ne puisse pas sauter entre deux cases. 

#### C'est en cours de route!!! 
Beaucoup de classes View ont été rajoutées dans  laneview.hpp, 
il reste à écrire des initialiseurs corrects pour la plupart de ces classes, puis on fera tourner le code
DONE!!!! 

- ~~[ ] WaterLanes en bleu~~ <br/>
~~Oui stp :pleading_face:~~
On va plutôt colorer les classes filles de WaterLanes en bleu, colorer waterlanes directement s'annonce plus coton pour l'instant

- [x] Définir les objets de finnishLane <br/>
D'accord définir de nouveaux objets imobiles (finnishCase?) et puis le mettre dans finnishLane
Définir des collisions avec ces objets
Définir des collisions avec toute la lane sauf ces objets (la mort quoi)
--- Pas vraiment nécessaire pour le moment, lit le pdf.

- [x] Gérer les collisions <br/>
Il faudrait au moins que ça affiche "poc" dans le terminal quand la grenouille touche un truc
Pour les collisions avec les voitures dans le programme, il y a un décalage avec les collisions
Gérer les collisions mortelles dans les WaterLanes
Gérer les collisions avec les Logs (pour faire bouger la grenouille avec la log)

- [x] Faire revenir les objets sur le plateau et initialiser par paquet <br/>
Actuellement le plateau est plutôt vide de voitures etc, j'aimerai bien qu'il soit plus vivant
donc rajoutons des voitures par paquets et tout, ce serait cool!
AMAZING

- [X] Rendre l'arrivée des objets sur le plateau plus smooth
Actuellement, l'arrivée des objets sur le plateau se fait de manière beaucoup trop clunky, ce serait bien qu'ils rentrent sur le plateau de manière beaucoup plus smooth

- [x] Faire un plateau à 13 lanes
Dans le pdf, il demande de faire un plateau à 13 lanes, on devrait entre autre augmenter la taille des lanes et de chaque frog.

- [x] Faire en sorte que les turtles se jettent sous l'eau de temps en temps
Les méthodes sont là, il y a plus qu'à combiner le tout
--- Occupé et bientôt fini !

- [X] Afficher le nombre de vies
Actuellement, la grenouille marche avec un système de vie, il faudrait l'afficher en haut à gauche si possible

- [X] Message de victoire
Actuellement, on a juste une image de victoire, un message de victoire fait partie des conditions de base pour réussir de la partie

- [X] Changer le design de la grenouille, pour qu'il puisse être orientable
On utilisera `enum class` pour avoir les différentes possibilités d'orientation de la grenouille,
la syntaxe (plutôt cool) est ainsi:

- [x] Changer les collisions des frogs
Actuellement, on peut être au bord de la frog sans tomber dans l'eau. Il suffit de faire la même implémentation de collide que pour les logs.

- [x] Rendre les niveaux un peu plus faciles quand même ...
Juste modifier un peu les fichiers .csv

``` cpp
enum class Directions {
  North,
  South,
  East,
  West
}
```

- [x] Ajouter le score et l'afficher en bas à droite
- [x] Le terminal est trop bruyant en jeu, retirer les cout incessants
- [x] S'assurer qu'on puisse écrire un score dans une file 
- [ ] Ajouter la possibilité d'accéder au menu chargé des niveaux et du score.
- [x] Save the score ~~(idée actuelle: mettre une ligne tout en bas des files levels qui met le score principal)~~ ~~remplacé par le très efficace "une file par score"~~ remplacé par le plus efficeace une file avec tous les scores dedans
- [ ] Ajouter le menu pour sélectionner les niveaux et le score :thumsbup:
We got this! -- C'est en cours
- [ ] Idées pour faire un éditeur de niveau facile
1. N'autoriser que l'édition de niveaux, pas la création
2. Quand on edit, on ne fait que rajouter une ligne à la file


#### Fichiers mis au propre
- main.hpp
- mainwindow.hpp (et .cpp)
- constants.hpp
- boardmodel.hpp (et .cpp)
- lanes.hpp (et .cpp)
- movingobjects.hpp (et .cpp)
- frog.hpp (et .cpp)
- control.hpp (et .cpp)
- movingobjectview.hpp (et .cpp)
- laneview.hpp (et .cpp)
- boardview.hpp (et .cpp)
- gameloop.hpp (et .cpp)
- waterlilies.hpp (et .cpp)
- image_classes.hpp (et .cpp) 
- frogview.hpp (et .cpp)
