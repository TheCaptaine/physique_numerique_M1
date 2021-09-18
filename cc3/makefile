CPPC = g++
CFLAGS = -W -Wall -Wshadow -pedantic -std=c++17
SRCS = fcts.cpp util.cpp methodes.cpp main.cpp
RM = rm -f

OBJS = $(SRCS:.cpp=.o) # fichiers objets

# Complèter la première règle => pour l'exécutable
deriv : main.o fcts.o methodes.o util.o
	$(CPPC) $^ -o $@ # main.o fcts.o methodes.o util.o

# Exemple de règle pour fcts.o
fcts.o : fcts.cpp fcts.h
	$(CPPC) -c $(CFLAGS) fcts.cpp
# ou mieux avec $<, qui désigne la première dépendance
#	$(CPPC) -c $(CFLAGS) $<

# Ecrire ci-dessous les règles pour les autres fichiers sources
main.o : main.cpp fcts.h methodes.h util.h
	$(CPPC) -c $(CFLAGS) main.cpp
methode.o : methodes.cpp methodes.h
	$(CPPC) -c $(CFLAGS) methodes.cpp
util.o : util.cpp util.h
	$(CPPC) -c $(CFLAGS) util.cpp

%.o : %.cpp %.h
	$(CPPC) -c $(CFLAGS) $<

# Exemples de règles pour le ménage
clean :
	$(RM) $(OBJS) 

super_clean :
	$(RM) $(OBJS) a.out
