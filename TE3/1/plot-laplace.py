import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d, Axes3D # pour la 3D
#
#------ PARAMETRES a EDITER -------------------------#
fichier= "laplace-condlimt1-ldt.dat" # nom du fichier de donnees (ayant 1 ligne d'en-tete)
niso   = 50            # nombre de courbes de niveaux a tracer
#
# Angles de vue du graphique 3D :
Altitud= 35            # elevation
Azimuth=-50            # rotation
#
# Table de couleurs : ( .jet .coolwarm .Spectral .CMRmap ...)
ColorMap = plt.cm.Spectral          # pour le plot 3D
#----------------------------------------------------#
#
# Lecture de la ligne d'entete : nl, nc, pas

# lecture de la ligne d'entete : nl+2 , nc+2 , pas
try:
    fp=open(fichier,"r")
except:
    print( " Erreur d'ouverture du fichier '%s' ."%fichier)
    exit(1)
params = fp.readline().strip().replace("#","").split()
fp.close()

try:
    nlig= int( params[0] )
    ncol= int( params[1] )
    pas = float(params[2])
except:
    print (" ! La ligne d'en-tete n'est pas au format attendu (nl nc pas) : ",params)
    pas=None
nl = nlig - 2
nc = ncol -2

# lecture des donnees : apres la 1ere ligne
data = np.loadtxt( fichier, skiprows=1)
if pas == None :
    nl = data.shape[0]-2
    nc = data.shape[1]-2
    pas  = 1.
print (" Nl=%d , Nc=%d, pas=%g"%(nl,nc,pas))

# Creation des axes X et Y (bords inclus):
x = np.linspace(0,nl+1, nl+2)*pas
y = np.linspace(0,nc+1, nc+2)*pas

# creation des matrices de X et Y en tous points :
Y, X = np.meshgrid(y, x)

# Affichage en contours :
plt.figure( figsize=(11.69,8.27) ) # format A4 paysage
ax = plt.gca()
ax.invert_yaxis()
contours = plt.contour(Y, X, data, niso, cmap= plt.cm.jet )
# libelles des isothermes (1 chiffre apres la virgule)
plt.clabel(contours, inline=1, fmt="%.1f", fontsize=10)
plt.xlabel("Y")
plt.ylabel("X")
plt.title("Temperature %dx%d"%(nl,nc) )
fig = plt.gcf()
fig.savefig("laplace_%dx%d.pdf"%(nl,nc), format="pdf")
print( " Le graphique 'laplace_%dx%d.pdf' a ete cree."%(nl,nc) )

# affichage 3D :
fig3D= plt.figure( figsize=(11.69,8.27) )
try:
    ax3d = Axes3D( fig3D ) # ax3d = plt.axes(projection='3d')
except:
    print( " Erreur ouverture Graphique 3D" )
    print ("\n Fermer la figure pour terminer.\n")
else:
    ax3d.invert_yaxis()
    ax3d.view_init( Altitud, Azimuth )
    ax3d.plot_surface(Y, X, data, cmap=ColorMap,
                      rstride=1,cstride=1,linewidth=0.2)
    ax3d.set_xlabel("Y")
    ax3d.set_ylabel("X")
    ax3d.set_zlabel("Temperature")
    fig = plt.gcf()
    fig.savefig("laplace3D_%dx%d.pdf"%(nl,nc), format="pdf")
    print( " Le graphique 'laplace3D_%dx%d.pdf' a ete cree."%(nl,nc) )
    print ("\n Fermer les 2 figures pour terminer.\n")
#
plt.pause(5)
plt.show()
