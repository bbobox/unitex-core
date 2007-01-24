 /*
  * Unitex
  *
  * Copyright (C) 2001-2007 Universit� de Marne-la-Vall�e <unitex@univ-mlv.fr>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
  * License as published by the Free Software Foundation; either
  * version 2.1 of the License, or (at your option) any later version.
  *
  * This library is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  * Lesser General Public License for more details.
  * 
  * You should have received a copy of the GNU Lesser General Public
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
  *
  */

/*************************************************************************\
*                                 emonde.h                          v0.01 *
*                                                                         *
*   EmondeAutomate        : emonde l'automate passe en parametre et       *
*                           renvoie 1 si tout c'est bien passe, 0 sinon   *
*                      (c) 1997 S. SAUPIQUE - MagiX                       *
\*************************************************************************/
void verifVide(tAutAlMot * a) ;
int EmondeAutomate(tAutAlMot * a, BOOL puits) ;
int MAJEtatsEntrants(tAutAlMot * a) ;
/* faire une structure pour les etats utiles et inutiles */
/* faire une fonction qui remplit cette structure */
/* appeler cette fonction depuis emonde */
