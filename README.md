# Fiche de trucs à faire et à défaire pour le projet LDP 2.
- [ X ] MAIN <br />
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

- [ ] Les lanes sont inversées <br/>
Lors de l'affichage des objets sur le plateau, mettre une lane plus grande qu'une autre fait que l'on a les objets affichés dans l'ordre inverse que ce que l'on voudrait

- [X] TurtleView <br/>
Il manque une classe view pour turtle

- [ ] LANES dans l'initialisation <br/>
Ce serait bien qu'on initialise directment avec des lanes quand même :sob:, dans l'état actuel, 
on initialise à chaque fois de manière brute.
#### C'est en cours de route!!! 
Beaucoup de classes View ont été rajoutées dans  laneview.hpp, 
il reste à écrire des initialiseurs corrects pour la plupart de ces classes, puis on fera tourner le code
- ~~[ ] WaterLanes en bleu~~ <br/>
~~Oui stp :pleading_face:~~
On va plutôt colorer les classes filles de WaterLanes en bleu, colorer waterlanes directement s'annonce plus coton pour l'instant
- [ ] Gérer les collisions <br/>
Il faudrait au moins que ça affiche "poc" dans le terminal quand la grenouille touche un truc

- [ ] Faire revenir les objets sur le plateau et initialiser par paquet <br/>
Actuellement le plateau est plutôt vide de voitures etc, j'aimerai bien qu'il soit plus vivant
donc rajoutons des voitures par paquets et tout, ce serait cool!
