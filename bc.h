#ifndef TURBOPASCAL_BC_H
#define TURBOPASCAL_BC_H

#include <string>
#include <list>
#include <map>

class BC {
 public:

  enum class InstrCode {
    // Load and store instructions.
    aload,
    astore,
    fload,
    fstore,
    faload,
    fastore,
    iload,
    istore,
    iaload,
    iastore,
    baload,
    bastore,
    getstatic,
    putstatic,
    // Operations
    iadd,
    idiv,
    imul,
    isub,
    ineg,
    fadd,
    fdiv,
    fmul,
    fsub,
    fneg,
    // Jumping instructions
    ifeq,
    ifne,
    ifgt,
    ifge,
    iflt,
    ifle,
    if_icmpeq,
    if_icmpne,
    if_icmpgt,
    if_icmpge,
    if_icmplt,
    if_icmple,
    _goto,
    // Methods calls and return statements.
    invokestatic,
    invokespecial,
    invokevirtual,
    _return,
    ireturn,
    freturn,
    // Various
    fcmpl,
    newarray,
    i2f,
    ldc,
    nop
  };

  static std::string instr_code_to_name( InstrCode instr_code ) {
    static const std::map<InstrCode,std::string> InstrCodeNames = {
        { InstrCode::iload, "iload" },
        { InstrCode::fload, "fload" },
        { InstrCode::aload, "aload" },
        { InstrCode::iaload, "iaload" },
        { InstrCode::faload, "faload" },
        { InstrCode::baload, "baload" },
        { InstrCode::istore, "istore" },
        { InstrCode::fstore, "fstore" },
        { InstrCode::astore, "astore" },
        { InstrCode::iastore, "iastore" },
        { InstrCode::fastore, "fastore" },
        { InstrCode::bastore, "bastore" },
        { InstrCode::invokespecial, "invokespecial" },
        { InstrCode::invokestatic, "invokestatic" },
        { InstrCode::invokevirtual, "invokevirtual" },
        { InstrCode::getstatic, "getstatic" },
        { InstrCode::putstatic, "putstatic" },
        { InstrCode::_return, "return" },
        { InstrCode::ireturn, "ireturn" },
        { InstrCode::freturn, "freturn" },
        { InstrCode::ldc, "ldc" },
        { InstrCode::ifeq, "ifeq" },
        { InstrCode::ifne, "ifne" },
        { InstrCode::ifgt, "ifgt" },
        { InstrCode::ifge, "ifge" },
        { InstrCode::iflt, "iflt" },
        { InstrCode::ifle, "ifle" },
        { InstrCode::if_icmpeq, "if_icmpeq" },
        { InstrCode::if_icmpne, "if_icmpne" },
        { InstrCode::if_icmpgt, "if_icmpgt" },
        { InstrCode::if_icmpge, "if_icmpge" },
        { InstrCode::if_icmplt, "if_icmplt" },
        { InstrCode::if_icmple, "if_icmple" },
        { InstrCode::_goto, "goto" },
        { InstrCode::fcmpl, "fcmpl" },
        { InstrCode::newarray, "newarray" },
        { InstrCode::i2f, "i2f" },
        { InstrCode::nop, "nop" },
        { InstrCode::iadd, "iadd" },
        { InstrCode::isub, "isub" },
        { InstrCode::idiv, "idiv" },
        { InstrCode::imul, "imul" },
        { InstrCode::ineg, "ineg" },
        { InstrCode::fadd, "fadd" },
        { InstrCode::fsub, "fsub" },
        { InstrCode::fdiv, "fdiv" },
        { InstrCode::fmul, "fmul" },
        { InstrCode::fneg, "fneg" }
    };
    auto it = InstrCodeNames.find( instr_code );
    if ( it != InstrCodeNames.end() )
      return it->second;
    return "unknown_instr_code";
  }

  class Label {
   public:
    Label ( ) : Label(-1) {}
    explicit Label( int num ) : num_(num) {}
    int get_num() const { return num_; }
    std::string to_string() const { return "L" + std::to_string(num_); }
   private:
    int num_;
  };

  class Instr {
   public:

    explicit Instr( const InstrCode& instr_code ) : instr_code_(instr_code) { }

    Instr( const InstrCode& instr_code, Label label ) : instr_code_(instr_code), label_(label) { }

    Instr( const InstrCode& instr_code, const std::list<std::string>& args, Label label = Label() ) :
        instr_code_(instr_code), args_(args), label_(label) { }

    std::string to_string() const {
      std::stringstream ss;
      if ( label_.get_num() >= 0 ) {
        ss << label_.to_string() << ":\t";
      }
      ss << instr_code_to_name( instr_code_ );

      for ( auto& a : args_ ) {
        ss << '\t' << a;
      }
      return ss.str();
    }

   private:
    InstrCode instr_code_;
    std::list<std::string> args_;
    Label label_;
  };

};

#endif //TURBOPASCAL_BC_H
