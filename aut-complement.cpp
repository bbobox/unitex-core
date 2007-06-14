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

#include "utils.h"
#include "autalmot.h"
#include "symbol_op.h"


//
// deprecated
//
/* static symbol_t * LEXIC_minus_transitions_old(transition_t * trans) {

  symbol_t * LEX = symbol_LEXIC_new();
  symbol_t * res = symbol_LEXIC_new();

  while (res && trans) {

    symbol_t * minus = symbol_minus_symbol(LEX, trans->label);
    symbol_t * tmp   = res;

    res = symbols_inter_symbols(tmp, minus);

    symbols_delete(tmp); symbols_delete(minus);
    trans = trans->next;
  }

  symbol_delete(LEX);
  return res;
}*/



static symbol_t * LEXIC_minus_transitions(transition_t * trans) {

  symbol_t * TAB[LANGUAGE->POSs->size];

  int i;
  for (i = 0; i < LANGUAGE->POSs->size; i++) {
    TAB[i] = new_symbol_POS((POS_t *) LANGUAGE->POSs->value[i]);
  }

  while (trans) {

    if (trans->label->type == LEXIC) {
      for (i = 0; i < LANGUAGE->POSs->size; i++) {
	free_symbols(TAB[i]);
      }
      return NULL;
    }

    symbol_t * minus = symbols_minus_symbol(TAB[trans->label->POS->index], trans->label);
    free_symbols(TAB[trans->label->POS->index]);
    TAB[trans->label->POS->index] = minus;

    trans = trans->next;
  }

  symbol_t res;
  res.next = NULL;
  symbol_t * end = & res;

  for (i = 0; i < LANGUAGE->POSs->size; i++) {
    concat_symbols(end, TAB[i], & end);
  }

  return res.next;
}

#define autalmot_complementation2 autalmot_complementation

void autalmot_complementation2(Fst2Automaton * A) {

  int nouvo = autalmot_add_state(A, 0); // dont make it TERMMINAL because flags will be reversed below
  A->states[nouvo].defto = nouvo;

  for (int q = 0; q < A->nbstates; q++) {
    if (autalmot_is_final(A, q)) {
      autalmot_unset_final(A, q);
    } else { autalmot_set_final(A, q); }

    if (A->states[q].defto == -1) {
      symbol_t * s = LEXIC_minus_transitions(A->states[q].trans);
      if (s) {
	add_transition(A, q, s, nouvo);
	free_symbols(s);
	// A->states[q].defto = nouvo;
      }
    }
  }
}


void autalmot_complementation1(Fst2Automaton * A) {

  int nouvo = autalmot_add_state(A, 0); // dont make it TERMMINAL because flags will be reversed below
  A->states[nouvo].defto = nouvo;

  for (int q = 0; q < A->nbstates; q++) {
    if (autalmot_is_final(A, q)) {
      autalmot_unset_final(A, q);
    } else { autalmot_set_final(A, q); }

    if (A->states[q].defto == -1) { A->states[q].defto = nouvo; }
  }
}
