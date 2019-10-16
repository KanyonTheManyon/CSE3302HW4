// Loyd, Kanyon W.
// kwl7925
// 2019-10-15

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken( FILE *fp );

regex_t gp;
regex_t shake;
regex_t orc;

void processToken( char *token )
{
  int result_gp = regexec(&gp, token, 0, NULL, 0);
  int result_shake = regexec(&shake, token, 0, NULL, 0);
  int result_orc = regexec(&orc, token, 0, NULL, 0);

  if (result_gp==0)
    printf(">%s< matches GeePea.\n", token);
  else if (result_shake==0)
    printf(">%s< matches Shake.\n", token);
  else if (result_orc==0)
    printf(">%s< matches Orc.\n", token);
  else
   printf(">%s< does not match.\n", token);
  
}

int main( int argc, char *argv[] )
{
  char g[] = ("^([!?][!?])*((g+gee)|(P+PEA)|[gP]+)$");
  char s[] = ("^(\\([M-W]([M-W][M-W])*[\\|-]$)|(\\|[M-W]([M-W][M-W])*[\\(-]$)|(-[M-W]([M-W][M-W])*[\\|\\(]$)");
  char o[] = ("^&(([a-m]+\\+)|([N-Z]+\\?)|\\*)$");

  int g_result = regcomp(&gp, g, REG_EXTENDED|REG_NOSUB);
  int s_result = regcomp(&shake, s, REG_EXTENDED|REG_NOSUB);
  int o_result = regcomp(&orc, o, REG_EXTENDED|REG_NOSUB);

  // DO NOT CHANGE anything below this line!
  if ( argc > 1 ) {
    printf( "processing tokens from %s ...\n", argv[1] );

    FILE *fp = fopen( argv[1], "r" );
    char *token = NULL;

    if ( fp != NULL ) {
      while ( token = getToken( fp ) ) {
        processToken( token );
        free( token );
      }

      fclose( fp );
    } else {
      printf( "unable to open %s?\n", argv[1] );
    }
  } else {
    printf( "No input file specified.\n" );
  }
}

#define MAX_TOKEN_SIZE (1024)

char *getToken( FILE *fp )
{
  char token[ MAX_TOKEN_SIZE+1 ];
  int  i  = 0;

  while ( i < MAX_TOKEN_SIZE ) {
    int ch = fgetc( fp );

    if ( ch == EOF ) { break; }

    if ( isspace( ch ) ) {
      if ( i == 0 ) { continue; }
      break;
    }

    token[ i++ ] = ch;
  }

  if ( i == 0 ) { return NULL; }

  token[ i ] = '\0';

  return strdup( token );
}
