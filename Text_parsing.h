 /*
  * Unitex
  *
  * Copyright (C) 2001-2010 Universit� Paris-Est Marne-la-Vall�e <unitex@univ-mlv.fr>
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

#ifndef Text_parsingH
#define Text_parsingH

#include "LocateMatches.h"
#include "Fst2.h"
#include "TransductionStack.h"
#include "String_hash.h"
#include "ParsingInfo.h"
#include "LocateConstants.h"
#include "CompoundWordTree.h"
#include "LocatePattern.h"
#include "MorphologicalFilters.h"


#define STACK_MAX 1000 /* The maximal size of recursive calls of the
                          function parcourir_opt =~ the maximal number
                          of tokens to be recognized in one match */

#define MAX_MATCHES_AT_TOKEN_POS 400 /* The maximal number of matches
                                        starting from one token : this
                                        value is critical in the case
                                        of bad designed grammars */

/* Arbitrary value used as a limit. It is similar to 'MAX_MATCHES_AT_TOKEN_POS',
 * but it concerns each subgraph. */
#define MAX_MATCHES_PER_SUBGRAPH 50

#define MAX_ERRORS 50  /* Maximal number of errors before exiting:
                          needed to avoid overflow of error buffers in Java GUI */


/* we try to known if user request cancel each COUNT_CANCEL_TRYING_INIT_CONST locate */
#define COUNT_CANCEL_TRYING_INIT_CONST (1024)

struct Token_error_ctx {
int n_errors;
int last_start;
int last_length;
int n_matches_at_token_pos__locate;
int n_matches_at_token_pos__morphological_locate;
};

void error_at_token_pos(const char* message,int start,int length,struct locate_parameters* p,struct Token_error_ctx*);
void launch_locate(U_FILE*,long int,U_FILE*,struct locate_parameters*,Abstract_allocator);
void locate(int,OptimizedFst2State,int,int,struct parsing_info**,int,struct list_int*,struct locate_parameters*,struct Token_error_ctx*,variable_backup_memory_reserve*,int*,int*, Abstract_allocator);
int XOR(int a,int b);

#endif


