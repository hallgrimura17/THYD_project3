#include <iostream>
#include <fstream>
#include <iomanip>
#include "language.h"
#include "bparser.h"
#include "ast.h"
#include "print_visitor.h"
#include "sa_visitor.h"
#include "icg_bc_visitor.h"

using namespace AST;

using namespace std;
int main( int argc, char* argv[] ) {

  Language::init();

  // Process the command-line arguments, if any.
  // Usage: program [ option [ filename ] ]  (option -h or -b)
  bool use_bison = true;
  if (argc >= 2 && string(argv[1]) == "-h") {
    use_bison = false;
  }
  string filename("test/test.pas");
  if (argc >= 3) {
    filename = argv[2];
  }

  // Open file with Pascal program, exit if error opening file.
  ifstream ifs(filename);
  if (!ifs) {
    cerr << "Could not open input file '" << filename << "'." << endl;
    return -1;
  }

  // Instantiate the right parser.
  Parser *parser;
  if (use_bison) {
    parser = new BParser( ifs, false, false); // Change flags to true for debugging.
  } else {
    cout << "Bison parser only supported." << endl;
    exit(1);
  }

  // Parse and do semantic check on the resulting AST.
  cout << "====> PARSING FILE " << filename
       << " USING PARSER " << parser->get_name() << endl;
  parser->parse();
  ProgramNode *ast = parser->get_AST();
  if (ast != nullptr) {
    //PrintVisitor pvisitor(cout);
    //ast->accept(pvisitor);
    SemanticAnalysisVisitor savisitor(parser->get_SymbolTable());
    ast->accept(savisitor);
  }
  /*
  cout << "====> SymbolTable" << endl;
  SymbolTable* st = parser->get_SymbolTable();
  for ( auto entry : st->get() ) {
    cout << entry.first << ' ' << entry.second.str() << endl;
  }
  */

  if (ast != nullptr) {
    std::string filename_out = ast->get_name() + ".j";
    cout << "====> outputting BC file '" << filename_out << "'" << endl;
    ICG_BC_Visitor icg_visitor( parser->get_SymbolTable() );
    ast->accept(icg_visitor);
    ofstream jfile;
    jfile.open ( filename_out );
    icg_visitor.output( jfile );
    jfile.close();
  }

  // Clean up and return.
  delete parser;
  return 0;
}