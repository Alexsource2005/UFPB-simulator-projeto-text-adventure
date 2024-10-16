#include <stdbool.h>

extern int fome, energia, sanidade, necessidade_banheiro;

extern bool exec_eat();
extern bool exec_sleep();
extern bool exec_banheiro(void);
extern void setLocation();
extern bool checkStatus();

extern bool loseEnergia(int howMuch);
extern bool loseFome(int howMuch);
extern bool loseBanheiro(int howMuch);
extern void addSanidade(int sanidadeValue);
extern void loseSanidade(int howMuch);
