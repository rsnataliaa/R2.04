# Cible par défaut du Makefile
all:
	# Commande pour compiler le programme.
	gcc -o analyser main.c extract_fields.c decode.c display.c
