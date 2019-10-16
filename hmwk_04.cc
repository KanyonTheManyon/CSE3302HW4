// Loyd, Kanyon W
// kwl7925
// 2019-10-15

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

void processToken( string token )
{
  regex gp("^([!?][!?])*((g+gee)|(P+PEA)|[gp]+)$");
  regex shake("^(\([M-W]([M-W][M-W])*[\|-]$)|(\|[M-W]([M-W][M-W])*[\(-]$)|(-[M-W]([M-W][M-W])*[\|\(]$)");
  regex orc("^&(([a-m]+\+)|([N-Z]+\?)|\*)$ ")

  if (regex_match(token, gp))
    cout << ">" << token << "< matches GeePea." << endl;
  else if (regex_match(token, shake))
    cout << ">" << token << "< matches Shake." << endl;
  else if (regex_match(token, orc))
    cout << ">" << token << "< matches Orc." << endl;
  else
     cout << ">" << token << "< does not match." << endl;
}

int main( int argc, char *argv[] )
{
  if ( argc > 1 ) {
    cout << "processing tokens from " << argv[ 1 ] << " ...\n";

    ifstream inputFile;
    string   token;

    inputFile.open( argv[ 1 ] );

    if ( inputFile.is_open() ) {
      while ( inputFile >> token ) {
        processToken( token );
      }
      inputFile.close();
    } else {
      cout << "unable to open " << argv[ 1 ] << "?\n";
    }
  } else {
    cout << "No input file specified.\n";
  }
}
