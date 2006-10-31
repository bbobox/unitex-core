 /*
  * Unitex
  *
  * Copyright (C) 2001-2006 Universit� de Marne-la-Vall�e <unitex@univ-mlv.fr>
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

//---------------------------------------------------------------------------
#ifndef Fst2_tags_optimizationH
#define Fst2_tags_optimizationH
//---------------------------------------------------------------------------

#include "Alphabet.h"
#include "String_hash.h"
#include "Fst2.h"
#include "CompoundWordTree.h"
#include "List_int.h"


void replace_pattern_tags(Fst2*,Alphabet*,struct string_hash*,
						struct DLC_tree_info*,int,struct list_int*,
                  struct lemma_node*);


#endif
